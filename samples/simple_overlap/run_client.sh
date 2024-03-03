script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
cd $script_dir
LD_LIBRARY_PATH=../../remoting/cuda/submodules/libtirpc/install/lib:../../remoting/cuda/cpu/:../../build LD_PRELOAD=../../remoting/cuda/cpu/cricket-client.so REMOTE_GPU_ADDRESS=10.66.10.1 ./bin/main


# nsys for client behaviour:
# nsys profile -t cuda,nvtx -o ./outout --force-overwrite true ./bin/main
# nsys profile -t cuda,nvtx -o ./outout --export json --force-overwrite true ./bin/main

# to download the nsys result
# scp -r hzb@meepo4:/disk1/hzb/projects/pos/reorg/phoenixos/samples/simple_overlap/outout.nsys-rep ~/Desktop
