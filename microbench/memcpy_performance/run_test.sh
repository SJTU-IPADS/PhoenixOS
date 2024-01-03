script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

cd $script_dir && cd .. && cd ..
sudo docker run --gpus all -dit --privileged -v $PWD/microbench:/root --network=host --ipc=host --name pos_mb_memcpy_test zobinhuang/pos_svr_base:11.3

sudo docker exec -it pos_mb_memcpy_test bash

sudo docker container stop pos_mb_memcpy_test
sudo docker container rm pos_mb_memcpy_test
