# PhoenixOS (PhOS)

[![build passing](https://img.shields.io/badge/build-passed-green)](https://github.com/PhoenixOS-IPADS/PhoenixOS)
[![build passing](https://img.shields.io/badge/supported-CUDA-blue)](https://phoenixos.readthedocs.io/en/latest/cuda_gsg/index.html)
[![build passing](https://img.shields.io/badge/TODO-ROCm-lightgrey)]()
[![build passing](https://img.shields.io/badge/TODO-Ascend-lightgrey)]()
[![doc](https://img.shields.io/badge/docs-green)](https://phoenixos.readthedocs.io/en/latest/index.html)

<table style="border:none;">
    <tr>
        <td width='30%'>
            <div align="center" style="margin:0px; padding:0px;">
                <img src="./docs/docs/source/_static/images/home/pos_logo.gif" style="margin:0px; padding:0px;" />
            </div>
        </td>
        <td>
            <p>
            <b>PhoenixOS</b> (<i>PhOS</i>) is an OS-level GPU checkpoint/restore (C/R) system. It can <b>transparently</b> C/R processes that use the GPU, without requiring any cooperation from the application, a key feature required by modern systems like the cloud. Moreover, <i>PhOS</i> is the first OS-level C/R system that can <b>concurrently execute C/R without stopping the execution of application</b>.
            <div style="padding: 0px 5px;">
                <p>
                <h3 style="margin:0px; margin-bottom:5px;">Latest News</h3>
                <ul>
                    <li>
                        <p style="margin:0px; margin-bottom:5px;">
                            <b>[Oct.20 2024]</b> <i>PhOS</i> is open sourced 🎉 [<a href="https://github.com/PhoenixOS-IPADS/PhoenixOS">Repo</a>] [<a href="http://phoenixos.readthedocs.io/">Documentations</a>] [<a href="https://arxiv.org/abs/2405.12079">Paper</a>]
                        </p>
                        <p style="margin:0px; margin-bottom:5px;">
                            👉 <i>PhOS</i> is currently fully supporting continuous checkpoint and fast restore, the feature of near-seamless migration would come soon :)
                        </p>
                        <p style="margin:0px; margin-bottom:5px;">
                            👉 <i>PhOS</i> is now supporting CUDA platform, ROCm and Ascend is also on the road.
                        </p>
                    </li>
                </ul>
            </div>
        </td>
    </tr>
</table>


## I. What *PhOS* Does?

> [!NOTE]  
> Contributions from community are very welcomed!<br />
> See all potential cool features could be built on *PhOS* at [<a href=""><i>PhOS</i> Roadmap</a>] and [<a href="">Contribute to <i>PhOS</i></a>]


## II. Build *PhOS* From Source

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
