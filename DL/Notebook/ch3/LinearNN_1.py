import numpy as np
import torch
from d2l import torch as d2l
import random

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

def data_iter(batch_size, features, labels):
    '''读取数据集并形成迭代器'''
    num_examples = len(features)
    indices = list(range(num_examples))

    random.shuffle(indices) # 把所有样本序号打乱
    for i in range(0, num_examples, batch_size):
        batch_indices = torch.tensor(
            indices[i: min(i + batch_size, num_examples)])
        yield features[batch_indices], labels[batch_indices]
    # 使用迭代器，一次返回一整批元素

batch_size = 10

for X, y in data_iter(batch_size, features, labels):
    print(X, '\n', y)
    break

w = torch.normal(0, 0.01, size = (2, 1), requires_grad = True)
# 打破对称性，虽说对线性模型无影响，但是对多层模型很有必要

b = torch.zeros(1, requires_grad = True)

def linreg(X, w, b):
    '''线性回归模型'''
    return torch.matmul(X, w) + b #直接返回预测值hat y

def squared_loss(y_hat, y):
    '''均方损失函数'''
    return (y_hat - y.reshape(y_hat.shape)) ** 2 / 2 # 返回向量

def sgd(params, lr, batch_size):
    '''小批量随机梯度下降'''
    with torch.no_grad():
        for param in params:                        # 遍历params里的所有量
            param -= lr * param.grad / batch_size   # 对里面的参数依次调整
            param.grad.zero_()                      # 重置梯度

# 定义参数

# 超参
lr = 0.03       # 学习率
num_epochs = 3  # 迭代周期

# 重命名
net = linreg
loss = squared_loss

#开始训练   
for epoch in range(num_epochs):         # 迭代num_epochs次
    for X, y in data_iter(batch_size, features, labels):    # 使用先前定义的迭代器选取一小部分样本
        l = loss(net(X, w, b), y)       # 定义损失函数
        l.sum().backward()              # 反向传播，考虑到l不是标量，因此先求和
        sgd([w, b], lr, batch_size)     # 更新参数
    with torch.no_grad():
        train_l = loss(net(features, w, b), labels)                     # 获取全样本集的loss
        print(f'epoch {epoch + 1}, loss {float(train_l.mean()):f}')     # 输出测试
print(f'误差\nw: {true_w - w.reshape(true_w.shape)}\nb: {true_b - b}')