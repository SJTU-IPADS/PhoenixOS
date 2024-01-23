script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $script_dir
LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../build ../../remoting/cuda/cpu/cricket-rpc-server -n custom_kernel -k ./custom_kernel.txt

# run with gdb
# LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../build gdb --args ../../remoting/cuda/cpu/cricket-rpc-server -n custom_kernel -k ./custom_kernel.txt

# run sys, hasn't success yet
# nsys profile -t cuda,nvtx -o ./output -e LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../build --force-overwrite true ../../remoting/cuda/cpu/cricket-rpc-server -n custom_kernel -k ./custom_kernel.txt

# to download the nsys result
# scp -r hzb@meepo4:/disk1/hzb/projects/pos/reorg/phoenixos/samples/cuda_resnet_train_single_node/output.nsys-rep ~/Desktop
