# Copyright 2024 The PhoenixOS Authors. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

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
