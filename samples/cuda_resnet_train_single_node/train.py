import torch
import numpy as np
from tqdm import tqdm
import torch.nn as nn
import torch.optim as optim
from utils.readData import read_dataset
from utils.ResNet import ResNet50, ResNet101, ResNet152
import time
import os

torch.backends.cudnn.enabled = False

# torch.set_num_threads(1)

print(f"process id: {os.getpid()}")

device = 'cuda:0' if torch.cuda.is_available() else 'cpu'
n_class = 10

# model = ResNet50()
model = ResNet152()

model = model.to(device)


def run_train():
    criterion = nn.CrossEntropyLoss().to(device)
    
    batch_size = 32
    
    n_epochs = 1
    valid_loss_min = np.Inf # track change in validation loss
    accuracy = []
    iter_durations = []
    lr = 0.1
    counter = 0

    train_loader, valid_loader, test_loader = read_dataset(batch_size=batch_size,pic_path='dataset')

    for epoch in tqdm(range(1, n_epochs+1)):
        # keep track of training and validation loss
        train_loss = 0.0
  
        # dynamically adjust the learning rate here
        if counter/10 ==1:
            counter = 0
            lr = lr*0.5
        
        optimizer = optim.SGD(model.parameters(), lr=lr, momentum=0.9, weight_decay=5e-4)
        
        nb_iteration = 0

        with_torch_ckpt = False
        torch_ckpt_ptr = 0
        torch_ckpt_interval = 5

        model.train()
        for data, target in train_loader:
            start_t = time.time()

            data = data.to(device)
            target = target.to(device)
                             
            output = model(data).to(device)

            optimizer.zero_grad()
            loss = criterion(output, target)
            loss.backward()
            optimizer.step()
            train_loss += loss.item()*data.size(0)

            nb_iteration += 1
            
            # NOTE: we force sync here to make sure the execution is done
            # torch.cuda.default_stream(0).synchronize()
            host_output = output.to("cpu")
            
            # checkpoint using naive torch
            if with_torch_ckpt and (torch_ckpt_ptr == torch_ckpt_interval):
                # mount -t tmpfs -o size=80g tmpfs /root/samples/torch_ckpt
                # umount /root/samples/torch_ckpt
                torch.save(model.state_dict(), '/root/samples/torch_ckpt/model.dict')
                torch_ckpt_ptr = 0
            else:
                torch_ckpt_ptr += 1

            end_t = time.time()

            print(f"itetration {nb_iteration} duration: {int(round((end_t-start_t) * 1000))} ms")
            iter_durations.append(int(round((end_t-start_t) * 1000)))

            if nb_iteration == 64:
                print(f"reach {nb_iteration}, break")
                break
        
        np_iter_durations = np.array(iter_durations)
        mean = np.mean(np_iter_durations)
        std = np.std(np_iter_durations)

        # cut_off = std
        # lower, upper = mean - cut_off, mean + cut_off
        # new_np_iter_durations = np_iter_durations[(np_iter_durations > lower) & (np_iter_durations < upper)]
        # print(f"drop wierd duration lower than {lower} or larger than {upper}")

        new_np_iter_durations = np_iter_durations

        throughput_list_str = "0, "
        time_list_str = "0, "
        time_accu = 0 #s
        for i, duration in enumerate(new_np_iter_durations):
            time_accu += duration / 1000
            if i != len(new_np_iter_durations) - 1:
                throughput_list_str += f"{60000/duration:.2f}, "
                time_list_str += f"{time_accu:.2f}, "
            else:
                throughput_list_str += f"{60000/duration:.2f}"
                time_list_str += f"{time_accu:.2f}"

        print(f"throughput list: {throughput_list_str}")
        print(f"time list: {time_list_str}")
        print(
            f"latency:"
            f" p10({np.percentile(new_np_iter_durations, 10)} ms), "
            f" p50({np.percentile(new_np_iter_durations, 50)} ms), "
            f" p99({np.percentile(new_np_iter_durations, 99)} ms), "
            f" mean({np.mean(new_np_iter_durations)} ms)"
        )
        

def run_infer():
    iter_durations = []
    nb_iteration = 0

    batch_size = 128
    train_loader, valid_loader, test_loader = read_dataset(batch_size=batch_size,pic_path='dataset')

    with torch.no_grad():
        all_start_t = time.time()
        for data, target in train_loader:
            start_t = time.time()

            data = data.to(device)
            output = model(data).to(device)

            # NOTE: we force sync here to make sure the execution is done
            # torch.cuda.default_stream(0).synchronize()
            host_output = output.to("cpu")
            
            nb_iteration += 1
            
            end_t = time.time()

            print(f"itetration {nb_iteration} duration: {int(round((end_t-start_t) * 1000))} ms")
            iter_durations.append(int(round((end_t-start_t) * 1000)))

            # POS: we only train 15 iteration for test
            # change this number to 15 while enable level-1 continuous checkpoint
            if nb_iteration == 64:
                print(f"reach {nb_iteration}, break")
                break
        all_end_t = time.time()
        
        np_iter_durations = np.array(iter_durations)
        mean = np.mean(np_iter_durations)
        std = np.std(np_iter_durations)

        # cut_off = std
        # lower, upper = mean - cut_off, mean + cut_off
        # new_np_iter_durations = np_iter_durations[(np_iter_durations > lower) & (np_iter_durations < upper)]
        # print(f"drop wierd duration lower than {lower} or larger than {upper}")

        new_np_iter_durations = np_iter_durations

        throughput_list_str = "0, "
        time_list_str = "0, "
        time_accu = 0 #s
        for i, duration in enumerate(new_np_iter_durations):
            time_accu += duration / 1000
            if i != len(new_np_iter_durations) - 1:
                throughput_list_str += f"{1000/duration*batch_size:.2f}, "
                time_list_str += f"{time_accu:.2f}, "
            else:
                throughput_list_str += f"{1000/duration*batch_size:.2f}"
                time_list_str += f"{time_accu:.2f}"

        print(f"throughput list: {throughput_list_str}")
        print(f"time list: {time_list_str}")
        print(
            f"latency:"
            f" p10({np.percentile(new_np_iter_durations, 10)} ms), "
            f" p50({np.percentile(new_np_iter_durations, 50)} ms), "
            f" p99({np.percentile(new_np_iter_durations, 99)} ms), "
            f" mean({np.mean(new_np_iter_durations)} ms)"
        )
        print(f"all duration: {(all_end_t - all_start_t)*1000:.2f} ms")

if __name__ == '__main__':
    run_train()
    # run_infer()
