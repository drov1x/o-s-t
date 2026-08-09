import torch
import torchvision
from torch.utils import data
from torchvision import transforms
from d2l import torch as d2l
from IPython import display

d2l.use_svg_display()

trans = transforms.ToTensor()       # 设置转换器：把图片转换为张量
mnist_train = torchvision.datasets.FashionMNIST(
    root="../data", train=True, transform=trans, download=True)
mnist_test = torchvision.datasets.FashionMNIST(
    root="../data", train=False, transform=trans, download=True)

print(f'len_train {len(mnist_train)}, len_test {len(mnist_test)}')
print(f'shape {mnist_test[0][0].shape}')
# 三维张量，分别代表通道（灰度图像只有一个）、长、宽

def get_fm_labels(labels):
    text_labels = ['t-shirt', 'trouser', 'pullover', 'dress', 'coat',
                   'sandal', 'shirt', 'sneaker', 'bag', 'ankle boot']

    return [text_labels[int(i)] for i in labels]    # 兼容各种输入

def show_images(imgs, num_rows, num_cols, titles=None, scale=1.5):
    figsize = (num_cols * scale, num_rows * scale)
    _, axes = d2l.plt.subplots(num_rows, num_cols, figsize=figsize)
    axes = axes.flatten()
    for i, (ax, img) in enumerate(zip(axes, imgs)):
        if torch.is_tensor(img):
            ax.imshow(img.numpy())
        else:
            ax.imshow(img)
        ax.axes.get_xaxis().set_visible(False)
        ax.axes.get_yaxis().set_visible(False)
        if titles:
            ax.set_title(titles[i])

X, y = next(iter(data.DataLoader(mnist_train, batch_size=10)))
show_images(X.reshape(10, 28, 28), 1, 10, titles=get_fm_labels(y))

batch_size = 256

train_iter = data.DataLoader(mnist_train, batch_size, shuffle=True, num_workers=0)
# 最后一个参数是用来规定读取数据的线程数的

timer = d2l.Timer()
for X, y in train_iter: # 每次从迭代器随机取batch_size个样本给X、y，
                        # 且多次循环遍历完样本集，不重不漏
    continue
print(f'{timer.stop():.2f} s.')

batch_size = 256
# train_iter已经在前文手动自定义，test_iter使用d2l自带的迭代器定义
_, test_iter = d2l.load_data_fashion_mnist(batch_size)

num_inputs = 28 * 28
num_outputs = 10

W = torch.normal(0, 0.01, size=(num_inputs, num_outputs), requires_grad=True)
b = torch.zeros(num_outputs, requires_grad=True)

def softmax_f(X):
    X_e = torch.exp(X)
    partition = X_e.sum(1, keepdim=True)
    return X_e / partition 

def softmax(X):
    X = X - X.max(1, keepdim=True).values
    X_e = torch.exp(X)
    partition = X_e.sum(1, keepdim=True)
    return X_e / partition 

def net(X):
    return softmax(torch.matmul(X.reshape((-1, W.shape[0])), W) + b)

def cross_entropy(y_hat, y):
    return -torch.log(y_hat[range(len(y_hat)), y])

def accuracy(y_hat, y):
    '''这个函数负责针对某批样本输出有效样本数'''
    if len(y_hat.shape) > 1 and y_hat.shape[1] > 1: # 确定是一个有效维度大于2的张量
        y_hat = y_hat.argmax(axis=1)                # y_hat未取argmax，取一下确定分类情况           
    cmp = y_hat.type(y.dtype) == y                  # 逐个比较样本，获取整个样本集的比较情况（一个bool向量）
    return float(cmp.type(y.dtype).sum())           # 返回最终的有效样本数量，float可以确保最后算比值的时候不会出问题
# 最终比值为 acc = accuracy(y_hat, y) / len(y)

def evaluate_accuracy(net, data_iter):
    '''获得模型对象和数据集，直接评测总体合格率'''
    if isinstance(net, torch.nn.Module):
        net.eval()
    metric = Accumulator(2)
    with torch.no_grad():
        for X, y in data_iter:
            metric.add(accuracy(net(X), y), y.numel())
    return metric[0] / metric[1]

class Accumulator:  #@save
    """计数器类"""
    def __init__(self, n):
        self.data = [0.0] * n
    def add(self, *args):
        self.data = [a + float(b) for a, b in zip(self.data, args)]
    def reset(self):
        self.data = [0.0] * len(self.data)
    def __getitem__(self, idx):
        return self.data[idx]

def train_epoch_ch3(net, train_iter, loss, updater):             # 参数解释，四个参数分别为模型、训练数据集、损失函数对象、模型更新函数
    '''
    这个函数已经内置在d2l包里了。
    另，这个函数是根据模型和优化
    函数来确定是否使用框架的。
    '''
    if isinstance(net, torch.nn.Module):    # 检查是否使用框架
        net.train()
    metric = Accumulator(3)                 # 3个计数器
    for X, y in train_iter:                 # 获取数据集
        y_hat = net(X)
        l = loss(y_hat, y)                  # 计算损失函数
        if isinstance(updater, torch.optim.Optimizer):     # 如果优化函数来自框架（使用框架）
            updater.zero_grad()
            l.mean().backward()             # 框架的l返回的是标量，已经是各个样本l的loss均值了，mean无意义只是统一写法
            updater.step()  
        else:
            l.sum().backward()              # 反向传播
            updater(X.shape[0])             # 手写updater
        metric.add(float(l.sum()), accuracy(y_hat, y), y.numel())   # 计数器++
    return metric[0] / metric[2], metric[1] / metric[2]

def train_ch3(net, train_iter, test_iter, loss, num_epochs, updater):
    '''正式训练'''
    animator = d2l.Animator(xlabel='epoch', xlim=[1, num_epochs], ylim=[0.3, 0.9], legend=['train loss', 'train acc', 'test acc'])          # 初始化出图对象
    for epoch in range(num_epochs):                         # 针对每个迭代周期
        train_metrics = train_epoch_ch3(net, train_iter, loss, updater) # 训练
        test_acc = evaluate_accuracy(net, test_iter)                    # 做整体评估
        animator.add(epoch + 1, train_metrics + (test_acc,))            # 画图
    train_loss, train_acc = train_metrics                       # 平均损失+训练精度
    assert train_loss < 0.5, train_loss                         # 以下三行都是断言检查
    assert train_acc <= 1 and train_acc > 0.7, train_acc        # 若不满足条件
    assert test_acc <= 1 and test_acc > 0.7, test_acc           # 则直接报错返回后者值

lr = 0.1

def updater(batch_size):
    return d2l.sgd([W, b], lr, batch_size)          # 小批量随机梯度下降

num_epochs = 10
train_ch3(net, train_iter, test_iter, cross_entropy, num_epochs, updater)

def pridict_ch3(net, test_iter, n=9):
    i = 0
    for X, y in test_iter:
        i += 1
        if i > 9:
            break
    trues = d2l.get_fashion_mnist_labels(y)
    preds = d2l.get_fashion_mnist_labels(net(X).argmax(axis=1))
    titles = [true + '\n' + pred for true, pred in zip(trues, preds)]
    d2l.show_images(X[0:n].reshape((n, 28, 28)), 1, n, titles=titles[0:n])

pridict_ch3(net, test_iter)