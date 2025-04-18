# Copyright 2025 The PhoenixOS Authors. All rights reserved.
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
