if [ $# != 1 ] ; then
    echo "must provide container id"
    exit 1
fi

container_name=pos_svr_$1
sudo docker container stop $container_name
sudo docker container rm $container_name
