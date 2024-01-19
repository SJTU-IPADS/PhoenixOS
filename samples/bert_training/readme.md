# Megratron-deepspeed training sample

## Prepare

1. clone repo and download datasets

```bash
git clone https://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@github.com/microsoft/Megatron-DeepSpeed.git
```

download datasets for BERT training

```bash
# TODO:
```

2. downgrade megratron version, and fix a adaption bug

```bash
cd Megatron-DeepSpeed
git reset --hard 2e6e7fb
```

we also need to fix `from deepspeed import get_accelerator` to `from deepspeed.accelerator import get_accelerator` in `Megatron-DeepSpeed/megatron/core/utils.py`

3. run container

```bash
sudo docker run --gpus all -dit --name hzb_bert_train -v[Megatron-DeepSpeed Path]:/root -v[Dataset Path]:/root zobinhuang/pytorch:1.13.1-megratron-deepspeed
```

## Run training

### (1) BERT

1. pre-process datasets

```bash
python3 ./examples_deepspeed/bert_with_pile/prepare_pile_data.py 
```




## Record of the building process of imgae `zobinhuang/pytorch:1.13.1-v3-megratron-deepspeed` (based on `zobinhuang/pytorch:1.13.1-v3`)

1. clone necessary repos on the host, and mount these repos into the container

```bash
git clone https://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@github.com/microsoft/DeepSpeed.git
git clone https://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@github.com/nvidia/apex.git
```

2. downgrade deepspeed version

```bash
# we need to downgrade the version of deepspeed, or it will use MPS which seems not supported in pytorch 11.3:
# module 'torch._C' has no attribute '_mps_currentAllocatedMemory'
cd DeepSpeed
git checkout v0.9.0
```

3. downgrade apex version

```bash
# we need to downgrade the version of apex, or it will use newer torch support:
# error: class "at::Tensor" has no member "mutable_data_ptr"
cd apex
git checkout 23.06
```

. install necessary pre-built libraries

```bash
pip install transformers datasets
conda install zstandard six regex nltk
```

6. building and install `deepspeed`

```bash
cd DeepSpeed
apt-get install libaio-dev libaio1
DS_BUILD_OPS=1 DS_BUILD_SPARSE_ATTN=0 pip install . --config-settings="--jobs=6"

# downgrade pydantic version
# see issue https://github.com/microsoft/DeepSpeed/issues/3963
python3 -m pip install pydantic=1.10

# check installation
ds_report
```

7. build and install `apex`

```bash
cd apex
pip install -v --disable-pip-version-check --no-cache-dir --no-build-isolation --config-settings "--build-option=--cpp_ext" --config-settings "--build-option=--cuda_ext" ./
```
