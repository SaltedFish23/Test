import torch
from torch import nn
import torchvision
import torchvision.models as models
from torch.utils import data
from torchvision import transforms
import random
import pandas
import numpy
import matplotlib.pyplot as plt
from IPython import display
import visdom
from torch.utils.data import TensorDataset, DataLoader


class classfier(nn.Module): #densenet, use batchnorm and relu
    def __init__(self):
        
        
    def forward(self,X):
        


class accumulator:
    def __init__(self,n):
        self.data = [0.0]*n
        
    def add(self,*args):
        self.data = [a + float(b) for a,b in zip(self.data,args)]
        
    def reset(self):
        self.data = [0.0]*len(self.data)
    
    def __getitem__(self,idx):
        return self.data[idx]

class visualize(object):
    def __init__(self,env='default',**kwargs):
        self.vis = visdom.Visdom(env=env,**kwargs)
        self.index = {}
        self.vis.line([0.],[0.],win='classifier',opts=dict(title = 'classifier'))
    
    def paint(self,train_loss,test_accuracy,train_accuracy,epochs):
        self.vis.line([[train_loss,test_accuracy,train_accuracy]],[epochs],win='train',update='append')

def data_iter(data,labels,batch_size): #输入张量
    data_set = TensorDataset(torch.FloatTensor(data),torch.LongTensor(labels))
    data_loader = DataLoader(data_set,batch_size=batch_size,shuffle=True)
    return iter(data_loader)

def loss():
    return torch.nn.CrossEntropyLoss()

def optimize(model,lr = 0.01,momentum = 0.5):
    return torch.optim.SGD(model.parameters(),lr=lr,momentum=momentum)

def train_epoch(X,y,net,loss,optimizer,device): # return the loss and accuracy
    optimizer.zero_grad()
    X,y = X.to(device),y.to(device)
    y_hat = net(X)
    l = loss(y_hat,y)
    l.backward()
    optimizer.step()
    with torch.no_grad():
        return l*X.shape[0],accuracy(y_hat,y),X.shape[0]

def train(net,train_iter,test_iter,num_epochs,loss,optimizer,device): #visualise的初始化放在里面
    net.to(device)
    visualizer = visualize()
    for epoch in range(num_epochs):
        metric = accumulator(3)
        for X,y in train_iter:
            metric.add(train_epoch(X,y,net,loss,optimizer,device))
        train_l = metric[0] / metric[2]
        train_acc = metric[1] / metric[2]
        test_acc = accuracy_test(net,test_iter)
        visualizer.paint(train_l,test_acc,train_acc,epoch)

#def updater():
    

def accuracy(y_hat,y):
    if len(y_hat.shape) > 1 and y_hat.shape[1] > 1:
        y_hat = y_hat.argmax(axis=1)
    cmp = y_hat.type(y.dtype) == y
    return float(cmp.type(y.dtype).sum())

def accuracy_test(net,data_iter,device=None):
    """使用GPU计算模型在数据集上的精度"""
    if isinstance(net, nn.Module):
        net.eval()  # 设置为评估模式
        if not device:
            device = next(iter(net.parameters())).device
    # 正确预测的数量，总预测的数量
    metric = accumulator(2)
    with torch.no_grad():
        for X, y in data_iter:
            if isinstance(X, list):
                X = [x.to(device) for x in X]
            else:
                X = X.to(device)
            y = y.to(device)
            metric.add(accuracy(net(X), y), y.numel())
    return metric[0] / metric[1]