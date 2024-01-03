# Migration Sample

## Run

1. create network

```bash
sudo docker network create --driver bridge --subnet 10.66.0.0/16 --gateway 10.66.0.1 pos_net

# to remove
sudo docker network rm pos_net
```

2. raise all necessary containers

(1) build base image

```bash
sudo docker build -t pos_svr_base:11.3 -f ./dockerfiles/pos_svr_base_cuda_11_3.Dockerfile .
```

(2) run servers

```bash
bash ./svr.sh -s 1 -m false  # change the parameter to be 2 to start the second sever

# inside container
cd /root
bash build.sh -t cuda -c
bash build.sh -t cuda -j -u true
```

Other:

```bash
# to stop server
bash ./svr.sh -c 1

# to enter the existing server
bash ./svr.sh -e 1

# to refresh the content inside the server
bash ./svr.sh -r 1
```

(3) run central service

```bash

```

(4) run client

```bash
bash ./clnt.sh -s 1 -i zobinhuang/pytorch:1.13.1-devel-for-pos -m false
```

Other:

```bash
# to stop client
bash ./clnt.sh -c 1

# to enter the existing client
bash ./svr.sh -e 1
```

3. migration operation
