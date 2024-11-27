# Copyright 2024 The PhoenixOS Authors. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

#!/bin/bash

# >>>>>>>>>> common variables <<<<<<<<<<
script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

SUDO=sudo

# >>>>>>>>>> action configurations <<<<<<<<<<
container_id=0
mount=true
do_start=false
do_close=false
do_enter=false


print_usage() {
    echo ">>>>>>>>>> PhoenixOS Container Starter <<<<<<<<<<"
    echo "usage: $0 [-m <mount>] [-h] [-s] [-c] [-r] [-e] [-i <container_id>]"
    echo "  -m <mount>          whether to mount POS root directory into the container, default to be true"
    echo "  -s <container_id>   start the container"
    echo "  -c <container_id>   close the container"
    echo "  -e <container_id>   enter existing container"
    echo "  -h                  help message"
}


start_container() {
    if [ $container_id = 0 ] ; then
        echo "no container id provided"
        exit 1
    fi

    container_name=phos_torch_cu113_$container_id

    if [ $mount = false ] ; then
        $SUDO docker run --gpus all -dit                    \
                    -v $PWD/autogen:/root/autogen           \
                    -v $PWD/pos:/root/pos                   \
                    -v $PWD/examples:/root/examples         \
                    -v $PWD/utils:/root/utils               \
                    -v /data:/data                          \
                    --privileged --ipc=host --network=host  \
                    --name $container_name                  \
                    phoenixos/pytorch:11.3-ubuntu20.04
        cd $script_dir && cd .. && cd ..
        # note: we copy files except the autogen, pos, examples and utils folder, which we mount to the container
        while read line; do $SUDO docker cp $line $container_name:/root; done < <(find . -mindepth 1 -maxdepth 1 | grep -v "examples$" | grep -v  "utils$" | grep -v "pos$" | grep -v "autogen$")
    else
        cd $script_dir && cd .. && cd ..
        $SUDO docker run --gpus all -dit                    \
                    -v $PWD:/root                           \
                    -v /data:/data                          \
                    --privileged --network=host --ipc=host  \
                    --name $container_name                  \
                    phoenixos/pytorch:11.3-ubuntu20.04
    fi
    $SUDO docker exec -it $container_name bash
}


close_container() {
    if [ $container_id = 0 ] ; then
        echo "no container id provided"
        exit 1
    fi
    container_name=phos_torch_cu113_$container_id
    $SUDO docker container stop $container_name
    $SUDO docker container rm $container_name
}


enter_container() {
    container_name=phos_torch_cu113_$container_id
    $SUDO docker exec -it $container_name /bin/bash
}


while getopts ":m:hs:c:r:e:" opt; do
    case $opt in
        h)
            print_usage
            exit 0
            ;;
        m)
            if [ "$OPTARG" = "true" ]; then
                mount=true
            elif [ "$OPTARG" = "false" ]; then
                mount=false
            else
                echo "invalid arguments of -m, should be \"true\" or \"false\""
                exit 1
            fi
            ;;
        s)
            if [ $do_close = true ] || [ $do_enter = true ]; then
                echo "can't -s/-c/-r/-e at the same time"
                exit 1
            else
                if [ $OPTARG = 0 ]; then
                    echo "invalid arguments of -s, container id can't be zero"
                    exit 1
                else
                    container_id=$OPTARG
                    do_start=true
                fi
            fi
            ;;
        c)
            if [ $do_start = true ] || [ $do_enter = true ]; then
                echo "can't -s/-c/-r/-e at the same time"
                exit 1
            else
                if [ $OPTARG = 0 ]; then
                    echo "invalid arguments of -c, container id can't be zero"
                    exit 1
                else
                    container_id=$OPTARG
                    do_close=true
                fi
            fi
            ;;
        e)
            if [ $do_start = true ] || [ $do_close = true ]; then
                echo "can't -s/-c/-r/-e at the same time"
                exit 1
            else
                if [ $OPTARG = 0 ]; then
                    echo "invalid arguments of -e, container id can't be zero"
                    exit 1
                else
                    container_id=$OPTARG
                    do_enter=true
                fi
            fi
            ;;
    esac
done

if [ $do_start = true ]; then
    start_container
elif [ $do_close = true ]; then
    close_container
elif [ $do_enter = true ]; then
    enter_container
fi
