import torch

# set device
device = torch.device("cuda:0")


x = torch.randn(3,1,5,4)
#print(x)
# batch=3, channel=1, h=5, w=4

norm = torch.nn.BatchNorm2d(1)
# 1 is the channel
norm = norm.to(device)
x = x.to(device)
res = norm(x).to(device)

res = res.cpu()
print(res)
print(res.shape)    
