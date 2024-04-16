from transformers import GPT2Tokenizer
from tqdm import tqdm
import numpy as np
import pickle

train_path = './dataset/train.txt'
save_path = './dataset/train.plb'

def preprocess():
    # 初始化tokenizer
    tokenizer = GPT2Tokenizer.from_pretrained('./tokenizer')
    sep_id = tokenizer.sep_token_id
    cls_id = tokenizer.cls_token_id
    
    print(sep_id)
    print(cls_id)

    # 读取训练数据集
    with open(train_path, 'rb') as f:
        data = f.read().decode("utf-8")

    # 需要区分linux和windows环境下的换行符
    if "\r\n" in data:
        train_data = data.split("\r\n\r\n")
    else:
        train_data = data.split("\n\n")

    # 开始进行tokenize
    # 保存所有的对话数据,每条数据的格式为："[CLS]utterance1[SEP]utterance2[SEP]utterance3[SEP]"
    dialogue_len = []  # 记录所有对话tokenize之后的长度，用于统计中位数与均值
    dialogue_list = []
    with open(save_path, "w", encoding="utf-8") as f:
        for index, dialogue in enumerate(tqdm(train_data)):
            if "\r\n" in data:
                utterances = dialogue.split("\r\n")
            else:
                utterances = dialogue.split("\n")

            # input_ids = [cls_id]  # 每个dialogue以[CLS]开头
            input_ids = []
            for utterance in utterances:
                input_ids += tokenizer.encode(utterance, add_special_tokens=False)
                # input_ids.append(sep_id)  # 每个utterance之后添加[SEP]，表示utterance结束
            
            if len(input_ids) == 0:
                continue

            dialogue_len.append(len(input_ids))
            dialogue_list.append(input_ids)
    len_mean = np.mean(dialogue_len)
    len_median = np.median(dialogue_len)
    len_max = np.max(dialogue_len)
    with open(save_path, "wb") as f:
        pickle.dump(dialogue_list, f)

if __name__ == '__main__':
    preprocess()
