# PhoenixOS (PhOS)
[![slack](https://img.shields.io/badge/CUDA-supported-brightgreen.svg?logo=nvidia)](https://phoenixos-docs.readthedocs-hosted.com/en/latest/cuda_gsg/index.html)
[![slack](https://img.shields.io/badge/ROCm-Developing-lightgrey.svg?logo=amd)]()
[![slack](https://img.shields.io/badge/Ascend-Developing-lightgrey.svg?logo=huawei)]()
[![slack](https://img.shields.io/badge/slack-PhoenixOS-brightgreen.svg?logo=slack)](https://phoenixoshq.slack.com/archives/C07V2QWVB8Q)
[![slack](https://img.shields.io/badge/Docs-passed-brightgreen.svg?logo=readthedocs)](https://phoenixos-docs.readthedocs-hosted.com/en/latest/index.html)

<div align="center">
    <img src="./docs/docs/source/_static/images/home/logo.jpg" height="200px" />
</div>

<div>
    <p>
    <b>PhoenixOS</b> (<i>PhOS</i>) is an OS-level GPU checkpoint/restore (C/R) system. It can <b>transparently</b> C/R processes that use the GPU, without requiring any cooperation from the application, a key feature required by modern systems like the cloud. Most importantly, <i>PhOS</i> is the first OS-level C/R system that can <b>concurrently execute C/R without stopping the execution of application</b>.
    <p>
    Note that <i>PhOS</i> is aimming to be a generic framework that takes no assumption on underlying hardware, by providing a set of interfaces which should be implemented by different hardware platforms. We currently provide the C/R implementation on CUDA platform, support for ROCm and Ascend are under development.
    <div style="margin:20px 0px;">
        <b>📢 <i>PhOS</i> is currently under heavy development. If you're interested in contributing to this project, please join our <a href="https://phoenixoshq.slack.com/archives/C07V2QWVB8Q">slack workspace</a>.</b>
    </div>
    <div style="padding: 0px 10px; border: 1px solid grey">
        <p>
        <h3 style="margin:0px; margin-bottom:5px;">Latest News</h3>
        <ul>
            <li>
                <p style="margin:0px; margin-bottom:5px;">
                    <b>[Nov.4 2024]</b> <i>PhOS</i> is open sourced 🎉 [<a href="https://github.com/PhoenixOS-IPADS/PhoenixOS">Repo</a>] [<a href="http://phoenixos-docs.readthedocs-hosted.com/">Documentations</a>] [<a href="https://arxiv.org/abs/2405.12079">Paper</a>]
                </p>
                <p style="margin:0px; margin-bottom:5px;">
                    👉 <i>PhOS</i> is currently fully supporting continuous checkpoint and fast restore
                </p>
                <p style="margin:0px; margin-bottom:5px;">
                    👉 We will soon release codes for live migration and multi-GPU support :)
                </p>                
            </li>
        </ul>
    </div>
</div>


## I. What *PhOS* Does?

## II. Build *PhOS* From Source

1. **[Start Container]**
    *PhOS* can be built and installed on official image from different vendors.

    For example, for running *PhOS* for CUDA 11.3,
    one can build on official CUDA images
    (e.g., [`nvidia/cuda:11.3.1-cudnn8-devel-ubuntu20.04`](https://hub.docker.com/layers/nvidia/cuda/11.3.1-cudnn8-devel-ubuntu20.04/images/sha256-459c130c94363099b02706b9b25d9fe5822ea233203ce9fbf8dfd276a55e7e95))


    ```bash
    # start container
    docker run -dit --gpus all -v.:/root --name phos nvidia/cuda:11.3.1-cudnn8-devel-ubuntu20.04

    # enter container
    docker exec -it phos /bin/bash
    ```

    > **Dependencies Declaration**
    > 1. PhOS require libc6 >= 2.29 for compiling CRIU from source;
    > 2. Currently *PhOS* is currently fully tested under CUDA 11.3, we will support other latest CUDA version soon


2. **[Downloading Necesssary Assets]**
    *PhOS* relies on some assets to build and test,
    please download these assets by simply running following commands

    ```bash
    # inside container
    cd /root/scripts/build_scripts
    bash download_assets.sh
    ```


3. **[Build]**
    Building *PhOS* is simple!

    *PhOS* provides a convinient build system as *PhOS* contains multiple dependent components 
    (e.g., autogen, daemon, client-side hijacker, unit-testing, CLI etc.),
    simply run the build script in the container would works:

    ```bash
    # inside container
    cd /root/scripts/build_scripts
    bash build.sh
    ```


## III. Running *PhOS* Samples

**TODO**


## IV. How *PhOS* Works?

<div align="center">
    <img src="./docs/docs/source/_static/images/pos_mechanism.jpg" width="80%" />
</div>


## V. Paper

If you use *PhOS* in your research, please cite our paper:

```bibtex
@article{huang2024parallelgpuos,
  title={PARALLELGPUOS: A Concurrent OS-level GPU Checkpoint and Restore System using Validated Speculation},
  author={Huang, Zhuobin and Wei, Xingda and Hao, Yingyi and Chen, Rong and Han, Mingcong and Gu, Jinyu and Chen, Haibo},
  journal={arXiv preprint arXiv:2405.12079},
  year={2024}
}
```
