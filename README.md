# PhoenixOS
[![cuda](https://img.shields.io/badge/CUDA-supported-brightgreen.svg?logo=nvidia)](https://phoenixos-docs.readthedocs-hosted.com/en/latest/cuda_gsg/index.html)
[![rocm](https://img.shields.io/badge/ROCm-Developing-lightgrey.svg?logo=amd)]()
[![ascend](https://img.shields.io/badge/Ascend-Developing-lightgrey.svg?logo=huawei)]()
[![slack](https://img.shields.io/badge/slack-PhoenixOS-brightgreen.svg?logo=slack)](https://phoenixoshq.slack.com/archives/C07V2QWVB8Q)
[![docs](https://img.shields.io/badge/Docs-passed-brightgreen.svg?logo=readthedocs)](https://phoenixos-docs.readthedocs-hosted.com/en/latest/index.html)

<div align="center">
    <img src="./docs/docs/source/_static/images/home/logo.jpg" height="200px" />
</div>

<div>
    <p>
    <b>PhoenixOS</b> (<i>PhOS</i>) is an OS-level GPU checkpoint/restore (C/R) system. It can <b>transparently</b> C/R processes that use the GPU, without requiring any cooperation from the application, a key feature required by modern systems like the cloud. Most importantly, <i>PhOS</i> is the first OS-level C/R system that can <b>concurrently execute C/R without stopping the execution of application</b>.
    <p>
    Note that <i>PhOS</i> is aimming to be a generic system that towards various hardware platforms from different vendors, by providing a set of interfaces which should be implemented by different hardware platforms. We currently provide the C/R implementation on CUDA platform, support for ROCm and Ascend are under development.
    <div style="margin:20px 0px;">
        <b>
        ⚠️ <i>PhOS</i> is currently under heavy development. If you're interested in contributing to this project, please join our <a href="https://phoenixoshq.slack.com/archives/C07V2QWVB8Q">slack workspace</a> for more upcoming cool features on <i>PhOS</i>.
        </b>
    </div>
    <div style="padding: 0px 10px;">
        <p>
        <h3 style="margin:0px; margin-bottom:5px;">📑 Latest News</h3>
        <ul>
            <li style="margin:0px; margin-bottom:8px;">
                <p style="margin:0px; margin-bottom:1px;">
                    <b>[Nov.4, 2024]</b> <i>PhOS</i> is open sourced 🎉 [<a href="https://github.com/PhoenixOS-IPADS/PhoenixOS">Repo</a>] [<a href="http://phoenixos-docs.readthedocs-hosted.com/">Documentations</a>]
                </p>
                <p style="margin:0px; margin-bottom:1px;">
                    👉 <i>PhOS</i> is currently fully supporting continuous checkpoint and fast restore
                </p>
                <p style="margin:0px; margin-bottom:1px;">
                    👉 We will soon release codes for live migration and multi-GPU support :)
                </p>                
            </li>
            <li>
                <p style="margin:0px; margin-bottom:5px;">
                    <b>[May 20, 2024]</b> <i>PhOS</i> paper is now released on arXiv [<a href="https://arxiv.org/abs/2405.12079">Paper</a>]
                </p>       
            </li>
        </ul>
    </div>
</div>


## I. Build and Install *PhOS*

### (A) CUDA Platform ![slack](https://img.shields.io/badge/CUDA-black.svg?logo=nvidia)

#### 💡 Option 1: Build and Install From Source

1. **[Clone Repository]**
    First of all, clone this repository **recursively**:

    ```bash
    git clone --recursive https://github.com/SJTU-IPADS/PhoenixOS.git
    ```

2. **[Start Container]**
    *PhOS* can be built and installed on official CUDA image from nVIDIA.

    > [!NOTE]
    > PhOS require libc6 >= 2.29 for compiling latest CRIU from source.

    For example, for running *PhOS* for CUDA 11.3,
    one can build on official CUDA images
    (e.g., [`nvidia/cuda:11.3.1-cudnn8-devel-ubuntu20.04`](https://hub.docker.com/layers/nvidia/cuda/11.3.1-cudnn8-devel-ubuntu20.04/images/sha256-459c130c94363099b02706b9b25d9fe5822ea233203ce9fbf8dfd276a55e7e95)):


    ```bash
    # enter repository
    cd PhoenixOS

    # start container
    sudo docker run -dit --gpus all -v.:/root --name phos nvidia/cuda:11.3.1-cudnn8-devel-ubuntu20.04

    # enter container
    sudo docker exec -it phos /bin/bash
    ```

    Note that it's important to execute docker container with root privilege, as CRIU needs the permission to C/R kernel-space memory pages.

3. **[Downloading Necesssary Assets]**
    *PhOS* relies on some assets to build and test,
    please download these assets by simply running following commands:

    ```bash
    # inside container
    cd /root/scripts/build_scripts
    bash download_assets.sh

    # install basic dependencies from OS pkg manager
    sudo apt-get update
    sudo apt-get install git wget
    ```


4. **[Build]**
    Building *PhOS* is simple!

    *PhOS* provides a convinient build system, which covers compiling, linking and installing all *PhOS* components:

    <ol>
    <li>
        <code>phos-autogen</code>: <b>Autogen Engine</b> for generating most of Parser and Worker code for specific hardware platform, based on lightwight notation.
    </li>
    <li>
        <code>phosd</code>: <b>PhOS Daemon</b>, which continuously run at the background, taking over the control of all GPU devices on the node.
    </li>
    <li>
        <code>libphos.so</code>: <b>PhOS Hijacker</b>, which hijacks all GPU API calls on the client-side and forward to PhOS Daemon.
    </li>
    <li>
        <code>libpccl.so</code>: <b>PhOS Checkpoint Communication Library</b> (PCCL), which provide highly-optimized device-to-device state migration. Note that this library is not included in current release.
    </li>
    <li>
        <code>unit-testing</code>: <b>Unit Tests</b> for PhOS, which is based on GoogleTest.
    </li>
    <li>
        <code>phos-cli</code>: <b>Command Line Interface</b> (CLI) for interacting with PhOS.
    </li>
    <li>
        <code>phos-remoting</code>: <b>Remoting Framework</b>, which provide highly-optimized GPU API remoting performance. See more details at <a href="https://github.com/SJTU-IPADS/PhoenixOS-Remoting">SJTU-IPADS/PhoenixOS-Remoting</a>.
    </li>
    </ol>

    To build and install all above components and other dependencies, simply run the build script in the container would works:

    ```bash
    # inside container
    cd /root/scripts/build_scripts

    # clear old build cache
    #   -c: clear previous build
    #   -3: the clean process involves all third-parties
    bash build.sh -c -3

    # start building
    #   -3: the build process involves all third-parties
    #   -i: install after successful building
    bash build.sh -3 -i
    ```

    For customizing build options, please refers to and modify avaiable options under `scripts/build_scripts/build_config.yaml`.

    If you encounter any build issues, you're able to see building logs under `build_log`. Please open a new issue if things are stuck :-|

#### 💡 Option 2: Install From Pre-built Binaries

1. **[Download Pre-built Package]**
    One can also download pre-built binaries from repo's release page:

    ```bash
    wget
    ```


### (B) Other Platforms ![rocm](https://img.shields.io/badge/ROCm-black.svg?logo=amd) ![rocm](https://img.shields.io/badge/Ascend-black.svg?logo=huawei)

We will release support to other platforms soon :)


## II. Usage

**TODO**


## III. How *PhOS* Works?

As migration is essentially the combination of checkpoint and restore, we below discuss the workflow in PhOS by demonstrating the migration process.

<div align="center">
    <img src="./docs/docs/source/_static/images/pos_mechanism.jpg" width="80%" />
</div>

### 🌟 Checkpoint

During checkpoint, <i>PhOS</i> leverages CRIU to checkpoint the state on CPU-side

For more details, please check our [paper](https://arxiv.org/abs/2405.12079).


## IV. Paper

If you use *PhOS* in your research, please cite our paper:

```bibtex
@article{huang2024parallelgpuos,
  title={PARALLELGPUOS: A Concurrent OS-level GPU Checkpoint and Restore System using Validated Speculation},
  author={Huang, Zhuobin and Wei, Xingda and Hao, Yingyi and Chen, Rong and Han, Mingcong and Gu, Jinyu and Chen, Haibo},
  journal={arXiv preprint arXiv:2405.12079},
  year={2024}
}
```

## V. Contributors

Please check <a href="https://github.com/SJTU-IPADS/PhoenixOS/blob/main/.mailmap">mailmap</a> for all contributors.