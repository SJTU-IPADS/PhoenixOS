# Quick start 

This guide will help you build and run PhOS from source. 
PhOS provides two options, and you can choose **either one** to build PhOS. 

## Overview of the build 

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


1. **[Clone Repository]**
    First of all, clone this repository **recursively**:

    ```bash
    git clone --recursive https://github.com/SJTU-IPADS/PhoenixOS.git
    ```

2. **[Downloading Necesssary (third-party) Assets]**
    PhOS relies on some assets to build and test,
    please download these assets by simply running following commands:

    ```bash
    # download assets
    cd path/to/phos/scripts/build_scripts
    bash download_assets.sh
    ```    

3. **(Optional#1) [Build with our image]**    
    First, build our pre-released image (if not found phos-base-113 on the hub):
    (This option only works for cuda 11.3 for now)
    
    ```bash
    make build-image
    ```

    Second, use the image to build PhOS all the time:
    
    ```bash
    make build BUILD_ARGS="-i -3 -p=false" 
    ```

    Use the following to check possible built options:

    ```bash
    make build BUILD_ARGS="-help"
    ```

3. **(Optional#2) [Start an interactive container]**
    PhOS can be built and installed on official vendor image (or host) 
    if you don't want to use our pre-built image. 

    > NOTE: PhOS has some minimal requirements, e.g., it requires libc6 >= 2.29 for compiling CRIU from source. Thus, we strongly recommend you to use our base image as an interactive building environment.

    For example, for running PhOS for CUDA 11.3,
    one can build on official CUDA images
    (e.g., [`nvidia/cuda:11.3.1-cudnn8-devel-ubuntu20.04`](https://hub.docker.com/layers/nvidia/cuda/11.3.1-cudnn8-devel-ubuntu20.04/images/sha256-459c130c94363099b02706b9b25d9fe5822ea233203ce9fbf8dfd276a55e7e95)):


    ```bash
    # enter repository
    cd PhoenixOS/scripts/docker

    # start and enter container with id 1
    bash run_torch_cu113.sh -s 1

    # enter / close container (no need to execute here, just listed)
    bash run_torch_cu113.sh -e 1    # enter container
    bash run_torch_cu113.sh -c 1    # close container
    ```

    > Note that it's important to execute docker container with root privilege, as CRIU needs the permission to C/R kernel-space memory pages.

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
    #   -u: build PhOS with unit test enable
    bash build.sh -i -3 -u
    ```

4. **Build configuration and trouble shooting**
    For customizing build options, please refers to and modify avaiable options under `scripts/build_scripts/build_config.yaml`.

    If you encounter any build issues, you're able to see building logs under `build_log`. Please open a new issue if things are stuck :-| The logs typically are quite self-explained. 