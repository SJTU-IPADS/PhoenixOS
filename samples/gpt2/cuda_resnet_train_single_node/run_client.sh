script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $script_dir
LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../remoting/cuda/cpu/:../../build LD_PRELOAD=../../remoting/cuda/cpu/cricket-client.so REMOTE_GPU_ADDRESS=10.66.10.1 python3 ./train.py 


# nsys for client behaviour:
# nsys profile -t cuda,nvtx -o ./resnet_50_client_output --force-overwrite true python3 ./train.py 
# nsys profile -t cuda,nvtx -o ./resnet_50_client_output --export json --force-overwrite true python3 ./train.py 

# to download the nsys result
# scp -r hzb@meepo4:/disk1/hzb/projects/pos/reorg/phoenixos/samples/cuda_resnet_train_single_node/resnet_50_client_output.nsys-rep ~/Desktop
