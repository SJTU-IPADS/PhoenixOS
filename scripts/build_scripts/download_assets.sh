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
wget -P $third_party_dir $download_url_prefix/releases/download/v0.1.0/libclang-static-build.tar.gz
tar -zxvf $third_party_dir/libclang-static-build.tar.gz -C $third_party_dir

# go
wget -P $assets_dir $download_url_prefix/releases/download/v0.1.0/go1.23.2.linux-amd64.tar.gz

# nsight system
wget -P $docker_assets_dir $download_url_prefix/releases/download/v0.1.0/NsightSystems-linux-cli-public-2023.4.1.97-3355750.deb
