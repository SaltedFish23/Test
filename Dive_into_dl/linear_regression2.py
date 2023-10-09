import random
import torch
import numpy as np
import pandas
import matplotlib.pyplot as p
from torch.utils import data
from torch import nn
#from d2l import torch as d2l

def synthetic_data(w,b,num_example): # return X,y
    X = torch.normal(0,1,(num_example,len(w))) # X is a matrix with the size of num_example * len(w)
    y = torch.matmul(X,w) + b
    y += torch.normal(0,0.01,y.shape)
    return X,y.reshape((-1,1)) #让y成为列向量，不过在这个例子里面直接return也行，因为w为列向量
true_w = torch.tensor([2,-3.4])
true_b = 4.2
features,labels = synthetic_data(true_w,true_b,1000)

def load_array(data_arrays,batch_size,shuffle_in_train = True):
    dataset = data.TensorDataset(*data_arrays)
    return data.DataLoader(dataset,batch_size,shuffle_in_train)

batch_size = 10
data_iter = load_array((features,labels),batch_size)

net = nn.Sequential(nn.Linear(2,1))
net[0].weight.data.normal_(0,0.01)
net[0].bias.data.fill_(0)

#loss = nn.MSELoss()
loss = nn.HuberLoss()

trainer = torch.optim.SGD(net.parameters(),lr = 0.03)

num_epochs = 10
for epoch in range(num_epochs):
    for X,y in data_iter:
        l = loss(net(X),y)
        trainer.zero_grad()
        l.backward()
        trainer.step()
    l = loss(net(features),labels)
    print(f'epoch {epoch+1}, loss {l:f}')