import torch
import torch.nn as nn

# 假设输入张量的特征数为input_features，输出张量的特征数为output_features
input_features = 10
output_features = 5

device = "cuda:0"

# 创建全连接层
linear_layer = nn.Linear(input_features, output_features)
linear_layer = linear_layer.to(device)

# 假设输入张量 x 的形状为 (batch_size, input_features)
x = torch.randn(32, input_features)
x = x.to(device)

# 使用全连接层进行前向传播
output = linear_layer(x).to(device)
output = output.cpu()
# 输出张量的形状为 (batch_size, output_features)
print(output)
print(output.shape)
