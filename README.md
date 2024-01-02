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
bash build -t cuda -c
bash build -t cuda -j -u true
```

## II. Example

### 1. Resnet Training

### 2. FasterTransformer Serving

### III. Development Guidance

## IV. Roadmap

[] (Jan.2) Fast checkpoint of all stateful resources
[] (Jan.2) Develop central node (using golang)
[] Develop communication channel across multiple POS servers
[] Develop client-server switch of POS and cricket
[] Develop dumping checkpoint state to memory / file
[] Try migration development (i.e., restore mechanism)