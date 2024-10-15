#! /bin/bash

export POS_BUILD_TARGET=cuda

chmod +x ../scripts/utils/get_cuda_version.sh
cuda_version=$(../scripts/utils/get_cuda_version.sh)

chmod +x ../scripts/utils/get_root_dir.sh
project_root_dir=$(../scripts/utils/get_root_dir.sh)

export POS_BUILD_ROOT=$project_root_dir
export POS_BUILD_TARGET_VERSION=$cuda_version
export POS_BUILD_ENABLE_RUNTIME_DEBUG_CHECK=1
export POS_BUILD_ENABLE_PRINT_ERROR=1
export POS_BUILD_ENABLE_PRINT_WARN=1
export POS_BUILD_ENABLE_PRINT_LOG=1
export POS_BUILD_ENABLE_PRINT_DEBUG=1
export POS_BUILD_ENABLE_PRINT_WITH_COLOR=1
