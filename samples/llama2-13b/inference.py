model_id = 'meta-llama/Llama-2-13b-chat-hf'

import time
import transformers
from transformers import AutoTokenizer, AutoModelForCausalLM
from huggingface_hub import login
login(token = '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')

# model = AutoModelForCausalLM.from_pretrained(model_id, device_map='auto', use_auth_token=True)
# model.save_pretrained('./model')

# tokenizer = AutoTokenizer.from_pretrained(model_id, use_auth_token=True)
# tokenizer.save_pretrained('./tokenizer')

# exit(0)

model = AutoModelForCausalLM.from_pretrained('./model').to('cuda:0')
tokenizer = AutoTokenizer.from_pretrained('./tokenizer')

# pip install accelerate
# pip install -i https://pypi.org/simple/ bitsandbytes

#Llama 2 Inference
def stream(user_prompt, batch_size=1):
    system_prompt = 'You are a helpful assistant that provides accurate and concise responses'

    B_INST, E_INST = "[INST]", "[/INST]"
    B_SYS, E_SYS = "<<SYS>>\n", "\n<</SYS>>\n\n"

    prompt = f"{B_INST} {B_SYS}{system_prompt.strip()}{E_SYS}{user_prompt.strip()} {E_INST}\n\n"

    inputs = tokenizer([prompt for _ in range(0, batch_size)], return_tensors="pt").to("cuda:0")

    # streamer = TextStreamer(tokenizer)

    s_time = time.time()
    # Despite returning the usual output, the streamer will also print the generated text to stdout.
    reply = model.generate(**inputs, max_new_tokens=20)
    e_time = time.time()

    num_tokens = 0
    for response in reply:
        num_tokens += list(response.size())[0]

    thpr = num_tokens/((e_time-s_time)/60)
    # print(f"throughput: {thpr} tokens / min")
    # return thpr

    return e_time-s_time, thpr, num_tokens

stream('Count to ten')
