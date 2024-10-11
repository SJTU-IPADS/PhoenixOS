model_id = 'meta-llama/Llama-2-7b-chat-hf'

import time
import os
import numpy as np
import transformers
from transformers import AutoTokenizer, AutoModelForCausalLM, TextStreamer

# from huggingface_hub import login
# login(token = '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')

# model = AutoModelForCausalLM.from_pretrained(model_id, device_map='auto')
# model.save_pretrained('./model')

# tokenizer = AutoTokenizer.from_pretrained(model_id)
# tokenizer.save_pretrained('./tokenizer')

# exit(0)

print(f"process id: {os.getpid()}")

model_path = '/root/samples/model/llama2'
tokenizer_path = '/root/samples/tokenizer/llama2'

model = AutoModelForCausalLM.from_pretrained(model_path).to('cuda:0')
# model_cpu = AutoModelForCausalLM.from_pretrained(model_path).to('cpu')

tokenizer = AutoTokenizer.from_pretrained(tokenizer_path)

mock_coldstart = True
if mock_coldstart:
    exit(0)

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
    

def test_lat_bw():
    duration_list = [] # s
    thpr_list = [] # token / min

    for i in range(0, 32):
        duration, thpr, _ = stream('Count to 128', batch_size=1)
        duration_list.append(duration)
        thpr_list.append(thpr)
        print(f'loop {i}, duration({duration} ms)')

    np_duration_list = np.array(duration_list)
    print(
        f"latency:"
        f" p10({np.percentile(np_duration_list, 10)} ms), "
        f" p50({np.percentile(np_duration_list, 50)} ms), "
        f" p99({np.percentile(np_duration_list, 99)} ms), "
        f" mean({np.mean(np_duration_list)} ms)"
    )

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

    print(f"thpr list: {throughput_list_str}")
    print(f"time list: {time_list_str}")


def test_restore():
    duration, _, _ = stream('Count to 4', batch_size=8)
    print(f"duration: {duration} s")
    while True:
        user_input = input("input 'q' to exit：")
        if user_input.lower() == 'q':
            break

test_lat_bw()
