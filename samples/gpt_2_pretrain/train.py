import pickle
import torch
from torch.utils.data import Dataset
import torch.nn.utils.rnn as rnn_utils
from transformers import GPT2LMHeadModel, GPT2Tokenizer
from torch.utils.data import DataLoader
from torch.optim import Adam
from tqdm import tqdm
import numpy as np
import time

train_path = './dataset/train.plb'
val_num = 1
max_len = 150
batch_size = 2
num_workers = 10
epochs = 1
device = 'cuda:0'

ignore_index = -100
gradient_accumulation_steps = 4
max_grad_norm = 2.0
eps = 1.0e-09
lr = 2.6e-5

class GPT2Dataset(Dataset):
    def __init__(self, input_list, max_len):
        self.input_list = input_list
        self.max_len = max_len

    def __getitem__(self, index):
        input_ids = self.input_list[index]
        input_ids = input_ids[:self.max_len]
        input_ids = torch.tensor(input_ids, dtype=torch.long)
        return input_ids

    def __len__(self):
        return len(self.input_list)

def load_dataset():
    """
    加载训练集和验证集
    """
    with open(train_path, "rb") as f:
        input_list = pickle.load(f)
        

    # 划分训练集与验证集
    input_list_train = input_list[val_num:]
    input_list_val = input_list[:val_num]

    train_dataset = GPT2Dataset(input_list_train, max_len)
    val_dataset = GPT2Dataset(input_list_val, max_len)

    return train_dataset, val_dataset


def calculate_acc(logit, labels, ignore_index=-100):
    logit = logit[..., :-1, :].contiguous().view(-1, logit.size(-1))
    labels = labels[..., 1:].contiguous().view(-1)

    # 对于每条数据，返回最大的index
    _, logit = logit.max(dim=-1)  
    
    # 进行非运算，返回一个tensor，若labels的第i个位置为pad_id，则置为0，否则为1
    non_pad_mask = labels.ne(ignore_index)
    n_correct = logit.eq(labels).masked_select(non_pad_mask).sum().item()
    n_word = non_pad_mask.sum().item()
    return n_correct, n_word

def train_epoch(model, train_dataloader, optimizer, epoch):
    model.train()

    epoch_correct_num, epoch_total_num = 0, 0
    duration_list = [] # ms

    for batch_idx, (input_ids, labels) in enumerate(tqdm(train_dataloader)):
        s_time = time.time()
        input_ids = input_ids.to(device)
        labels = labels.to(device)
        outputs = model.forward(input_ids, labels=labels)
        logits = outputs.logits
        loss = outputs.loss
        loss = loss.mean()

        # 统计该batch的预测token的正确数与总数
        batch_correct_num, batch_total_num = calculate_acc(logits, labels, ignore_index=ignore_index)

        # 统计该epoch的预测token的正确数与总数
        epoch_correct_num += batch_correct_num
        epoch_total_num += batch_total_num
        # 计算该batch的accuracy
        batch_acc = batch_correct_num / batch_total_num

        if gradient_accumulation_steps > 1:
            loss = loss / gradient_accumulation_steps
        
        loss.backward()

        # 梯度裁剪
        torch.nn.utils.clip_grad_norm_(model.parameters(), max_grad_norm)

        # 进行一定step的梯度累计之后，更新参数
        if (batch_idx + 1) % gradient_accumulation_steps == 0:
            # 更新参数
            optimizer.step()
            # 清空梯度信息
            optimizer.zero_grad()

        del input_ids, outputs

        e_time = time.time()
        duration_list.append(int(round((e_time-s_time) * 1000))) # ms

        if batch_idx == 128:
            break

    np_duration_list = np.array(duration_list)
    print(
        f"latency:"
        f" p10({np.percentile(np_duration_list, 10)} ms), "
        f" p50({np.percentile(np_duration_list, 50)} ms), "
        f" p99({np.percentile(np_duration_list, 99)} ms), "
        f" mean({np.mean(np_duration_list)} ms)"
    )


def validate_epoch(model, validate_dataloader, epoch):
    model.eval()
    total_loss = 0
    with torch.no_grad():
        
        for batch_idx, (input_ids, labels) in enumerate(validate_dataloader):  
            input_ids = input_ids.to(device)
            labels = labels.to(device)
            outputs = model.forward(input_ids, labels=labels)
            logits = outputs.logits
            loss = outputs.loss
            loss = loss.mean()

            total_loss += loss.item()
            del input_ids, outputs
    
        # 记录当前epoch的平均loss
        epoch_mean_loss = total_loss / len(validate_dataloader)
        return epoch_mean_loss

def train(model, train_dataset, validate_dataset):
    def collate_fn(batch):
        input_ids = rnn_utils.pad_sequence(batch, batch_first=True, padding_value=0)
        labels = rnn_utils.pad_sequence(batch, batch_first=True, padding_value=-100)
        return input_ids, labels
    
    train_dataloader = DataLoader(
        train_dataset, batch_size=batch_size, shuffle=True, num_workers=num_workers, collate_fn=collate_fn, drop_last=True
    )

    validate_dataloader = DataLoader(
        validate_dataset, batch_size=batch_size, shuffle=True, num_workers=num_workers, collate_fn=collate_fn, drop_last=True
    )

    optimizer = Adam(model.parameters(), lr=lr)

    train_losses, validate_losses = [], []
    best_val_loss = 10000
    for epoch in range(epochs):
        train_loss = train_epoch(model=model, train_dataloader=train_dataloader, optimizer=optimizer, epoch=epoch)
        train_losses.append(train_loss)

        # validate_loss = validate_epoch(model=model, validate_dataloader=validate_dataloader, epoch=epoch)
        # validate_losses.append(validate_loss)

        # if validate_loss < best_val_loss:
        #     best_val_loss = validate_loss
        #     # save model

def main():
    print("loading the spliting datasets...")
    train_dataset, validate_dataset = load_dataset()

    print("loading model...")
    model = GPT2LMHeadModel.from_pretrained('./model').to(device)
    tokenizer = GPT2Tokenizer.from_pretrained('./tokenizer')
    assert model.config.vocab_size == tokenizer.vocab_size
    num_parameters = 0
    parameters = model.parameters()
    for parameter in parameters:
        num_parameters += parameter.numel()
    print(f'(number of model parameters: {num_parameters})\n')

    print("start training...")
    train(model, train_dataset, validate_dataset)

if __name__ == '__main__':
    main()
