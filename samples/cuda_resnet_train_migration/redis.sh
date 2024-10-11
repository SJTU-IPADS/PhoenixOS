#!/bin/bash

# >>>>>>>>>> common variables <<<<<<<<<<
script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)


# >>>>>>>>>> action configurations <<<<<<<<<<
container_id=0
do_start=false
do_close=false

print_usage() {
    echo ">>>>>>>>>> PhoenixOS RedisDB <<<<<<<<<<"
    echo "usage: $0 [-h] [-s <container_id>] [-c <container_id>]"
    echo "  -s <container_id>   start the redis db"
    echo "  -c <container_id>   close the redis db"
}


start_server() {
    if [ $container_id = 0 ] ; then
        echo "no container id provided"
        exit 1
    fi

    container_name=pos_redis_$container_id
    ip_addr=10.66.30.$container_id
    sudo docker run -dit --privileged --network=pos_net \
            --ip $ip_addr --ipc=host --name $container_name redis:6.2
}


close_server() {
    if [ $container_id = 0 ] ; then
        echo "no container id provided"
        exit 1
    fi
    container_name=pos_redis_$container_id
    sudo docker container stop $container_name
    sudo docker container rm $container_name
}


while getopts ":hs:c:" opt; do
    case $opt in
        h)
            print_usage
            exit 0
            ;;
        s)
            if [ $do_close = true ]; then
                echo "can't -s/-c at the same time"
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
            if [ $do_start = true ]; then
                echo "can't -s/-c at the same time"
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
    esac
done

# execution
if [ $do_start = true ]; then
    start_server
elif [ $do_close = true ]; then
    close_server
fi
