import torch
from  torch import nn
from d2l import torch as d2l

batch_size = 256
train_iter,test_iter = d2l.load_data_fashion_mnist(batch_size)

num_inputs,num_outputs,num_hiddens = 784,10,256
W1 = nn.Parameter(torch.randn(num_inputs,num_hiddens,requires_grad=True) * 0.01)
b1 = nn.Parameter(torch.zeros(num_hiddens,requires_grad=True))
W2 = nn.Parameter(torch.randn(num_hiddens,num_outputs,requires_grad=True) * 0.01)
b2 = nn.Parameter(torch.zeros(num_outputs,requires_grad=True))
params = [W1,b1,W2,b2]

def relu(X):
    a = torch.zeros_like(X)
    return torch.max(a,X)

def net(X):
    X = X.reshape((-1,num_inputs))
    H = relu(X@params[0] + params[1])
    return H@params[2] + params[3]

loss = nn.CrossEntropyLoss(reduction='None')

num_epochs,lr = 10,0.1
updater = torch.optim.SGD(params,lr = lr)
'''for epoch in range(num_epochs):
    for X,y in train_iter:
        l = loss(net(X),y)
        updater.zero_grad()
        l.backward()
        updater.step()
    '''