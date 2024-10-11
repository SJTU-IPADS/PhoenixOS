import torch
from transformers import GPT2Tokenizer, GPT2LMHeadModel, set_seed
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
set_seed(42)
device = 'cuda' if torch.cuda.is_available() else 'cpu'

# tokenizer = GPT2Tokenizer.from_pretrained('gpt2')
# tokenizer.save_pretrained('./tokenizer/')

tokenizer = GPT2Tokenizer.from_pretrained('./tokenizer/')
tokenizer.padding_side = 'left'
tokenizer.pad_token = tokenizer.eos_token

# model = GPT2LMHeadModel.from_pretrained('gpt2').to(device)
# model.save_pretrained('./model/')
model = GPT2LMHeadModel.from_pretrained('./model/').to(device)

texts = ["Hello, I'm a language model," for _ in range(batch_size)]

# remove initial overhead
torch.cuda.empty_cache()
for i in range(2):
    encoding = tokenizer(texts, padding=True, return_tensors='pt').to(device)
    with torch.no_grad():
        generated_ids = model.generate(**encoding, max_length=20)
        generated_texts = tokenizer.batch_decode(generated_ids, skip_special_tokens=True)


duration_list = [] # ms

all_s_time = time.time()

for i in range(num_iter):
    s_time = time.time()
    encoding = tokenizer(texts, padding=True, return_tensors='pt').to(device)
    with torch.no_grad():
        generated_ids = model.generate(**encoding, max_length=20)
        generated_texts = tokenizer.batch_decode(generated_ids, skip_special_tokens=True)
    e_time = time.time()
    duration_list.append(int(round((e_time-s_time) * 1000))) # ms

all_e_time = time.time()

np_duration_list = np.array(duration_list)

print(
    f"latency:"
    f" p10({np.percentile(np_duration_list, 10)} ms), "
    f" p50({np.percentile(np_duration_list, 50)} ms), "
    f" p99({np.percentile(np_duration_list, 99)} ms), "
    f" mean({np.mean(np_duration_list)} ms)"
)
print(f'overall time used: {(all_e_time-all_s_time)*1000} ms')

# print(generated_texts)
