script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $script_dir

if [ -f "./client_exist.txt" ]; then
    rm ./client_exist.txt
fi

# 16384 * 16384 = 268435456 (268.43M)
LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../remoting/cuda/cpu/:../../build LD_PRELOAD=../../remoting/cuda/cpu/cricket-client.so REMOTE_GPU_ADDRESS=10.66.10.1 python3 ./main.py --Max_train_steps 1500 --eval_interval 100 --T_horizon 256 --net_width 4096


# nsys for client behaviour:
# nsys profile -t cuda,nvtx -o ./resnet_50_client_output --force-overwrite true python3 ./main.py --Max_train_steps 20000
# nsys profile -t cuda,nvtx -o ./resnet_50_client_output --export json --force-overwrite true python3 ./main.py --Max_train_steps 20000

# to download the nsys result
# scp -r hzb@meepo4:/disk1/hzb/projects/pos/reorg/phoenixos/samples/cuda_resnet_train_single_node/resnet_50_client_output.nsys-rep ~/Desktop
