script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $script_dir
LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../build ../../remoting/cuda/cpu/cricket-rpc-server

# run sys, hasn't success yet
# nsys profile -o ./output -e LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../build --force-overwrite true ../../remoting/cuda/cpu/cricket-rpc-server