#!/bin/bash

# >>>>>>>>>> common variables <<<<<<<<<<
script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

# >>>>>>>>>> build configurations <<<<<<<<<<
container_id=0
used_image=
mount=true
do_start=false
do_close=false
do_refresh=false
do_enter=false

print_usage() {
    echo ">>>>>>>>>> PhoenixOS Client <<<<<<<<<<"
    echo "usage: $0 [-m <mount>] [-h] [-s] [-c] [-r] [-e] [-i <container_id>]"
    echo "  -m <mount>          whether to mount POS root directory into the container, default to be true"
    echo "  -i <image_name>     the name of the used client docker image"
    echo "  -s <container_id>   start the client"
    echo "  -c <container_id>   close the client"
    echo "  -e <container_id>   enter existing client"
    echo "  -r <container_id>   refresh the client"
    echo "  -h                  help message"
}

start_client() {
    if [ $container_id = 0 ] ; then
        echo "no container id provided"
        exit 1
    fi

    if [ ! $used_image ] ; then
        echo "no image name provided!"
        exit 1
    fi

    container_name=pos_clnt_$container_id
    ip_addr=10.66.20.$container_id

    if [ $mount = false ] ; then
        cd $script_dir && cd .. && cd ..
        sudo docker run --gpus all -dit -v $PWD/samples:/root/samples -v $PWD/utils:/root/utils --privileged --network=pos_net \
                        --ip $ip_addr --ipc=host --name $container_name $used_image
        
        # note: we copy files except the samples and utils folder, which we mount to the container
        while read line; do sudo docker cp $line $container_name:/root; done < <(find . -mindepth 1 -maxdepth 1 | grep -v "samples$" | grep -v  "utils$")
        sudo docker exec -it $container_name bash
    else
        cd $script_dir && cd .. && cd ..
        sudo docker run --gpus all -dit -v $PWD:/root --privileged --network=pos_net \
                        --ip $ip_addr --ipc=host --name $container_name $used_image
        sudo docker exec -it $container_name bash
    fi
}

close_client() {
    if [ $container_id = 0 ] ; then
        echo "no container id provided"
        exit 1
    fi
    container_name=pos_clnt_$container_id
    sudo docker container stop $container_name
    sudo docker container rm $container_name
}

enter_client() {
    container_name=pos_clnt_$container_id
    sudo docker exec -it $container_name bash
}

while getopts ":m:hi:s:c:r:e:" opt; do
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
        i)
            used_image=$OPTARG
            ;;
    esac
done

# execution
if [ $do_start = true ]; then
    start_client
elif [ $do_close = true ]; then
    close_client
# elif [ $do_refresh = true ]; then
#     refresh_client
elif [ $do_enter = true ]; then
    enter_client
fi
