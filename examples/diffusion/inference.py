import os
# os.environ["PYTORCH_CUDA_ALLOC_CONF"] = "max_split_size_mb:1024"

import torch
from diffusers import StableDiffusionPipeline, StableDiffusionOnnxPipeline
import time
import sys
import asyncio
import threading
import ctypes


torch.backends.cudnn.enabled = False

if(len(sys.argv) < 3):
    print('Usage: python3 inference.py num_iter batch_size [model_path]')
    sys.exit()

pid = os.getpid()
print(f"process id: {pid}")

num_iter = int(sys.argv[1])
batch_size = int(sys.argv[2])

model_path = '/data/huggingface/hub/CompVis/stable-diffusion-v1-4'
if len(sys.argv) > 3:
    model_path = sys.argv[3]
    print('model_path:', model_path)
else:
    print('Using remote model:', model_path)
    
device = 'cuda' if torch.cuda.is_available() else 'cpu'

print("read model")
pipe = StableDiffusionPipeline.from_pretrained(
    model_path,
    revision="main",
    torch_dtype=torch.float32,
).to(device)

total_params = sum(p.numel() for p in pipe.unet.parameters()) + \
               sum(p.numel() for p in pipe.text_encoder.parameters()) + \
               sum(p.numel() for p in pipe.vae.parameters())
print(f"Total parameters: {total_params}")

print("end read model")

prompt = "a photo of an astronaut riding a horse on mars"

# if batch_size>16:
#     pipe.enable_vae_slicing()

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


T1 = time.time()

for i in range(num_iter):
    print("iter: ", i)
    # if i == 1:
    #     phos.predump(pid, mode='cow')
    images = pipe(prompt=[prompt] * batch_size, num_inference_steps=100).images
    
T2 = time.time()
print('time used: ', T2-T1)

# images[0].save("astronaut_rides_horse.png")
