import os
import torch
import transformers
import time
import asyncio
import threading
from collections import deque
from torch.utils.data import Dataset, DataLoader
from transformers import AutoConfig, AutoTokenizer, AutoModelForCausalLM, TextStreamer
from accelerate import init_on_device

# device = torch.device("cuda:0")
device = torch.device("cuda:0") if torch.cuda.is_available() else 'cpu'

SIMULATED_ALLREDUCE_DELAY = 0.001

# original_parameter = torch.nn.Parameter
# original_empty = torch.empty

# def parameter_on_device(data, requires_grad=True):
#     return original_parameter(data.to(device), requires_grad=requires_grad)

# def empty_on_device(*size, **kwargs):
#     if 'device' in kwargs:
#         kwargs['device'] = device
#     return original_empty(*size, **kwargs)

# # monkey patch torch so that we can directly create parameter on device
# torch.nn.Parameter = parameter_on_device
# torch.empty = empty_on_device


# dataset
class SyntheticDataset(Dataset):
    def __init__(self, vocab_size=32000, seq_length=2048, num_samples=1000):
        self.vocab_size = vocab_size
        self.seq_length = seq_length
        self.num_samples = num_samples
        
    def __len__(self):
        return self.num_samples
    
    def __getitem__(self, idx):
        input_ids = torch.randint(0, self.vocab_size, (self.seq_length,))
        attention_mask = torch.ones(self.seq_length, dtype=torch.long)
        labels = input_ids.clone()
        return {
            "input_ids": input_ids,
            "attention_mask": attention_mask,
            "labels": labels
        }


coldstart_start_time = time.time()

print("load config...")
config = AutoConfig.from_pretrained("./model_train/config.json")

print("create model arch...")
with init_on_device(device):
    model = AutoModelForCausalLM.from_config(config).to(device)
    model.gradient_checkpointing_enable()

print("load tokenizer...")
tokenizer = AutoTokenizer.from_pretrained("./model_train", use_fast=True)
tokenizer.save_pretrained("./model_train")

pid = os.getpid()
print(f"process id: {pid}")
print(torch.cuda.memory_summary())

dataset = SyntheticDataset(seq_length=512)
dataloader = DataLoader(dataset, batch_size=2)

optimizer = torch.optim.AdamW(model.parameters(), lr=1e-5)

iter_times = deque(maxlen=10)

async def run_pos_cli(pid, cmd):
    env = os.environ.copy()
    env.pop("LD_PRELOAD", None)
    process = await asyncio.create_subprocess_shell(
        cmd,
        stdout=asyncio.subprocess.PIPE,
        stderr=asyncio.subprocess.PIPE,
        env=env
    )
    stdout, stderr = await process.communicate()
    if process.returncode == 0:
        print(f"[stdout]\n{stdout.decode()}")
    else:
        print(f"[stderr]\n{stderr.decode()}")
        raise RuntimeError(f"Command failed with return code {process.returncode}")


class phos:
    @staticmethod
    def predump(pid, mode='cow'):
        async def run_and_log():
            try:
                if mode == 'cow':
                    await run_pos_cli(pid, cmd=f"pos_cli --pre-dump --dir ./ckpt --option cow --pid {pid}")
                elif mode == 'sow':
                    await run_pos_cli(pid, cmd=f"pos_cli --pre-dump --dir ./ckpt --pid {pid}")
                elif mode == 'cuda-ckpt':
                    await run_pos_cli(pid, cmd = f"bash run_nvcr_ckpt.sh -c")
                    await run_pos_cli(pid, cmd = f"bash run_nvcr_ckpt.sh -s false -g")
            except Exception as e:
                print(f"[run_pos_cli] Error: {e}")
        def runner():
            asyncio.run(run_and_log())
        threading.Thread(target=runner, daemon=True).start()


model.train()
for batch_idx, batch in enumerate(dataloader):
    start_time = time.time()
    inputs = {k: v.to(device) for k, v in batch.items()}
    inputs["use_cache"] = False

    # checkpoint before forward
    if batch_idx == 22:
        print(torch.cuda.memory_summary())
        phos.predump(pid, mode='cow')

    s_tick = time.time()
    model(**inputs)
    model(**inputs)
    model(**inputs)
    model(**inputs)
    model(**inputs)
    model(**inputs)
    model(**inputs)
    model(**inputs)
    torch.cuda.synchronize()
    e_tick = time.time()
    print(f"forward time: {e_tick-s_tick}")
    
    s_tick = time.time()
    outputs = model(**inputs)
    loss = outputs.loss
    loss.backward()
    torch.cuda.synchronize()
    e_tick = time.time()
    print(f"backward time: {e_tick-s_tick}")


    # time.sleep(SIMULATED_ALLREDUCE_DELAY)

    optimizer.step()
    optimizer.zero_grad()

    end_time = time.time()
    iter_times.append(end_time - start_time)

    if batch_idx % 10 == 0:
        avg_time = sum(iter_times) / len(iter_times)
        print(f"Step {batch_idx}, Avg Iter Time: {avg_time:.4f}s")
        # print(f"Step {batch_idx}, Loss: {loss.item():.4f}, Avg Iter Time: {avg_time:.4f}s")
