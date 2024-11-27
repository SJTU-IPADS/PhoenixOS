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

#!/bin/bash

log() {
  echo -e "\033[37m [POS Build Log] $1 \033[0m"
}

warn() {
  echo -e "\033[33m [POS Build Wrn] $1 \033[0m"
}

error() {
  echo -e "\033[31m [POS Build Err] $1 \033[0m"
  exit 0
}

error_f() {
    string_template="$1"
    shift
    params="$@"
    printf "\033[31m [POS Build Err] $string_template \033[0m" $params
    exit 1
}
