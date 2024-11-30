#!/bin/bash

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
dir_path="./ckpt"

if [ $# -ne 2 ]; then
    echo "usage: $0 <continuous ckpt interval (ms)> <pid>"
    exit 1
fi

umount_mem_ckpt() {
    for dir in "$dir_path"/*/; do
        if [ -d "$dir" ]; then
            umount "$dir" 2>/dev/null
            if [ $? -eq 0 ]; then
                echo "umount: $dir"
            else
                echo "failed to umount: $dir"
            fi
        fi
    done
    umount $dir_path
    rm -rf $dir_path
    echo "umount and rm: $dir_path"
}

interval=$(echo "$1 / 1000" | bc -l)
pid=$2
pre_dump_version=0

cd $script_dir
umount_mem_ckpt
if [ ! -d "$dir_path" ]; then
    mkdir ckpt    
fi

while true; do
    if ps -p $pid > /dev/null; then
        pos_cli --pre-dump --dir ./ckpt/$pre_dump_version --pid $pid
        pre_dump_version=$((pre_dump_version + 1))
    else
        break
    fi
    sleep $interval
done
