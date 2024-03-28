import torch
from transformers import GPT2Tokenizer, GPT2LMHeadModel, set_seed
import time
import sys
import ctypes
import os

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
    # generated_texts = tokenizer.batch_decode(generated_ids, skip_special_tokens=True)
    print(generated_ids)

T1 = time.time()

for i in range(num_iter):
    encoding = tokenizer(texts, padding=True, return_tensors='pt').to(device)
    with torch.no_grad():
        generated_ids = model.generate(**encoding, max_length=20)
    # generated_texts = tokenizer.batch_decode(generated_ids, skip_special_tokens=True)
    print(generated_ids)
    
T2 = time.time()
print('time used: ', T2-T1)
# print(generated_texts)
