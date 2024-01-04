import torch
import numpy as np
from tqdm import tqdm
import torch.nn as nn
import torch.optim as optim
from utils.readData import read_dataset
from utils.ResNet import ResNet18
import time

torch.backends.cudnn.enabled = False

device = 'cuda:0' if torch.cuda.is_available() else 'cpu'
batch_size = 128

train_loader,valid_loader,test_loader = read_dataset(batch_size=batch_size,pic_path='dataset')
n_class = 10

model = ResNet18()
model.conv1 = nn.Conv2d(in_channels=3, out_channels=64, kernel_size=3, stride=1, padding=1, bias=False)
model.fc = torch.nn.Linear(512, n_class)
model = model.to(device)
criterion = nn.CrossEntropyLoss().to(device)


n_epochs = 1
valid_loss_min = np.Inf # track change in validation loss
accuracy = []
lr = 0.1
counter = 0
for epoch in tqdm(range(1, n_epochs+1)):
    # keep track of training and validation loss
    train_loss = 0.0
    valid_loss = 0.0
    total_sample = 0
    right_sample = 0
    
    # dynamically adjust the learning rate here
    if counter/10 ==1:
        counter = 0
        lr = lr*0.5
    
    optimizer = optim.SGD(model.parameters(), lr=lr, momentum=0.9, weight_decay=5e-4)
    
    start_t = time.time()

    nb_iteration = 0

    model.train()
    for data, target in train_loader:
        data = data.to(device)
        target = target.to(device)
        optimizer.zero_grad()
        output = model(data).to(device)
        loss = criterion(output, target)

        loss.backward()

        optimizer.step()
        train_loss += loss.item()*data.size(0)

        nb_iteration += 1
        
        # POS: we only train 5 iteration for test
        if nb_iteration == 5:
            break

    # model.eval()
    # for data, target in valid_loader:
    #     data = data.to(device)
    #     target = target.to(device)
    #     output = model(data).to(device)
    #     loss = criterion(output, target)
    #     valid_loss += loss.item()*data.size(0)
    #     _, pred = torch.max(output, 1)    
    #     correct_tensor = pred.eq(target.data.view_as(pred))
    #     total_sample += batch_size
    #     for i in correct_tensor:
    #         if i:
    #             right_sample += 1

    end_t = time.time()

    print(f"end-to-end duration: {int(round((end_t-start_t) * 1000))}ms")

    print("Accuracy:",100*right_sample/total_sample,"%")
    accuracy.append(right_sample/total_sample)
 
    train_loss = train_loss/len(train_loader.sampler)
    valid_loss = valid_loss/len(valid_loader.sampler)
        
    print('Epoch: {} \tTraining Loss: {:.6f} \tValidation Loss: {:.6f}'.format(
        epoch, train_loss, valid_loss))
    
    if valid_loss <= valid_loss_min:
        print('Validation loss decreased ({:.6f} --> {:.6f}).  Saving model ...'.format(valid_loss_min,valid_loss))
        # torch.save(model.state_dict(), 'checkpoint/resnet18_cifar10.pt')
        valid_loss_min = valid_loss
        counter = 0
    else:
        counter += 1
