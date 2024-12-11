import time
import torch
from torch.utils.data import DataLoader, Dataset
from diffusers import StableDiffusionPipeline
from transformers import CLIPTextModel, CLIPTokenizer
import numpy as np

image_size = 64
batch_size = 4
num_epochs = 2
num_samples = 100
learning_rate = 5e-6
device = "cuda" if torch.cuda.is_available() else "cpu"
torch.backends.cudnn.enabled = False

class RandomDataset(Dataset):
    def __init__(self, size, num_samples):
        self.size = size
        self.num_samples = num_samples

    def __len__(self):
        return self.num_samples

    def __getitem__(self, idx):
        image = np.random.randn(3, self.size, self.size).astype(np.float32)
        caption = f"Random caption {idx}"
        return torch.tensor(image), caption


model_path = "/data/huggingface/hub/stable-diffusion-v1-4/"
pipeline = StableDiffusionPipeline.from_pretrained(model_path)
unet = pipeline.unet.to(device)
vae = pipeline.vae.to(device)
text_encoder = pipeline.text_encoder.to(device)
tokenizer = pipeline.tokenizer

vae.requires_grad_(False)
text_encoder.requires_grad_(False)

dataset = RandomDataset(size=image_size, num_samples=num_samples)
dataloader = DataLoader(dataset, batch_size=batch_size, shuffle=True)

optimizer = torch.optim.AdamW(unet.parameters(), lr=learning_rate)

start_time = time.perf_counter()

for epoch in range(num_epochs):
    print(f"Epoch {epoch + 1}/{num_epochs}")
    unet.train()
    for step, (images, captions) in enumerate(dataloader):
        inputs = tokenizer(
            captions, padding="max_length", truncation=True, return_tensors="pt"
        ).to(device)

        images = images.to(device)
        latents = vae.encode(images).latent_dist.sample()
        latents = latents * 0.18215  # Scale latents

        noise = torch.randn_like(latents).to(device)
        timesteps = torch.randint(0, 1000, (latents.shape[0],), device=device).long()
        noisy_latents = pipeline.scheduler.add_noise(latents, noise, timesteps)

        model_output = unet(
            noisy_latents,
            timesteps,
            encoder_hidden_states=text_encoder(inputs.input_ids).last_hidden_state,
        ).sample

        loss = torch.nn.functional.mse_loss(model_output, noise)

        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

        print(f"Epoch {epoch + 1}, Step {step + 1}, Loss: {loss.item()}")

end_time = time.perf_counter()
print(f"Time for training: {end_time - start_time:.2f}s")
