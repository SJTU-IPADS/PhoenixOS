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

# >>>>>>>>>> global variables <<<<<<<<<<
git config --global --add safe.directory /root
DIR_ROOT=$(git rev-parse --show-toplevel)
DIR_ASSETS=$DIR_ROOT/assets
DIR_POS=$DIR_ROOT/pos
DIR_REMOTING=$DIR_ROOT/remoting
DIR_TEST=$DIR_ROOT/test
DIR_THIRD_PARTIES=$DIR_ROOT/third_party
DIR_SCRIPTS=$DIR_ROOT/scripts

# >>>>>>>>>> included utilities <<<<<<<<<<
source $DIR_SCRIPTS/utils/log.sh
source $DIR_SCRIPTS/utils/dependencies.sh
