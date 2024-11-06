# PhoenixOS
[![cuda](https://img.shields.io/badge/CUDA-supported-brightgreen.svg?logo=nvidia)](https://phoenixos.readthedocs.io/en/latest/cuda_gsg/index.html#)
[![rocm](https://img.shields.io/badge/ROCm-Developing-lightgrey.svg?logo=amd)](https://phoenixos.readthedocs.io/en/latest/rocm_gsg/index.html)
[![ascend](https://img.shields.io/badge/Ascend-Developing-lightgrey.svg?logo=huawei)]()
[![slack](https://img.shields.io/badge/slack-PhoenixOS-brightgreen.svg?logo=slack)](https://phoenixoshq.slack.com/archives/C07V2QWVB8Q)
[![docs](https://img.shields.io/badge/Docs-passed-brightgreen.svg?logo=readthedocs)](https://phoenixos.readthedocs.io/en/latest/)

<div align="center">
    <img src="./docs/docs/source/_static/images/home/logo.jpg" height="200px" />
</div>

<div>
    <p>
    <b>PhoenixOS</b> (PhOS) is an OS-level GPU checkpoint/restore (C/R) system. It can <b>transparently</b> C/R processes that use the GPU, without requiring any cooperation from the application, a key feature required by modern systems like the cloud. Most importantly, PhOS is the first OS-level C/R system that can <b>concurrently execute C/R without stopping the execution of application</b>.
    <p>
    Under CUDA platform, we compared the C/R performace of PhOS with [nvidia/cuda-checkpoint](https://github.com/NVIDIA/cuda-checkpoint):
    <table>
        <tr><th align="center">Checkpointing Llama2-13b-chat</th></tr>
        <tr><td align="center"><img src="./docs/docs/source/_static/images/home/llama2_ckpt.gif" /></td></tr>
    </table>
    <table>
        <tr><th align="center">Restoring Llama2-13b-chat</th></tr>
        <tr><td align="center"><img src="./docs/docs/source/_static/images/home/llama2_restore.gif" /></td></tr>
    </table>
    <p>
    Note that PhOS is aimming to be a generic design that towards various hardware platforms from different vendors, by providing a set of interfaces which should be implemented by specific hardware platforms. We currently provide the C/R implementation on CUDA platform, support for ROCm and Ascend are under development.
    <div style="padding: 0px 10px;">
        <p>
        <h3 style="margin:0px; margin-bottom:5px;">📑 Latest News</h3>
        <ul>
            <li style="margin:0px; margin-bottom:8px;">
                <p style="margin:0px; margin-bottom:1px;">
                    <b>[Nov.6, 2024]</b> PhOS is open sourced 🎉 [<a href="https://github.com/PhoenixOS-IPADS/PhoenixOS">Repo</a>] [<a href="https://phoenixos.readthedocs.io/en/latest/index.html">Documentations</a>]
                </p>
                <p style="margin:0px; margin-bottom:1px;">
                    👉 PhOS is currently fully supporting single-GPU checkpoint and restore
                </p>
                <p style="margin:0px; margin-bottom:1px;">
                    👉 We will soon release codes for cross-node live migration and multi-GPU support :)
                </p>                
            </li>
            <li>
                <p style="margin:0px; margin-bottom:5px;">
                    <b>[May 20, 2024]</b> PhOS paper is now released on arXiv [<a href="https://arxiv.org/abs/2405.12079">Paper</a>]
                </p>       
            </li>
        </ul>
    </div>
    <table style="margin:20px 0px;">
        <tr><td><b>
        PhOS is currently under heavy development. If you're interested in contributing to this project, please join our <a href="https://phoenixoshq.slack.com/archives/C07V2QWVB8Q">slack workspace</a> for more upcoming cool features on PhOS.
        </b></td></tr>
    </table>
</div>

<br />

## I. Build and Install PhOS

### 💡 Option 1: Build and Install From Source

1. **[Clone Repository]**
    First of all, clone this repository **recursively**:

    ```bash
    git clone --recursive https://github.com/SJTU-IPADS/PhoenixOS.git
    ```

2. **[Start Container]**
    PhOS can be built and installed on official vendor image.

    > NOTE: PhOS require libc6 >= 2.29 for compiling CRIU from source.

    For example, for running PhOS for CUDA 11.3,
    one can build on official CUDA images
    (e.g., [`nvidia/cuda:11.3.1-cudnn8-devel-ubuntu20.04`](https://hub.docker.com/layers/nvidia/cuda/11.3.1-cudnn8-devel-ubuntu20.04/images/sha256-459c130c94363099b02706b9b25d9fe5822ea233203ce9fbf8dfd276a55e7e95)):


    ```bash
    # enter repository
    cd PhoenixOS

    # start container
    sudo docker run -dit --gpus all                                         \
                -v.:/root                                                   \
                --privileged --network=host --ipc=host                      \
                --name phos nvidia/cuda:11.3.1-cudnn8-devel-ubuntu20.04

    # enter container
    sudo docker exec -it phos /bin/bash
    ```

    Note that it's important to execute docker container with root privilege, as CRIU needs the permission to C/R kernel-space memory pages.

3. **[Downloading Necesssary Assets]**
    PhOS relies on some assets to build and test,
    please download these assets by simply running following commands:

    ```bash
    # inside container

    # install basic dependencies from OS pkg manager
    apt-get update
    apt-get install git wget
    
    # download assets
    cd /root/scripts/build_scripts
    bash download_assets.sh
    ```


4. **[Build]**
    Building PhOS is simple!

    PhOS provides a convinient build system, which covers compiling, linking and installing all PhOS components:

    <table>
        <tr>
            <th width="25%">Component</th>
            <th width="75%">Description</th>
        </tr>
        <tr>
            <td><code>phos-autogen</code></td>
            <td><b>Autogen Engine</b> for generating most of Parser and Worker code for specific hardware platform, based on lightwight notation.</td>
        </tr>
        <tr>
            <td><code>phosd</code></td>
            <td><b>PhOS Daemon</b>, which continuously run at the background, taking over the control of all GPU devices on the node.</td>
        </tr>
        <tr>
            <td><code>libphos.so</code></td>
            <td><b>PhOS Hijacker</b>, which hijacks all GPU API calls on the client-side and forward to PhOS Daemon.</td>
        </tr>
        <tr>
            <td><code>libpccl.so</code></td>
            <td><b>PhOS Checkpoint Communication Library</b> (PCCL), which provide highly-optimized device-to-device state migration. Note that this library is not included in current release.</td>
        </tr>
        <tr>
            <td><code>unit-testing</code></td>
            <td><b>Unit Tests</b> for PhOS, which is based on GoogleTest.</td>
        </tr>
        <tr>
            <td><code>phos-cli</code></td>
            <td><b>Command Line Interface</b> (CLI) for interacting with PhOS.</td>
        </tr>
        <tr>
            <td><code>phos-remoting</code></td>
            <td><b>Remoting Framework</b>, which provide highly-optimized GPU API remoting performance. See more details at <a href="https://github.com/SJTU-IPADS/PhoenixOS-Remoting">SJTU-IPADS/PhoenixOS-Remoting</a>.</td>
        </tr>
    </table>

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

### 💡 Option 2: Install From Pre-built Binaries

    Will soon be updated :)


<br />

## II. Usage

Once successfully installed PhOS, you can now try run your program with PhOS support!

<table style="margin:20px 0px;">
    <tr><td><b>
    For more details, you can refer to <a href="https://github.com/SJTU-IPADS/PhoenixOS/tree/main/examples"><code>examples</code></a> for step-by-step tutorials to run PhOS.
    </b></td></tr>
</table>

### (1) Start `phosd` and your program

1. Start the PhOS daemon (`phosd`), which takes over all GPU reousces on the node:

    ```bash
    pos_cli --start --target daemon
    ```

2. To run your program with PhOS support, one need to put a `yaml` configure file under the directory which your program would regard as `$PWD`.
This file contains all necessary informations for PhOS to hijack your program. An example file looks like:

    ```yaml
    # [Field]   name of the job
    # [Note]    job with same name would share some resources in posd, e.g., CUModule, etc.
    job_name: "llama2-13b-chat-hf"

    # [Field]   remote address of posd, default is local
    daemon_addr: "127.0.0.1"
    ```

3. You are going for launch now! Try run your program with `env $phos` prefix, for example:

    ```bash
    env $phos python3 train.py
    ```

### (2) Pre-dump your program

To pre-dump your program, which save the CPU & GPU state without stopping your execution, simple run:

```bash
# create directory to store checkpoing files
mkdir /root/ckpt

# pre-dump command
pos_cli --pre-dump --dir /root/ckpt --pid [your program's pid]
```

### (3) Dump your program

To dump your program, which save the CPU & GPU state and stop your execution, simple run:

```bash
# create directory to store checkpoing files
mkdir /root/ckpt

# pre-dump command
pos_cli --dump --dir /root/ckpt --pid [your program's pid]
```


### (4) Restore your program

To restore your program, simply run:

```bash
# restore command
pos_cli --restore --dir /root/ckpt
```


<br />

## III. How PhOS Works?

<div align="center">
    <img src="./docs/docs/source/_static/images/pos_mechanism.jpg" width="80%" />
</div>

For more details, please check our [paper](https://arxiv.org/abs/2405.12079).


<br />

## IV. Paper

If you use PhOS in your research, please cite our paper:

```bibtex
@article{huang2024parallelgpuos,
  title={PARALLELGPUOS: A Concurrent OS-level GPU Checkpoint and Restore System using Validated Speculation},
  author={Huang, Zhuobin and Wei, Xingda and Hao, Yingyi and Chen, Rong and Han, Mingcong and Gu, Jinyu and Chen, Haibo},
  journal={arXiv preprint arXiv:2405.12079},
  year={2024}
}
```


<br />

## V. Contributors

Please check <a href="https://github.com/SJTU-IPADS/PhoenixOS/blob/main/.mailmap">mailmap</a> for all contributors.
