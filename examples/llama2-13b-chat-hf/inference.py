import os
import torch
import transformers
import time
from transformers import AutoTokenizer, AutoModelForCausalLM, TextStreamer

model = AutoModelForCausalLM.from_pretrained('/nvme/huggingface/hub/models--meta-llama--Llama-2-13b-chat-hf/snapshots/a2cb7a712bb6e5e736ca7f8cd98167f81a0b5bd8/').to('cuda:0')
tokenizer = AutoTokenizer.from_pretrained('/nvme/huggingface/hub/models--meta-llama--Llama-2-13b-chat-hf/snapshots/a2cb7a712bb6e5e736ca7f8cd98167f81a0b5bd8/')

print(f"process id: {os.getpid()}")

torch.backends.cudnn.enabled = False
device = 'cuda:0' if torch.cuda.is_available() else 'cpu'

def infer(user_prompt, batch_size=1):
    system_prompt = "Act as an expert in writing captivating stories. Your task is to create detailed and engaging characters for a story based on the following abstract. Each character should have a distinct personality, background, motivations, and development arc that aligns with the story's themes and direction. Consider how these characters interact with each other and how their individual journeys contribute to the overall narrative. Make sure to include both protagonists and antagonists, giving each a unique voice and perspective. Your characters should be relatable and compelling to the readers, driving the story forward and enhancing its emotional impact.\n"

    B_INST, E_INST = "[INST]", "[/INST]"
    B_SYS, E_SYS = "<<SYS>>\n", "\n<</SYS>>\n\n"

    prompt = f"{B_INST} {B_SYS}{system_prompt.strip()}{E_SYS}{user_prompt.strip()} {E_INST}\n\n"
    inputs = tokenizer([prompt for _ in range(0, batch_size)], return_tensors="pt", return_token_type_ids=False).to(device)

    streamer = TextStreamer(tokenizer)

    # streaming
    start_time = time.time()
    generated_texts = model.generate(**inputs, streamer=streamer)
    end_time = time.time()

    # calculate throughput
    text_length = 0
    for text in generated_texts:
        text_length += list(text.size())[0]
    elapsed_time = end_time - start_time
    throughput = text_length / elapsed_time
    print(f'Throughput: {throughput:.2f} characters per second')

    return


if __name__ == '__main__':
    user_prompt = "In a quiet village nestled between two mountains, a young girl named Lila discovers an ancient, shimmering stone that grants her the ability to communicate with the stars. As she learns their secrets, she finds herself drawn into a cosmic conflict between light and darkness. With the fate of her village hanging in the balance, Lila must unite her community and harness the power of the stars to restore harmony before the shadows consume everything she loves."

    for i in range(0, 20):
        infer(user_prompt=user_prompt, batch_size=1)
        print("\n\n\n")
