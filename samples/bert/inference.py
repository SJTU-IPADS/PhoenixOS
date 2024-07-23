import torch
from transformers import BertTokenizer, BertForMaskedLM
import time
import sys
import ctypes
import os
import numpy as np

print(f"process id: {os.getpid()}")

if(len(sys.argv) != 3):
    print('Usage: python3 inference.py num_iter batch_size')
    sys.exit()

num_iter = int(sys.argv[1])
batch_size = int(sys.argv[2])
device = 'cuda' if torch.cuda.is_available() else 'cpu'

model_path = '/root/samples/model/bert'
tokenizer_path = '/root/samples/tokenizer/bert'

# tokenizer = BertTokenizer.from_pretrained('bert-base-uncased')
# tokenizer.save_pretrained('./tokenizer_base')
tokenizer = BertTokenizer.from_pretrained(tokenizer_path)

# model = BertForMaskedLM.from_pretrained('bert-base-uncased').to(device)
# model.save_pretrained('./model_base')
model = BertForMaskedLM.from_pretrained(model_path).to(device)

mock_coldstart = False
if mock_coldstart:
    exit(0)

masked_sentences = ["The primary [MASK] of the United States is English." for _ in range(batch_size)]
pos_masks = [3 for _ in range(batch_size)]

# remove initial overhead
torch.cuda.empty_cache()
for i in range(2):
    encoded_inputs = tokenizer(masked_sentences, return_tensors='pt', padding='max_length', max_length=20).to(device)
    outputs = model(**encoded_inputs)
    most_likely_token_ids = [torch.argmax(outputs[0][i, pos, :]) for i, pos in enumerate(pos_masks)]
    unmasked_tokens = tokenizer.decode(most_likely_token_ids).split(' ')
    unmasked_sentences = [masked_sentences[i].replace('[MASK]', token) for i, token in enumerate(unmasked_tokens)]

duration_list = [] # ms
thpr_list = [] # token / min

all_s_time = time.time()

for i in range(num_iter):
    s_time = time.time()
    encoded_inputs = tokenizer(masked_sentences, return_tensors='pt', padding='max_length', max_length=20).to(device)
    outputs = model(**encoded_inputs)
    most_likely_token_ids = [torch.argmax(outputs[0][i, pos, :]) for i, pos in enumerate(pos_masks)]
    unmasked_tokens = tokenizer.decode(most_likely_token_ids).split(' ')
    unmasked_sentences = [masked_sentences[i].replace('[MASK]', token) for i, token in enumerate(unmasked_tokens)]
    e_time = time.time()

    thpr = len(most_likely_token_ids)/((e_time-s_time)/60)

    duration_list.append(int(round((e_time-s_time) * 1000))) # ms
    thpr_list.append(thpr)

    print(f'{i}th iter: {thpr} tokens/min')
    
all_e_time = time.time()

time_accu = 0 #s
time_list_str = "0, "
throughput_list_str = "0, "
for i, duration in enumerate(duration_list):
    time_accu += duration / 1000
    if i != len(duration_list) - 1:
        time_list_str += f"{time_accu:.2f}, "
        throughput_list_str += f"{thpr_list[i]:.2f}, "
    else:
        time_list_str += f"{time_accu:.2f}"
        throughput_list_str += f"{thpr_list[i]:.2f}"



np_duration_list = np.array(duration_list)

print(
    f"latency:"
    f" p10({np.percentile(np_duration_list, 10)} ms), "
    f" p50({np.percentile(np_duration_list, 50)} ms), "
    f" p99({np.percentile(np_duration_list, 99)} ms), "
    f" mean({np.mean(np_duration_list)} ms)"
)

print(f"thpr list: {throughput_list_str}")
print(f"time list: {time_list_str}")
print(f'overall time used: {(all_e_time-all_s_time)*1000} ms')

# print(unmasked_sentences)
