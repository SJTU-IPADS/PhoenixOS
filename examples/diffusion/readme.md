# PhoenixOS Sample: stable-diffusion-v1-4 Pre-training & Inference

## Environment

This example is fully tested under:

* `pytorch=1.13.0a0+git2263262`
* `transformers==4.30.0`
* `accelerate==0.20.1`
* `diffusers==0.9.0`
* `huggingface-hub==0.24.6`
* CUDA 11.3

We have already built a docker image for running this example (`phoenixos/pytorch:11.3-ubuntu20.04`), you can pull and run the container by:

```bash
cd [REPO PATH]
docker run -dit --gpu all --privileged  --ipc=host --network=host \
            -v .:/root --name phos_example phoenixos/pytorch:11.3-ubuntu20.04

docker exec -it phos_example /bin/bash

## To Run

After succesfully installed PhOS inside the container (See [Build and Install PhOS](https://github.com/SJTU-IPADS/PhoenixOS/tree/zhuobin/fix_cli?tab=readme-ov-file#i-build-and-install-phos)), you can run this example by:

1. Install the necessary python package

    ```bash
    pip3 uninstall transformers accelerate diffusers huggingface-hub
    pip3 install transformers==4.30.0 accelerate==0.20.1 diffusers==0.9.0 huggingface-hub==0.24.6
    ```

2. Start PhOS daemon by simply runing:

    ```bash
    # inside container
    pos_cli --start --target daemon

    # if you want to control number of CUDA devices, you can add the CUDA_VISIBLE_DEVICES environment variable
    # CUDA_VISIBLE_DEVICES=0 pos_cli --start --target daemon
    ```

3. Running the training script:

    ```bash
    # inside container
    cd /root/example/diffusion

    # train
    env $phos python3 ./inference.py 1 1
    ```

    Note that the first run would be longer, as PhOS would parse and instrument all registered .fatbin/.cubin.

4. To C/R using PhOS

    ```bash
    # pre-dump
    mkdir /root/ckpt
    pos_cli --pre-dump --dir /root/ckpt --pid [your program pid]

    # dump
    mkdir /root/ckpt
    pos_cli --dump --dir /root/ckpt --pid [your program pid]

    # restore
    pos_cli --restore --dir /root/ckpt
    ```

5. To C/R using [nvidia/cuda-checkpoint](https://github.com/NVIDIA/cuda-checkpoint) for comparison

    ```bash
    # clear old checkpoints, and mount tmpfs for storing in-memory ckpts
    bash run_nvcr_ckpt.sh -c

    # pre-dump
    bash run_nvcr_ckpt.sh -s false -g

    # dump
    bash run_nvcr_ckpt.sh -s true -g

    # restore
    bash run_nvcr_restore.sh -g
    ```
