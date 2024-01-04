#!/bin/bash

# >>>>>>>>>> common variables <<<<<<<<<<
script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

# >>>>>>>>>> build configurations <<<<<<<<<<
# build target (options: cuda)
target="cuda"

# clean
doclean=false

# enable multi-thrading build
multithread_build=false

# run unittest after building
run_unit_test=true

# build cuda target
build_cuda() {
    if [ $doclean = true ]; then
        echo "clean target: cuda"
        echo "[1] cleaning POS"
            cd $script_dir
            if [ -d "./build" ]; then
                rm -rf ./build
            fi
        echo "[2] cleaning remoting framework (cricket)"
            cd $script_dir
            cd remoting/cuda/submodules/libtirpc
            make clean
            
            cd $script_dir
            cd remoting/cuda/cpu
            make clean
        echo "[3] cleaning unittest"
            cd $script_dir
            cd unittest/cuda
            if [ -d "./build" ]; then
                rm -rf build
            fi
            if [ -d "./bin" ]; then
                rm -rf bin
            fi
    else
        echo "build target: cuda"
        echo "[1] building POS"
            cd $script_dir
            if [ ! -d "./build" ]; then
                meson build
            fi
            cd build
            ninja clean
            ninja
        echo "[2] building remoting framework (cricket)"
            cd $script_dir
            cd remoting/cuda
            make libtirpc -j
            cd cpu
            if [ $multithread_build = true ]; then
                LOG=INFO make cricket-rpc-server cricket-client.so -j
            else
                LOG=INFO make cricket-rpc-server cricket-client.so
            fi
        echo "[3] building unittest"
            cd $script_dir
            cd unittest/cuda
            if [ -d "./build" ]; then
                rm -rf build
            fi
            if [ -d "./bin" ]; then
                rm -rf bin
            fi
            mkdir build
            cd build
            cmake ..
            make -j

        if [ $run_unit_test = true ]; then
                echo "[3.1] run per-api unittest"
                    # raise POS server
                    cd $script_dir
                    cd remoting/cuda/cpu
                    nohup bash -c 'LD_LIBRARY_PATH=../submodules/libtirpc/install/lib:../../../build ./cricket-rpc-server' &
                    server_pid=$!

                    # raise per-api unittest client
                    sleep 3
                    cd $script_dir
                    cd unittest/cuda/build
                    LD_LIBRARY_PATH=../../../remoting/cuda/submodules/libtirpc/install/lib/:../../../remoting/cuda/cpu/:../../../build LD_PRELOAD=../../../remoting/cuda/cpu/cricket-client.so REMOTE_GPU_ADDRESS=127.0.0.1 ../bin/per_api_test
                    client_retval=$?
                    kill $server_pid

                    if [ $client_retval -eq 0 ]; then
                        echo "Per-API unittest passed!"
                        cd $script_dir
                        cd remoting/cuda/cpu
                        rm ./nohup.out
                    else
                        cd $script_dir
                        cd remoting/cuda/cpu
                        cat ./nohup.out
                        rm ./nohup.out
                        echo "Per-API unittest failed! server log printed"
                        exit 1
                    fi

                echo "[3.2] run hidden-api unittest (TODO)"
        fi
    fi
}


# print helping
print_usage() {
    echo ">>>>>>>>>> PhoenixOS build routine <<<<<<<<<<"
    echo "usage: $0 [-t <target>] [-h]"
    echo "  -t <target>     specified build target (options: cuda), default to be cuda"
    echo "  -u <enable>     run unittest after building to verify correctness (options: true, false), default to be false"
    echo "  -j              multi-threading build"
    echo "  -c              clean previously built assets"
    echo "  -h              help message"
}


# parse command line options
while getopts ":t:hcju:" opt; do
  case $opt in
    t)
        target=$OPTARG
        ;;
    h)
        print_usage
        exit 0
        ;;
    u)
        if [ "$OPTARG" = "true" ]; then
            run_unit_test=true
        elif [ "$OPTARG" = "false" ]; then
            run_unit_test=false
        else
            echo "invalid arguments of -u, should be \"true\" or \"false\""
            exit 1
        fi
        ;;
    c)
        doclean=true
        ;;
    j)
        multithread_build=true
        ;;
    \?)
        echo "invalid target: -$OPTARG" >&2
        exit 1
        ;;
    :)
        echo "option -$OPTARG require extra parameter (options: cuda)" >&2
        exit 1
        ;;
  esac
done


# execution
if [ "$target" = "cuda" ]; then
  build_cuda
else
  echo "invalid target: $target" >&2
  exit 1
fi
