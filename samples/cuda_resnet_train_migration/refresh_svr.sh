if [ $# != 1 ] ; then
    echo "must provide container id"
    exit 1
fi

script_dir=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

container_name=pos_svr_$1

# remove old content
sudo docker exec -it $container_name /bin/bash -c 'cd /root && rm -rf ./*'

# copy new content
cd $script_dir && cd .. && cd ..
sudo docker cp . $container_name:/root
