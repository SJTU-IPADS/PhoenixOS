import torch
from torch.utils.data import Dataset, DataLoader
import psutil
import os
import time


class DummyTextDataset(Dataset):
    def __init__(self, num_samples=65536, seq_len=2048, vocab_size=32000):
        self.num_samples = num_samples
        self.seq_len = seq_len
        self.vocab_size = vocab_size

    def __len__(self):
        return self.num_samples

    def __getitem__(self, idx):
        sample = torch.randint(0, self.vocab_size, (self.seq_len,), dtype=torch.long)
        return sample


dataset = DummyTextDataset(num_samples=65536, seq_len=2048)
dataloader = DataLoader(dataset, batch_size=64, shuffle=False, pin_memory=True)

pid = os.getpid()
print(f"process id: {pid}")

batches = []

# 强制写入 pinned memory buffer
def touch_tensor(t: torch.Tensor):
    if not t.is_pinned():
        return
    # 转成 numpy array，逐个元素写入（原地修改）
    a = t.numpy()
    a += 1  # 原地写，触发 page commit

iterator = iter(dataloader)
for i in range(8192):
    try:
        batch = next(iterator)
    except StopIteration:
        iterator = iter(dataloader)
        batch = next(iterator)
    # 逐个 sample 强制触发写入 pinned page
    if isinstance(batch, torch.Tensor):
        touch_tensor(batch)
    else:
        for sample in batch:
            touch_tensor(sample)
    batches.append(batch)


def print_memory_usage():
    process = psutil.Process(os.getpid())
    mem_info = process.memory_info()
    print(f"RSS (Resident Set Size): {mem_info.rss / (1024 ** 2):.2f} MB")
    print(f"VMS (Virtual Memory Size): {mem_info.vms / (1024 ** 2):.2f} MB")

print_memory_usage()

while True:
    pass
