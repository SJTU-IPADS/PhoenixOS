# PhoenixOS

![build passing](https://img.shields.io/badge/build-passed-green)
![build passing](https://img.shields.io/badge/supported-nVIDIA-blue)
![build passing](https://img.shields.io/badge/TODO-ROCm-lightgrey)
![build passing](https://img.shields.io/badge/TODO-Ascend-lightgrey)
![doc](https://img.shields.io/badge/docs-green)

<div style="display:flex;">

<div align="center" style="margin-right:10px;">
    <img src="./docs/docs/source/_static/images/home/pos_logo.gif" width="280px" />
</div>

**PhoenixOS** (*PhOS*) is an OS-level GPU C/R system. It can transparently checkpoint or restore processes that use the GPU, without requiring any cooperation from the application, a key feature required by modern systems like the cloud. Moreover, *PhOS* is the first OS-level C/R system that can concurrently execute C/R with the application execution. *PhOS* is now supporting CUDA platform.

</div>

## I. Build *PhOS* From Source

1. **[Start Container]**
    *PhOS* can be built and installed on official image from different vendors.

    For example, for running *PhOS* for CUDA 12.1,
    one can build on official CUDA images
    (e.g., [`nvidia/cuda/12.1.1-cudnn8-devel-ubuntu20.04`](https://hub.docker.com/layers/nvidia/cuda/12.1.1-cudnn8-devel-ubuntu20.04/images/sha256-f676f5b29377e942b533ed13e554cc54aecf853b598ae55f6b67e20adcf81f23))

    ```bash
    # start container
    docker run -dit --gpus all -v.:/root --name phos nvidia/cuda/12.1.1-cudnn8-devel-ubuntu20.04

    # enter container
    docker exec -it phos /bin/bash
    ```

2. **[Build]**
    Building *PhOS* is simple!

    *PhOS* provides a convinient build system as it contains multiple components 
    (e.g., autogen, daemon, client-side hijacker, unit-testing, CLI etc.),
    simply run the build script in the container would works:

    ```bash
    # inside container
    cd /root/scripts/build_scripts
    bash build.sh
    ```

## II. Running *PhOS* Samples

**TODO**

## III. How *PhOS* Works?

<div align="center">
    <img src="./docs/docs/source/_static/images/pos_mechanism.jpg" width="80%" />
</div>

### Paper

If you use *PhOS* in your research, please cite our paper:

```bibtex
@article{huang2024parallelgpuos,
  title={PARALLELGPUOS: A Concurrent OS-level GPU Checkpoint and Restore System using Validated Speculation},
  author={Huang, Zhuobin and Wei, Xingda and Hao, Yingyi and Chen, Rong and Han, Mingcong and Gu, Jinyu and Chen, Haibo},
  journal={arXiv preprint arXiv:2405.12079},
  year={2024}
}
```

