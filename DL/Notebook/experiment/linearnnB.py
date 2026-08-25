import torch
from torch.utils import data
from torch import nn

def synthetic_dataset(w, b, num):
    X = torch.normal(0, 1, (num, len(w)))
    y = torch.matmul(X, w) + b
    y += torch.normal(0, 0.01, y.shape)
    return X, y.reshape(-1, 1)

w = torch.tensor([3, 4], dtype = torch.float32)
b = 2
dataset_num = 1000
features, labels = synthetic_dataset(w, b, dataset_num)
batch_size = 10

def data_iter(data_arrays, batch_size, trains = True):
    dataset = data.TensorDataset(*data_arrays)
    return data.DataLoader(dataset, batch_size, shuffle=trains)

net = nn.Sequential(nn.Linear(2, 1))

nn.init.normal_(net[0].weight, std=0.01)

loss = nn.MSELoss()

trainer = torch.optim.SGD(net.parameters(), lr = 0.03)

num_epochs = 3
big_epochs = 16
lr = 0.03

for be in range(big_epochs):
    trainer = torch.optim.SGD(net.parameters(), lr = lr)
    for epoch in range(num_epochs):
        for X, y in data_iter((features, labels), batch_size):
            l = loss(net(X), y)
            trainer.zero_grad()
            l.backward()
            trainer.step()
        l = loss(net(features), labels)
        print(f"epoch {epoch+1}, loss {l}")
    lr /= 5