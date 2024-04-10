# Samples for POS

run CRIU on the client side:

```bash
criu dump -D ckpt/ --display-stats -j -v4 -t 2221
```

```bash
criu restore -D ckpt/ -j --display-stats
```

incremental checkpoint

```bash

criu dump --images-dir ./ckpt/ --track-mem --shell-job --leave-running --display-stats -t 23546

criu dump --images-dir ./ckpt/ --shell-job --prev-images-dir ../ckpt/ --display-stats -t 23546 
```

to set proxy inside container 

```bash
export https_proxy=http://192.168.23.105:7890;export http_proxy=http://192.168.23.105:7890;export all_proxy=socks5://192.168.23.105:7890
```

see all CUDA apis

```bash
nvprof --print-api-summary --openacc-profiling off ./a.out 
```