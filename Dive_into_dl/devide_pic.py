import torch
import torchvision
from torch.utils import data
from torchvision import transforms
import random
import pandas
import numpy
import matplotlib.pyplot as plt
import time
from IPython import display

#plt.use_svg_display()

def get_mnist_labels(labels): #'labels is a list or an int
    text_labels = ['t-shirt', 'trouser', 'pullover', 'dress', 'coat','sandal', 'shirt', 'sneaker', 'bag', 'ankle boot']
    return [text_labels[int(i)] for i in labels]

def get_dataloader_workers(): #?
    return 4

#train_iter = data.DataLoader(mnist_train,batch_size,shuffle=True,num_workers=get_dataloader_workers())

#test the time consuming in opening train dataset
'''if __name__ == '__main__':
    start = time.time()
    for X,y in train_iter:
        continue
    end = time.time()
    print(f'{end-start:.2f} sec')'''
    
def load_data_fashion_mnist(batch_size,resize = None):
    trans = transforms.ToTensor()
    if resize:
        trans.insert(0,transforms.Resize(resize))
    trans = transforms.Compose(trans)
    mnist_train = torchvision.datasets.FashionMNIST(root="../data",train=True,transform=trans,download=False)
    mnist_test = torchvision.datasets.FashionMNIST(root="../data",train=False,transform=trans,download=False)
    return (data.DataLoader(mnist_train,batch_size,shuffle=True,num_workers=get_dataloader_workers()),data.DataLoader(mnist_test,batch_size,shuffle=True,num_workers=get_dataloader_workers()))

batch_size = 256