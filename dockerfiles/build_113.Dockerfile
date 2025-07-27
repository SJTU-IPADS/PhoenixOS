FROM  phoenixos/pytorch:11.3-ubuntu20.04 as base

ARG DEBIAN_FRONTEND=noninteractive
ARG proxy

RUN apt update
RUN apt-get install -y libibverbs-dev libboost-all-dev net-tools            \
    git-lfs pkg-config python3-pip libelf-dev libssl-dev libgl1-mesa-dev    \
    libvdpau-dev iputils-ping wget gdb vim nsight-compute-2023.1.1    

RUN apt-get update && \
    apt-get install -y software-properties-common && \
    add-apt-repository -y ppa:ubuntu-toolchain-r/test && \
    apt-get update

RUN apt-get install -y g++-9
RUN apt-get install -y g++-13

RUN pip3 install meson  -i https://mirrors.aliyun.com/pypi/simple/

RUN ln -s /opt/nvidia/nsight-compute/2023.1.1/target/linux-desktop-glibc_2_11_3-x64/ncu /usr/local/bin/ncu

RUN pip config set global.index-url https://mirrors.aliyun.com/pypi/simple/

# Copy build scripts from the project root
COPY  scripts/ /scripts
COPY  third_party/go1.23.2.linux-amd64.tar.gz /third_party/go1.23.2.linux-amd64.tar.gz

# Make scripts executable and run download_assets.sh
RUN chmod +x /scripts/build_scripts/*.sh
RUN cd /scripts/build_scripts && bash build.sh -p -b=false -3=true

ENV PATH="/root/bin:${PATH}"
ENV PATH="/opt/rust/.cargo/bin:${PATH}"
ENV LD_LIBRARY_PATH="/root/lib:${LD_LIBRARY_PATH}"
ENV CARGO_HOME=/opt/rust/.cargo
ENV RUSTUP_HOME=/opt/rust/.rustup

RUN . /opt/rust/.cargo/env
RUN export RUSTUP_DIST_SERVER=https://mirrors.tuna.tsinghua.edu.cn/rustup && rustup default nightly

WORKDIR /root

