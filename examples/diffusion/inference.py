import os
# os.environ["PYTORCH_CUDA_ALLOC_CONF"] = "max_split_size_mb:1024"

import torch
from diffusers import StableDiffusionPipeline, StableDiffusionOnnxPipeline
import time
import sys
import ctypes


torch.backends.cudnn.enabled = False

if(len(sys.argv) < 3):
    print('Usage: python3 inference.py num_iter batch_size [model_path]')
    sys.exit()

print(f"process id: {os.getpid()}")

num_iter = int(sys.argv[1])
batch_size = int(sys.argv[2])

model_path = '/data/huggingface/hub/stable-diffusion-v1-4'
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


T1 = time.time()

for i in range(num_iter):
    print("iter: ", i)
    images = pipe(prompt=[prompt] * batch_size, num_inference_steps=50).images
    
T2 = time.time()
print('time used: ', T2-T1)

# images[0].save("astronaut_rides_horse.png")
