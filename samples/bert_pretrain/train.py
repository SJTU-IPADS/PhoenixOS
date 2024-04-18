import torch
import numpy as np
from transformers import BertTokenizer
import pandas as pd
import time

model_path = '/root/samples/model/bert'
tokenizer_path = '/root/samples/tokenizer/bert'
batch_size = 8


tokenizer = BertTokenizer.from_pretrained(tokenizer_path)
labels = {
    'business':0,
    'entertainment':1,
    'sport':2,
    'tech':3,
    'politics':4
}

class Dataset(torch.utils.data.Dataset):
    def __init__(self, df):
        self.labels = [labels[label] for label in df['category']]
        self.texts = [tokenizer(text, 
                                padding='max_length', 
                                max_length = 512, 
                                truncation=True,
                                return_tensors="pt") 
                      for text in df['text']]

    def classes(self):
        return self.labels

    def __len__(self):
        return len(self.labels)

    def get_batch_labels(self, idx):
        # Fetch a batch of labels
        return np.array(self.labels[idx])

    def get_batch_texts(self, idx):
        # Fetch a batch of inputs
        return self.texts[idx]

    def __getitem__(self, idx):
        batch_texts = self.get_batch_texts(idx)
        batch_y = self.get_batch_labels(idx)
        return batch_texts, batch_y

from torch import nn
from transformers import BertModel

class BertClassifier(nn.Module):
    def __init__(self, dropout=0.5):
        super(BertClassifier, self).__init__()
        self.bert = BertModel.from_pretrained(model_path)
        self.dropout = nn.Dropout(dropout)
        # self.linear = nn.Linear(768, 5)
        self.linear = nn.Linear(1024, 5)
        self.relu = nn.ReLU()

    def forward(self, input_id, mask):
        _, pooled_output = self.bert(input_ids= input_id, attention_mask=mask,return_dict=False)
        dropout_output = self.dropout(pooled_output)
        linear_output = self.linear(dropout_output)
        final_layer = self.relu(linear_output)
        return final_layer

from torch.optim import Adam
from tqdm import tqdm

def train(model, train_data, val_data, learning_rate, epochs):
    # 通过Dataset类获取训练和验证集
    train, val = Dataset(train_data), Dataset(val_data)
    
    # DataLoader根据batch_size获取数据，训练时选择打乱样本
    train_dataloader = torch.utils.data.DataLoader(train, batch_size=batch_size, shuffle=True)
    val_dataloader = torch.utils.data.DataLoader(val, batch_size=batch_size)
    
    # 判断是否使用GPU
    use_cuda = torch.cuda.is_available()
    device = torch.device("cuda:0" if use_cuda else "cpu")
    
    # 定义损失函数和优化器
    criterion = nn.CrossEntropyLoss()
    optimizer = Adam(model.parameters(), lr=learning_rate)

    if use_cuda:
        model = model.cuda()
        criterion = criterion.cuda()
    
    # 开始进入训练循环
    for epoch_num in range(epochs):
        # 定义两个变量，用于存储训练集的准确率和损失
        total_acc_train = 0
        total_loss_train = 0

        duration_list = [] # ms

        # 进度条函数tqdm
        for batch_idx, (train_input, train_label) in enumerate(tqdm(train_dataloader)):
            s_time = time.time()
            train_label = train_label.to(device)
            mask = train_input['attention_mask'].to(device)
            input_id = train_input['input_ids'].squeeze(1).to(device)
            # 通过模型得到输出
            output = model(input_id, mask)
            # 计算损失
            batch_loss = criterion(output, train_label)
            total_loss_train += batch_loss.item()
            # 计算精度
            acc = (output.argmax(dim=1) == train_label).sum().item()
            total_acc_train += acc
            # 模型更新
            model.zero_grad()
            batch_loss.backward()
            optimizer.step()

            e_time = time.time()
            duration_list.append(int(round((e_time-s_time) * 1000))) # ms
            
            if batch_idx == 64:
                break
        
        np_duration_list = np.array(duration_list)
    
        mean = np.mean(np_duration_list)
        std = np.std(np_duration_list)

        # cut_off = std * 3
        # lower, upper = mean - cut_off, mean + cut_off
        # new_np_duration_list = np_duration_list[(np_duration_list > lower) & (np_duration_list < upper)]
        # print(f"drop wierd duration lower than {lower} or larger than {upper}")

        new_np_iter_durations = np_duration_list

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
        
        print(
            f"latency:"
            f" p10({np.percentile(new_np_iter_durations, 10)} ms), "
            f" p50({np.percentile(new_np_iter_durations, 50)} ms), "
            f" p99({np.percentile(new_np_iter_durations, 99)} ms), "
            f" mean({np.mean(new_np_iter_durations)} ms)"
        )

        print(f"throughput list: {throughput_list_str}")
        print(f"time list: {time_list_str}")

        exit(0)

        # ------ 验证模型 -----------
        # 定义两个变量，用于存储验证集的准确率和损失
        total_acc_val = 0
        total_loss_val = 0

        # 不需要计算梯度
        with torch.no_grad():
            # 循环获取数据集，并用训练好的模型进行验证
            for val_input, val_label in val_dataloader:
                # 如果有GPU，则使用GPU，接下来的操作同训练
                val_label = val_label.to(device)
                mask = val_input['attention_mask'].to(device)
                input_id = val_input['input_ids'].squeeze(1).to(device)

                output = model(input_id, mask)

                batch_loss = criterion(output, val_label)
                total_loss_val += batch_loss.item()
                
                acc = (output.argmax(dim=1) == val_label).sum().item()
                total_acc_val += acc
        
        # print(
        #     f'''Epochs: {epoch_num + 1} 
        #     | Train Loss: {total_loss_train / len(train_data): .3f} 
        #     | Train Accuracy: {total_acc_train / len(train_data): .3f} 
        #     | Val Loss: {total_loss_val / len(val_data): .3f} 
        #     | Val Accuracy: {total_acc_val / len(val_data): .3f}''')


def main():
    bbc_text_df = pd.read_csv('./dataset/bbc-text.csv')
    df = pd.DataFrame(bbc_text_df)

    print("loading the spliting datasets...")
    df_train, df_val, df_test = np.split(
        df.sample(frac=1, random_state=42),
        [int(.8*len(df)), int(.9*len(df))]
    )
    
    print("loading model...")
    model = BertClassifier()

    print("start training...")
    train(model=model, train_data=df_train, val_data=df_val, learning_rate=0.5, epochs=1)

if __name__ == '__main__':
    main()
