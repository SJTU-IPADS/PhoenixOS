model_id = 'NousResearch/Meta-Llama-3-8B'

import transformers
from transformers import AutoTokenizer, AutoModelForCausalLM, TextStreamer
from huggingface_hub import login
login(token = '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')

model = AutoModelForCausalLM.from_pretrained(model_id, device_map='auto')
model.save_pretrained('../model/llama3-8b')

tokenizer = AutoTokenizer.from_pretrained(model_id)
tokenizer.save_pretrained('../tokenizer/llama3-8b')

exit(0)

# model = AutoModelForCausalLM.from_pretrained('./model').to('cuda:0')
# tokenizer = AutoTokenizer.from_pretrained('./tokenizer')

# pip install accelerate
# pip install -i https://pypi.org/simple/ bitsandbytes

#Llama 3 Inference
def stream(user_prompt):
    system_prompt = 'You are a helpful assistant that provides accurate and concise responses'

    B_INST, E_INST = "[INST]", "[/INST]"
    B_SYS, E_SYS = "<<SYS>>\n", "\n<</SYS>>\n\n"

    prompt = f"{B_INST} {B_SYS}{system_prompt.strip()}{E_SYS}{user_prompt.strip()} {E_INST}\n\n"

    inputs = tokenizer([prompt], return_tensors="pt").to("cuda:0")

    streamer = TextStreamer(tokenizer)

    # Despite returning the usual output, the streamer will also print the generated text to stdout.
    _ = model.generate(**inputs, streamer=streamer, max_new_tokens=500)

stream('Count to ten')
