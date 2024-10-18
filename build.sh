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
    log ">> clean target: cuda..."
    log ">>>> [1] cleaning dependencies..."
    if [ $involve_third_party = true ]; then
      log ">>>>>> [1.1] cleaning libclang..."
      cd $script_dir
      cd third_party/libclang-static-build
      if [ -d "./build" ] || [ -d "./include" ] || [ -d "./lib" ] || [ -d "./share" ]; then
        rm -rf build include lib share
      fi
    else
      log ">>>> SKIPED"
    fi

    log ">>>> [2] cleaning POS..."
    log ">>>>>> [2.1] cleaning patcher component..."
    cd $script_dir/pos/cuda_impl/patcher
    rm -rf ./build
    rm /lib/x86_64-linux-gnu/libpatcher.a
    rm $script_dir/pos/cuda_impl/patcher/patcher.h

    log ">>>>>> [2.2] cleaning core..."
    cd $script_dir
    if [ -d "./build" ]; then
      rm -rf ./build
    fi
    rm $script_dir/pos_build.log
    rm /lib/x86_64-linux-gnu/libpos.so

    log ">>>> [3] cleaning POS CLI..."
    cd $script_dir
    cd pos/cli
    if [ -d "./build" ]; then
      rm -rf ./build
    fi
    rm $script_dir/pos_cli_build.log

    log ">>>> [4] cleaning remoting framework (cricket)..."
    cd $script_dir
    cd remoting/cuda/submodules/libtirpc
    make clean

    cd $script_dir
    cd remoting/cuda/cpu
    make clean
    rm --force core.*
    rm $script_dir/remoting_build.log

    log ">>>> [5] cleaning unittest..."
    cd $script_dir
    cd unittest/cuda
    if [ -d "./build" ]; then
      rm -rf build
    fi
    if [ -d "./bin" ]; then
      rm -rf bin
    fi
  else
    log ">> build target: cuda..."
    log ">>>> [1] building dependencies..."
    if [ $involve_third_party = true ]; then
      log ">>>>>> [1.1] building libclang..."
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
      log ">>>>>> SKIPED"
    fi

    log ">>>> [2] building POS..."
    log ">>>>>> [2.1] building patcher component..."
    cd $script_dir/pos/cuda_impl/patcher
    if [ -d "./build" ]; then
      rm -rf build
    fi
    mkdir build && cd build
    cmake .. && make -j
    status=$?
    if [ $status -ne 0 ]; then
      error "failed to build patcher component"
    fi
    if [ -e "./libpatcher.a" ] && [ -e "./patcher.h" ]; then
        cp ./release/libpatcher.a /lib/x86_64-linux-gnu/
        cp ./patcher.h $script_dir/pos/cuda_impl/patcher
    else
        error_f "failed to find %s under %s, is compilation success?"   \
                "./libpatcher.a, ./patcher.h"                           \
                "$script_dir/pos/cuda_impl/patcher/build"
    fi

    log ">>>>>> [2.2] building core..."
    cd $script_dir
    if [ ! -d "./build" ]; then
      meson build
      status=$?
      if [ $status -ne 0 ]; then
        error "failed to meson POS project"
      fi
    fi
    cd build
    ninja clean
    ninja &>$script_dir/pos_build.log
    status=$?
    if [ $status -ne 0 ]; then
      grep -n -A 5 'error' $script_dir/pos_build.log | awk '{print} NR%2==0 {print ""}'
      error "failed to build POS core, error log printed"
    fi
    cp $script_dir/build/*.so /lib/x86_64-linux-gnu/

    echo ">>>>>> [3] building POS CLI..."
    cd $script_dir
    cd pos/cli
    if [ ! -d "./build" ]; then
      mkdir build
    fi
    cd build && rm -rf ./*
    cmake ..
    status=$?
    if [ $status -ne 0 ]; then
      error "failed to cmake POS CLI"
    fi

    make -j &>$script_dir/pos_cli_build.log
    status=$?
    if [ $status -ne 0 ]; then
      grep -n 'error' $script_dir/pos_cli_build.log | awk '{print} NR%2==0 {print ""}'
      error "failed to build POS CLI project, error log printed"
    fi

    cp ../bin/* /usr/local/bin

    log ">>>> [3] building remoting framework (cricket)"
    export POS_ENABLE=true
    cd $script_dir
    cd remoting/cuda
    make libtirpc -j
    cd cpu
    if [ $multithread_build = true ]; then
      LOG=DEBUG make cricket-rpc-server cricket-client.so -j &>$script_dir/remoting_build.log
    else
      LOG=DEBUG make cricket-rpc-server cricket-client.so &>$script_dir/remoting_build.log
    fi
    status=$?
    if [ $status -ne 0 ]; then
      grep -n 'error' $script_dir/remoting_build.log | awk '{print} NR%2==0 {print ""}'
      error "failed to build remoting framework, error log printed"
    fi

    log ">>>> [4] building unittest"
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
      log ">>>>>> [4.1] run per-api unittest"
      # raise POS server
      cd $script_dir
      cd remoting/cuda/cpu
      nohup bash -c 'LD_LIBRARY_PATH=../submodules/libtirpc/install/lib:../../../lib ./cricket-rpc-server -n test' &
      server_pid=$!

      # raise per-api unittest client
      sleep 3
      cd $script_dir
      cd unittest/cuda/build
      rm client_exist.txt
      LD_LIBRARY_PATH=../../../remoting/cuda/submodules/libtirpc/install/lib/:../../../remoting/cuda/cpu/:../../../lib LD_PRELOAD=../../../remoting/cuda/cpu/cricket-client.so REMOTE_GPU_ADDRESS=127.0.0.1 ../bin/per_api_test
      client_retval=$?
      kill -SIGINT $server_pid

      if [ $client_retval -eq 0 ]; then
        log "Per-API unittest passed!"
        cd $script_dir
        cd remoting/cuda/cpu
        rm ./nohup.out
      else
        cd $script_dir
        cd remoting/cuda/cpu
        cat ./nohup.out
        rm ./nohup.out
        error "Per-API unittest failed! server log printed"
      fi

      log ">>>>>> [4.2] run hidden-api unittest (TODO)..."
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
        error "invalid arguments of -u, should be \"true\" or \"false\""
        fi
        ;;
    c)
        doclean=true
        ;;
    j)
        multithread_build=true
        ;;
    \?)
        error "invalid target: -$OPTARG" >&2
        ;;
    :)
        error "option -$OPTARG require extra parameter (options: cuda)" >&2
        ;;
    esac
done

# execution
if [ "$target" = "cuda" ]; then
    util_install_common "git" "git"

    . "$HOME/.cargo/env"
    util_check_dep "cargo" "cargo"
    if [[ $util_check_dep_retval -eq 0 ]]; then
        error "no cargo installed"
    fi
    build_cuda
else
    error "invalid target: $target" >&2
fi
