import numpy as np
import torch
from d2l import torch as d2l
from torch.utils import data
from torch import nn    # nn = Neural Network 神经网络

def synthetic_data(w, b, num_examples):
    '''生成数据集'''
    X = torch.normal(0, 1, (num_examples, len(w)))
    y = torch.matmul(X, w) + b
    y += torch.normal(0, 0.01, y.shape)
    return X, y.reshape((-1, 1))

true_w = torch.tensor([2, -3.4])
true_b = 4.2
features, labels = synthetic_data(true_w, true_b, 1000)

n = 0
print('features:', features[n], '\nlabels:', labels[n])

# 生成图查看样本情况
d2l.set_figsize()
d2l.plt.scatter(features[:, 1].detach().numpy(), labels.detach().numpy(), 1)


def load_array(data_arrays, batch_size, is_train = True):
    dataset = data.TensorDataset(*data_arrays)                          # 把元组解包成元素，xxx(a, b)
    return data.DataLoader(dataset, batch_size, shuffle = is_train)     # 返回的对象本质就是迭代器

batch_size = 10
data_iter = load_array((features, labels), batch_size)

print(next(iter(data_iter)))    # 检查迭代器

# 1. 创建模型
net = nn.Sequential(nn.Linear(2, 1))

# 2. 初始化模型参数
net[0].weight.data.normal_(0, 0.01)     # net[0]指的是Sequential对象的第一层
net[0].bias.data.fill_(0)

loss = nn.MSELoss()

trainer = torch.optim.SGD(net.parameters(), lr = 0.03)

num_epochs = 3
for epoch in range(num_epochs):
    for X, y in data_iter:
        l = loss(net(X), y)             # 前向计算
        trainer.zero_grad()             # 清空梯度
        l.backward()                    # 反向传播
        trainer.step()                  # 更新参数
    l = loss(net(features), labels)     # 计算整体loss均值
    print(f'epoch {epoch + 1}, loss {l:f}')