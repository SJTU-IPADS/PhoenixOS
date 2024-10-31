#!/bin/bash

# >>>>>>>>>> common variables <<<<<<<<<<
script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

SUDO=

# >>>>>>>>>> action configurations <<<<<<<<<<
container_id=0
mount=true
do_start=false
do_close=false
do_refresh=false
do_enter=false


print_usage() {
    echo ">>>>>>>>>> PhoenixOS Server <<<<<<<<<<"
    echo "usage: $0 [-m <mount>] [-h] [-s] [-c] [-r] [-e] [-i <container_id>]"
    echo "  -m <mount>          whether to mount POS root directory into the container, default to be true"
    echo "  -s <container_id>   start the server"
    echo "  -c <container_id>   close the server"
    echo "  -r <container_id>   refresh the server"
    echo "  -e <container_id>   enter existing server"
    echo "  -h                  help message"
}


start_server() {
    if [ $container_id = 0 ] ; then
        echo "no container id provided"
        exit 1
    fi

    container_name=pos_svr_$container_id
    ip_addr=10.66.10.$container_id

    if [ $mount = false ] ; then
        $SUDO docker run --gpus all -dit --privileged --network=pos_net \
                        --ip $ip_addr --ipc=host --name $container_name zobinhuang/pytorch:1.13.1-v2-criu-transformers
        cd $script_dir && cd .. && cd ..
        $SUDO docker cp . $container_name:/root
        $SUDO docker exec -it $container_name bash
    else
        cd $script_dir && cd .. && cd ..
        # $SUDO docker run --gpus all -dit -v $PWD:/root --privileged --network=pos_net \
        #                 --ip $ip_addr --ipc=host --name $container_name zobinhuang/pos_svr_base:11.3
        $SUDO docker run --gpus all -dit -v $PWD:/root --privileged --ipc=host --name $container_name zobinhuang/pytorch:1.13.1-v2-criu-transformers
        # $SUDO docker run -dit -v $PWD:/root --privileged --ipc=host --name $container_name zobinhuang/pos_svr_base:11.3
        $SUDO docker exec -it $container_name bash
    fi
}


close_server() {
    if [ $container_id = 0 ] ; then
        echo "no container id provided"
        exit 1
    fi
    container_name=pos_svr_$container_id
    $SUDO docker container stop $container_name
    $SUDO docker container rm $container_name
}


# refresh_server() {
#     if [ $container_id = 0 ] ; then
#         echo "no container id provided to start"
#         exit 1
#     fi
#     container_name=pos_svr_$container_id

#     # remove old content
#      docker exec -it $container_name /bin/bash -c 'cd /root && rm -rf ./*'

#     # copy new content
#     cd $script_dir && cd .. && cd ..
#      docker cp . $container_name:/root
# }


enter_server() {
    container_name=pos_svr_$container_id
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
            if [ $do_close = true ] || [ $do_refresh = true ] || [ $do_enter = true ]; then
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
            if [ $do_start = true ] || [ $do_refresh = true ] || [ $do_enter = true ]; then
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
        r)
            echo "refresh is forbidden!"
            exit 0
            ;;
            # if [ $do_start = true ] || [ $do_close = true ] || [ $do_enter = true ]; then
            #     echo "can't -s/-c/-r/-e at the same time"
            #     exit 1
            # else
            #     if [ $OPTARG = 0 ]; then
            #         echo "invalid arguments of -c, container id can't be zero"
            #         exit 1
            #     else
            #         container_id=$OPTARG
            #         do_refresh=true
            #     fi
            # fi
            # ;;
        e)
            if [ $do_start = true ] || [ $do_close = true ] || [ $do_refresh = true ]; then
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


# execution
if [ $do_start = true ]; then
    start_server
elif [ $do_close = true ]; then
    close_server
# elif [ $do_refresh = true ]; then
#     refresh_server
elif [ $do_enter = true ]; then
    enter_server
fi
