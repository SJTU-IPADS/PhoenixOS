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

#! /bin/bash

# this script is for fast debug of auto-generator
chmod +x ../scripts/utils/get_root_dir.sh
project_root_dir=$(../scripts/utils/get_root_dir.sh)
export POS_BUILD_CONF_PlatformProjectRoot=$project_root_dir

export POS_BUILD_CONF_RuntimeTarget=cuda

chmod +x ../scripts/utils/get_cuda_version.sh
cuda_version=$(../scripts/utils/get_cuda_version.sh)
export POS_BUILD_CONF_RuntimeTargetVersion=$cuda_version

export POS_BUILD_CONF_RuntimeEnablePrintError=1
export POS_BUILD_CONF_RuntimeEnablePrintWarn=1
export POS_BUILD_CONF_RuntimeEnablePrintLog=1
export POS_BUILD_CONF_RuntimeEnablePrintDebug=0
export POS_BUILD_CONF_RuntimeEnablePrintWithColor=1
export POS_BUILD_CONF_RuntimeEnableDebugCheck=1
export POS_BUILD_CONF_RuntimeEnableHijackApiCheck=1
export POS_BUILD_CONF_RuntimeEnableTrace=0
export POS_BUILD_CONF_RuntimeDefaultDaemonLogPath="/var/log/phos/daemon.log"
export POS_BUILD_CONF_RuntimeDefaultClientLogPath="/var/log/phos/client.log"
export POS_BUILD_CONF_EvalCkptOptLevel=2
export POS_BUILD_CONF_EvalCkptEnableIncremental=1
export POS_BUILD_CONF_EvalCkptEnablePipeline=1
export POS_BUILD_CONF_EvalCkptDefaultIntervalMs=6000
export POS_BUILD_CONF_EvalMigrOptLevel=0
export POS_BUILD_CONF_EvalRstEnableContextPool=1
