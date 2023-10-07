import random
import torch
import numpy
import pandas
import matplotlib.pyplot as plt

true_w = torch.tensor([2,-3.4])
true_b = 4.2
w = torch.normal(0,1,size=(2,1),requires_grad=True)
b = torch.zeros(1,requires_grad=True) #用torch来初始化是因为后面训练要用到梯度
def synthetic_data(w,b,num_example): # return X,y
    X = torch.normal(0,1,(num_example,len(w))) # X is a matrix with the size of num_example * len(w)
    y = torch.matmul(X,w) + b
    y += torch.normal(0,0.01,y.shape)
    return X,y.reshape((-1,1)) #让y成为列向量，不过在这个例子里面直接return也行，因为w为列向量

def data_iter(features,labels,batch_size):
    num_examples = len(labels)
    list_of_example = list(range(num_examples))
    random.shuffle(list_of_example)
    for i in range(0,num_examples,batch_size):
        list_of_batch = torch.tensor(list_of_example[i : min(num_examples,i+batch_size)])
        yield features[list_of_batch],labels[list_of_batch]

def linreg(X,w,b):
    return torch.matmul(X,w) + b

def loss(labels,y):
    return (labels - y.reshape(labels.shape)) ** 2 / 2

def optimize(params,learning_rate,batch_size):
    with torch.no_grad():
        for param in params:
            param -= learning_rate * param.grad / batch_size
            param.grad.zero_()

lr = 0.04
num_epoch = 5
batch_size = 10
features,labels = synthetic_data(true_w,true_b,1000)
for epoch in range(num_epoch):
    for X,y in data_iter(features,labels,batch_size):
        l = loss(y,linreg(X,w,b))
        l.sum().backward()
        optimize([w,b],lr,batch_size)