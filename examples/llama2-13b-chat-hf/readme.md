# PhoenixOS Sample: llama2-13b-chat Inference

## Environment

This example is fully tested under:

* `pytorch=1.13.0a0+git2263262`
* `transformers==4.30.0`
* CUDA 11.3

We have already built a docker image for running this example (`phoenixos/pytorch:11.3-ubuntu20.04`), you can pull and run the container by:

```bash
cd [REPO PATH]
docker run -dit --gpu all --privileged  --ipc=host --network=host \
            -v .:/root --name phos_example phoenixos/pytorch:11.3-ubuntu20.04

docker exec -it phos_example /bin/bash
```

## Run

After succesfully installed PhOS inside the container (See [Build and Install PhOS](https://github.com/SJTU-IPADS/PhoenixOS/tree/zhuobin/fix_cli?tab=readme-ov-file#i-build-and-install-phos)), you can run this example by:

1. Install the `transformers` python package

    ```bash
    pip3 install transformers==4.30.0
    ```

2. You need to download model parameter and tokenizer, simply run the following script:

    ```bash
    export HF_TOKEN=your huggingface token
    python3 ./download.py
    ```


3. Start PhOS daemon by simply runing:

    ```bash
    # inside container
    pos_cli --start --target daemon
    # CUDA_VISIBLE_DEVICES=0 pos_cli --start --target daemon
    ```

4. Running the training / inference script:

    ```bash
    # inside container
    cd /root/example/resnet

    # train
    env $phos python3 ./inference.py
    ```

    Note that the first run would be longer, as PhOS would parse and instrument all registered .fatbin/.cubin.

5. To C/R using PhOS

    ```bash
    # checkpoint
    mkdir /root/ckpt
    pos_cli --dump --dir /root/ckpt --pid [your program pid]

    # restore
    pos_cli --restore --dir /root/ckpt
    ```

6. To C/R using [nvidia/cuda-checkpoint](https://github.com/NVIDIA/cuda-checkpoint) for comparison

    ```bash
    # checkpoint
    bash run_nvcr_ckpt.sh -s true -g

    # restore
    bash run_nvcr_restore.sh -g
    ```
