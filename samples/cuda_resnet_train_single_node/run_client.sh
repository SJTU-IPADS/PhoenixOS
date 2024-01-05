script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $script_dir
LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../remoting/cuda/cpu/:../../build LD_PRELOAD=../../remoting/cuda/cpu/cricket-client.so REMOTE_GPU_ADDRESS=10.66.10.1 python3 ./train.py 
