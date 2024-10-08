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
