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

import sys
import glob

'''
argv[1] - module name
'''
kArgvIndex_module = 1

args = sys.argv

# add all local source files
sources = glob.glob(f"./{args[kArgvIndex_module]}/**/*.c", recursive=True)     \
        + glob.glob(f"./{args[kArgvIndex_module]}/**/*.cpp", recursive=True)   \
        + glob.glob(f"./{args[kArgvIndex_module]}/**/*.cc", recursive=True)

for i in sources:
    if "__template__" in i or "__TEMPLATE__" in i:
        continue
    print(i)
