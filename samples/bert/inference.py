import torch
from transformers import BertTokenizer, BertForMaskedLM
import time
import sys
import ctypes
import os

if(len(sys.argv) != 3):
    print('Usage: python3 inference.py num_iter batch_size')
    sys.exit()

num_iter = int(sys.argv[1])
batch_size = int(sys.argv[2])
device = 'cuda' if torch.cuda.is_available() else 'cpu'

# tokenizer = BertTokenizer.from_pretrained('bert-base-uncased')
# tokenizer.save_pretrained('./tokenizer')
tokenizer = BertTokenizer.from_pretrained('./tokenizer')

# model = BertForMaskedLM.from_pretrained('bert-base-uncased').to(device)
# model.save_pretrained('./model')
model = BertForMaskedLM.from_pretrained('./model').to(device)

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

T1 = time.time()

for i in range(num_iter):
    encoded_inputs = tokenizer(masked_sentences, return_tensors='pt', padding='max_length', max_length=20).to(device)
    outputs = model(**encoded_inputs)
    most_likely_token_ids = [torch.argmax(outputs[0][i, pos, :]) for i, pos in enumerate(pos_masks)]
    unmasked_tokens = tokenizer.decode(most_likely_token_ids).split(' ')
    unmasked_sentences = [masked_sentences[i].replace('[MASK]', token) for i, token in enumerate(unmasked_tokens)]
    
T2 = time.time()
print('time used: ', T2-T1)
# print(unmasked_sentences)
