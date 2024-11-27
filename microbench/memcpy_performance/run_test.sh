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

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

cd $script_dir && cd .. && cd ..
sudo docker run --gpus all -dit --privileged -v $PWD/microbench:/root --network=host --ipc=host --name pos_mb_memcpy_test zobinhuang/pos_svr_base:11.3

sudo docker exec -it pos_mb_memcpy_test bash

sudo docker container stop pos_mb_memcpy_test
sudo docker container rm pos_mb_memcpy_test
