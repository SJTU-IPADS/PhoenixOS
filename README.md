# PhoenixOS

**PhoenixOS** is an generic framework for transparently checkpointing / restoring XPU state.

TODO: give effect of fast rasing container here

TODO: give effect of training migration here

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

## IV. Roadmap

[] (Jan.3) Fast checkpoint of all stateful resources
    [*] develop performance code to measure checkpoint performance
    - verify stream behaviour
    - develop overlap version
[] (Jan.2) Develop container environment
[] (Jan.2) Develop central node & redis (using golang)
[] (Jan.2) Develop communication channel across multiple POS servers

[] Develop client-server switch of POS and cricket
[] Develop dumping checkpoint state to memory / file
[] Try migration development (i.e., restore mechanism)

```bash
alias proxy_on='export http_proxy=http://172.17.0.1:7890; export https_proxy=http://172.17.0.1:7890; export all_proxy=http://172.17.0.1:7890; export HTTP_PROXY=http://172.17.0.1:7890; export HTTPS_PROXY=http://172.17.0.1:7890; export ALL_PROXY=http://172.17.0.1:7890'
export CUDA_VISIBLE_DEVICES=6,7
```