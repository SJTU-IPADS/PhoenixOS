if [ $# != 1 ] ; then
    echo "must provide container id"
    exit 1
fi

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

container_name=pos_svr_$1
sudo docker run --gpus all -dit --privileged --network=pos_net --ipc=host --name $container_name pos_svr_base:11.3

cd $script_dir && cd .. && cd ..
sudo docker cp . $container_name:/root
sudo docker exec -it $container_name bash
