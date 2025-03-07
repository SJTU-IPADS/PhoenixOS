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

#!/bin/bash

# >>>>>>>>>> common variables <<<<<<<<<<
script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
assets_dir=$script_dir/../../assets
docker_assets_dir=$script_dir/../../dockerfiles/assets
third_party_dir=$script_dir/../../third_party
download_url_prefix=https://github.com/SJTU-IPADS/PhoenixOS-Assets

# import utilities
source $script_dir/../common.sh

set -e

# ================== program starts here ==================
# we need wget to install
util_install_common wget wget

# make sure asset directory exist
if [ ! -d "$assets_dir" ]; then
    mkdir -p "$assets_dir"
fi

if [ ! -d "$docker_assets_dir" ]; then
    mkdir -p "$docker_assets_dir"
fi

# libclang-static-build
git lfs pull
tar -zxvf $third_party_dir/libclang-static-build.tar.gz -C $third_party_dir

