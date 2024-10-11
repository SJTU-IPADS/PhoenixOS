# PhOS Autogen Framework

This directory contains a framework for automatically generating codes in PhOS for certain target (e.g., CUDA)

## Usage

For CUDA:

```bash
export POS_BUILD_TARGET=cuda
LD_LIBRARY_PATH=../../lib/ ./pos_autogen -s ../autogen_cuda/supported/11.3 -d /usr/local/cuda/include
```
