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
