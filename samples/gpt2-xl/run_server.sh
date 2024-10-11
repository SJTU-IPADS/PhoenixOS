script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $script_dir
LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../build ../../remoting/cuda/cpu/cricket-rpc-server -n gpt2_xl -k ./gpt2_xl_kernel_metas.txt

# run with restore
# LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../build ../../remoting/cuda/cpu/cricket-rpc-server -n gpt2_xl -c ./gpt2_xl_checkpoints_0.bat
# LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../build gdb --args ../../remoting/cuda/cpu/cricket-rpc-server -n gpt2_xl -c ./gpt2_xl_checkpoints_0.bat

# run with gdb
# LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../build gdb --args ../../remoting/cuda/cpu/cricket-rpc-server -n gpt2_xl -k ./gpt2_xl_kernel_metas.txt

# run sys, hasn't success yet
# nsys profile -t cuda,nvtx -o ./output -e LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../build --force-overwrite true ../../remoting/cuda/cpu/cricket-rpc-server -n gpt2_xl -k ./gpt2_xl_kernel_metas.txt

# to download the nsys result
# scp -r hzb@meepo4:/disk1/hzb/projects/pos/reorg/phoenixos/samples/cuda_resnet_train_single_node/output.nsys-rep ~/Desktop
