# PhoenixOS

<div align="center">
    <img src="./docs/pos_logo_small.png" width="200px" />
</div>

**PhoenixOS** is an OS service for checkpointing and restroing GPU process with transparency and efficiency.

## I. Build

TODO: give an architecture figure here (e.g., remoting module, POS)

### 1. Preparation docker image for specified target

TODO:

### 2. Install dependencies

```bash
apt-get install -y pkg-config
python3 -m pip install meson
python3 -m pip install ninja
```

### 3. Build From Source

```bash
bash build.sh -t cuda -c
bash build.sh -t cuda -j -u true
```

## II. Example

### 1. Resnet Training

### 2. FasterTransformer Serving

### III. Development Guidance

## IV. Stuff

```bash
alias proxy_on='export http_proxy=http://172.17.0.1:7890; export https_proxy=http://172.17.0.1:7890; export all_proxy=http://172.17.0.1:7890; export HTTP_PROXY=http://172.17.0.1:7890; export HTTPS_PROXY=http://172.17.0.1:7890; export ALL_PROXY=http://172.17.0.1:7890'
export CUDA_VISIBLE_DEVICES=6,7
```
