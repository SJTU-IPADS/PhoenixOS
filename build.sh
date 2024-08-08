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

# involve third-party library to the operation
involve_third_party=false

# build cuda target
build_cuda() {
  if [ $doclean = true ]; then
    echo "clean target: cuda"
    echo "[1] cleaning dependencies"
    if [ $involve_third_party = true ]; then

      echo "    [1.1] cleaning libclang"
      cd $script_dir
      cd third_party/libclang-static-build
      if [ -d "./build" ] || [ -d "./include" ] || [ -d "./lib" ] || [ -d "./share" ]; then
        rm -rf build include lib share
      fi
    else
      echo "    SKIPED"
    fi

    echo "[2] cleaning POS"
    cd $script_dir
    if [ -d "./build" ]; then
      rm -rf ./build
    fi
    rm $script_dir/pos_build.log
    rm /lib/x86_64-linux-gnu/libpos.so

    echo "[3] cleaning POS CLI"
    cd $script_dir
    cd pos/cli
    if [ -d "./build" ]; then
      rm -rf ./build
    fi
    rm $script_dir/pos_cli_build.log

    echo "[4] cleaning remoting framework (cricket)"
    cd $script_dir
    cd remoting/cuda/submodules/libtirpc
    make clean

    cd $script_dir
    cd remoting/cuda/cpu
    make clean
    rm --force core.*
    rm $script_dir/remoting_build.log

    echo "[5] cleaning unittest"
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
    echo "[1] building dependencies"
    if [ $involve_third_party = true ]; then
      echo "    [1.1] building libclang"
      cd $script_dir
      cd third_party/libclang-static-build
      if [ ! -d "./build" ]; then
        mkdir build && cd build
        cmake .. -DCMAKE_INSTALL_PREFIX=..
        make install -j
      fi
      # we need to move the dynamic libraries to the system path, or we can't execute the final executable due to loss .so
      cp $script_dir/third_party/libclang-static-build/lib/*.so* /lib/x86_64-linux-gnu/
      cp $script_dir/third_party/libclang-static-build/lib/*.a* /lib/x86_64-linux-gnu/
    else
      echo "    SKIPED"
    fi

    echo "[2] building POS"
    cd $script_dir
    if [ ! -d "./build" ]; then
      meson build
      status=$?
      if [ $status -ne 0 ]; then
        echo "failed to meson POS project"
        exit 1
      fi
    fi
    cd build
    ninja clean
    ninja &>$script_dir/pos_build.log
    status=$?
    if [ $status -ne 0 ]; then
      echo "failed to build POS project"
      grep -n -A 5 'error' $script_dir/pos_build.log | awk '{print} NR%2==0 {print ""}'
      exit 1
    fi
    cp $script_dir/build/*.so /lib/x86_64-linux-gnu/

    echo "[3] building POS CLI"
    cd $script_dir
    cd pos/cli
    if [ ! -d "./build" ]; then
      mkdir build
    fi
    cd build && rm -rf ./*
    cmake ..
    status=$?
    if [ $status -ne 0 ]; then
      echo "failed to cmake POS CLI"
      exit 1
    fi

    make -j &>$script_dir/pos_cli_build.log
    status=$?
    if [ $status -ne 0 ]; then
      echo "failed to build POS CLI project"
      grep -n 'error' $script_dir/pos_cli_build.log | awk '{print} NR%2==0 {print ""}'
      exit 1
    fi

    cp ../bin/* /usr/local/bin

    echo "[3] building remoting framework (cricket)"
    export POS_ENABLE=true
    cd $script_dir
    cd remoting/cuda
    make libtirpc -j
    cd cpu
    if [ $multithread_build = true ]; then
      LOG=INFO make cricket-rpc-server cricket-client.so -j &>$script_dir/remoting_build.log
    else
      LOG=INFO make cricket-rpc-server cricket-client.so &>$script_dir/remoting_build.log
    fi
    status=$?
    if [ $status -ne 0 ]; then
      echo "failed to build remoting framework"
      grep -n 'error' $script_dir/remoting_build.log | awk '{print} NR%2==0 {print ""}'
      exit 1
    fi

    echo "[4] building unittest"
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
      nohup bash -c 'LD_LIBRARY_PATH=../submodules/libtirpc/install/lib:../../../build ./cricket-rpc-server -n test' &
      server_pid=$!

      # raise per-api unittest client
      sleep 3
      cd $script_dir
      cd unittest/cuda/build
      LD_LIBRARY_PATH=../../../remoting/cuda/submodules/libtirpc/install/lib/:../../../remoting/cuda/cpu/:../../../build LD_PRELOAD=../../../remoting/cuda/cpu/cricket-client.so REMOTE_GPU_ADDRESS=10.66.10.1 ../bin/per_api_test
      client_retval=$?
      kill -SIGINT $server_pid

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
  echo "  -3              involve third-party library"
}

# parse command line options
while getopts ":t:hcju:3" opt; do
  case $opt in
  t)
    target=$OPTARG
    ;;
  h)
    print_usage
    exit 0
    ;;
  3)
    involve_third_party=true
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
