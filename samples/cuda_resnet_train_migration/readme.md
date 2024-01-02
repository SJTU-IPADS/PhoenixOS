# Migration Sample

## Run

1. create network

```bash
sudo docker network create --driver bridge --subnet 192.168.20.0/24 --gateway 192.168.20.1 pos_net
```

2. raise all necessary containers

(1) build base image

```bash
sudo docker build -t pos_svr_base:11.3 -f ./dockerfiles/pos_svr_base_cuda_11_3.Dockerfile .
```

(2) run servers

```bash
# TODO: we need to expose necessary port!
bash ./start_svr.sh 1   # change the parameter to be 2 to start the second sever

# inside container
cd /root
bash build.sh -t cuda -c
bash build.sh -t cuda -j -u true
```

```bash
# to stop server
bash ./stop_svr.sh 1

# to enter the existing server
bash ./enter_svr.sh 1

# to refresh the content inside the server
bash ./refresh_svr.sh 1
```

(3) run redis container


(4) run central service


(5) run client

3. migration operation
