import torch

# set device
device = torch.device("cuda:0")


x = torch.randn(3,1,5,4)
#print(x)

conv = torch.nn.Conv2d(1,4,(2,3))
conv = conv.to(device)
x = x.to(device)
res = conv(x).to(device)

res = res.cpu()
print(res)
print(res.shape)    # torch.Size([3, 4, 4, 2])
