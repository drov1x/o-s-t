import torch
import random

def synthetic_dataset(w, b, num):
    X = torch.normal(0, 1, (num, len(w)))
    y = torch.matmul(X, w) + b
    y += torch.normal(0, 0.01, y.shape)
    return X, y.reshape(-1, 1)

w = torch.tensor([3, 4], dtype = torch.float32)
b = 2
dataset_num = 1000
features, labels = synthetic_dataset(w, b, dataset_num)

def data_iter(batch_size, features, labels):
    nums = len(features)
    indices = list(range(nums))

    random.shuffle(indices)
    for i in range(0, nums, batch_size):
        tindices = torch.tensor(indices[i: min(i + batch_size, nums)])
        yield features[tindices], labels[tindices]

#print(next(data_iter(10, features, labels)))

w = torch.normal(0, 0.01, size=(2, 1), requires_grad=True)
b = torch.zeros(1, requires_grad=True)

def LinearNN(X, w, b):
    return torch.matmul(X, w) + b

def MSEloss(hat_y, y):
    return (hat_y - y) ** 2 / 2

def sgd(params, lr, batch_size):
    with torch.no_grad():
        for i in params:
            i -= (lr * i.grad) / batch_size
            i.grad.zero_()

loss = MSEloss
net = LinearNN

lr = 0.03
epochs = 3

batch_size = 10

for i in range(epochs):
    for X, y in data_iter(batch_size, features, labels):
        l = loss(net(X, w, b), y)
        l.sum().backward()
        sgd([w, b], lr, batch_size)
    with torch.no_grad():
        l_sum = loss(net(features, w, b), labels)
        print(f'epoch: {i + 1}, loss: {l_sum.mean()}')