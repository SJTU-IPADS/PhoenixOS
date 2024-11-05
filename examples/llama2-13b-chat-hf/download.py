
import os
import transformers
from huggingface_hub import login
from transformers import AutoTokenizer, AutoModelForCausalLM

hf_token = os.getenv('HF_TOKEN')
login(token = hf_token)

model_id = 'meta-llama/Llama-2-7b-chat-hf'
model_path = './model'
tokenizer_path = './tokenizer'

# download model parameter
if not os.path.exists(model_path):
    os.makedirs(model_path)
model = AutoModelForCausalLM.from_pretrained(model_id, device_map='auto')
model.save_pretrained(model_path)

# download tokenizer parameter
if not os.path.exists(tokenizer_path):
    os.makedirs(model_path)
tokenizer = AutoTokenizer.from_pretrained(model_id)
tokenizer.save_pretrained(tokenizer_path)

exit(0)
