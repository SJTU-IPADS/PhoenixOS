#!/bin/bash

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
SUDO=
image=zobinhuang/pytorch:1.13.1-v2-criu-transformers


cd $script_dir && cd .. && cd ..

start=$(date +%s%N | cut -b1-13)
$SUDO docker run --gpus all -v $PWD:/root --privileged --rm -it $image bash -c "CUDA_VISIBLE_DEVICES=2 python3 /root/samples/cuda_resnet_train_single_node/train.py"
# $SUDO docker run --rm -it ubuntu bash -c "echo hello"
end=$(date +%s%N | cut -b1-13)

elapsed_ms=$(($end-$start))
echo "Elapsed time: $elapsed_ms ms."
