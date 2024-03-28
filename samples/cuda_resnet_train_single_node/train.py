import torch
import numpy as np
from tqdm import tqdm
import torch.nn as nn
import torch.optim as optim
from utils.readData import read_dataset
from utils.ResNet import ResNet50
import time
import os
# import nvtx

torch.backends.cudnn.enabled = False

# torch.set_num_threads(1)

print(f"process id: {os.getpid()}")

device = 'cuda:0' if torch.cuda.is_available() else 'cpu'
batch_size = 1

train_loader,valid_loader,test_loader = read_dataset(batch_size=batch_size,pic_path='dataset')
n_class = 10

model = ResNet50()
# model.conv1 = nn.Conv2d(in_channels=3, out_channels=64, kernel_size=3, stride=1, padding=1, bias=False)
# model.fc = torch.nn.Linear(512, n_class)
model = model.to(device)
criterion = nn.CrossEntropyLoss().to(device)

nvtx_switch = False

def __nvtx_push(message:str, color:str):
    if nvtx_switch:
        return nvtx.start_range(message=message, color=color)

def __nvtx_pop(handle):
    if nvtx_switch:
        nvtx.end_range(handle)

n_epochs = 1
valid_loss_min = np.Inf # track change in validation loss
accuracy = []
iter_durations = []
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
    
    nb_iteration = 0

    model.train()
    for data, target in train_loader:
        start_t = time.time()

        rng_iter = __nvtx_push(message=f"iteration {nb_iteration}", color="blue")
        
        rng_copy = __nvtx_push(message=f"data transfer", color="red")
        data = data.to(device)
        target = target.to(device)
        __nvtx_pop(rng_copy)
                
        rng_fwd = __nvtx_push(message=f"forward", color="green")
        output = model(data).to(device)
        __nvtx_pop(rng_fwd)

        # NOTE: comment out to mock inference
        # TODO: use nsight system to see whether this part has multi-threads
        rng_bwd = __nvtx_push(message=f"backward", color="green")
        optimizer.zero_grad()
        loss = criterion(output, target)
        loss.backward()
        optimizer.step()
        train_loss += loss.item()*data.size(0)
        __nvtx_pop(rng_bwd)

        nb_iteration += 1
        
        # NOTE: we force sync here to make sure the execution is done
        # torch.cuda.default_stream(0).synchronize()
        host_output = output.to("cpu")

        __nvtx_pop(rng_iter)
        
        end_t = time.time()

        print(f"itetration {nb_iteration} duration: {int(round((end_t-start_t) * 1000))} ms")
        iter_durations.append(int(round((end_t-start_t) * 1000)))

        # POS: we only train 15 iteration for test
        # change this number to 15 while enable level-1 continuous checkpoint
        if nb_iteration == 15:
            print(f"reach {nb_iteration}, break")
            break
    
    np_iter_durations = np.array(iter_durations)
    mean = np.mean(np_iter_durations)
    std = np.std(np_iter_durations)

    cut_off = std * 3
    lower, upper = mean - cut_off, mean + cut_off
    new_np_iter_durations = np_iter_durations[(np_iter_durations > lower) & (np_iter_durations < upper)]

    print(f"drop wierd duration lower than {lower} or larger than {upper}")

    throughput_list_str = ""
    time_list_str = ""
    time_accu = 0 #s
    for i, duration in enumerate(new_np_iter_durations):
        time_accu += duration / 1000
        if i != len(new_np_iter_durations) - 1:
            throughput_list_str += f"{1000/duration:.2f}, "
            time_list_str += f"{time_accu:.2f}, "
        else:
            throughput_list_str += f"{1000/duration:.2f}"
            time_list_str += f"{time_accu:.2f}"
    print(f"throughput list: {throughput_list_str}")
    print(f"time list: {time_list_str}")

    print(f"avg itetration duration: {np.mean(new_np_iter_durations):.2f} ms")
    
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

    # print("Accuracy:",100*right_sample/total_sample,"%")
    # accuracy.append(right_sample/total_sample)
 
    # train_loss = train_loss/len(train_loader.sampler)
    # valid_loss = valid_loss/len(valid_loader.sampler)
        
    # print('Epoch: {} \tTraining Loss: {:.6f} \tValidation Loss: {:.6f}'.format(
    #     epoch, train_loss, valid_loss))
    
    # if valid_loss <= valid_loss_min:
    #     print('Validation loss decreased ({:.6f} --> {:.6f}).  Saving model ...'.format(valid_loss_min,valid_loss))
    #     # torch.save(model.state_dict(), 'checkpoint/resnet18_cifar10.pt')
    #     valid_loss_min = valid_loss
    #     counter = 0
    # else:
    #     counter += 1
