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

# import utilities
source $script_dir/../common.sh



# ================== program starts here ==================
check_and_install_go
if [ $? -ne 0 ]; then
    error "failed to install golang"
fi

cd $script_dir
go build -o pos_build
if [ $? -ne 0 ]; then
    error "faile to build PhOS's build system"
fi
if [ ! -e $script_dir/pos_build ]; then
    error "no building binary was built"
fi

./pos_build "$@"
