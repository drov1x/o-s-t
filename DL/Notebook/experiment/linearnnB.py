import torch
from torch.utils import data
from torch import nn
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

def data_iter(data_arrays, batch_size, trains = True):
    dataset = data.TensorDataset(*data_arrays)
    return data.DataLoader(data)

