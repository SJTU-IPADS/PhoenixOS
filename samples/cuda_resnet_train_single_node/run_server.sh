script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $script_dir
LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../lib gdb ../../remoting/cuda/cpu/cricket-rpc-server

# echo '0' | sudo tee /proc/PID_OF_PROCESS/coredump_filter

rm $script_dir/core.*

# run with restore
# LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../build ../../remoting/cuda/cpu/cricket-rpc-server -n resnet -c ./resnet_checkpoints_0.bat
# LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../build gdb --args ../../remoting/cuda/cpu/cricket-rpc-server -n resnet -c ./resnet_checkpoints_0.bat

# run with gdb
# LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../build gdb --args ../../remoting/cuda/cpu/cricket-rpc-server -n resnet -k ./resnet_kernel_metas.txt

# run sys, hasn't success yet
# nsys profile -t cuda,nvtx -o ./output -e LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../build --force-overwrite true ../../remoting/cuda/cpu/cricket-rpc-server -n resnet -k ./resnet_kernel_metas.txt

# to download the nsys result
# scp -r hzb@meepo4:/disk1/hzb/projects/pos/reorg/phoenixos/samples/cuda_resnet_train_single_node/output.nsys-rep ~/Desktop

# scp -r hzb@a100pjlab:/nvme/hzb/projects/phoenixos/samples/cuda_resnet_train_single_node/output.nsys-rep ~/Desktop/migration.nsys-rep
