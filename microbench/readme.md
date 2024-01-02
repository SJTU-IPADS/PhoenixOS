# Microbench Tests

## Tools

### 1. NVIDIA Nsights

We borrowed the dockerfile provided by [leimao/Nsight-Systems-Docker-Image](https://github.com/leimao/Nsight-Systems-Docker-Image) to use the nsight system and compute tool

```bash
cd Nsight-Systems-Docker-Image/
sudo docker build -f nsight-systems.Dockerfile --no-cache --tag=nsight-systems:2023.4 .
```
