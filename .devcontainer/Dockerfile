FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

# ---- base tools ----
RUN apt-get update && apt-get install -y \
    ca-certificates \
    wget \
    gnupg \
    lsb-release \
    software-properties-common \
    build-essential \
    cmake \
    ninja-build \
    git \
    neovim \
    gdb \
    && rm -rf /var/lib/apt/lists/*

# ---- install LLVM trunk (aka "21") ----
WORKDIR /tmp
RUN wget https://apt.llvm.org/llvm.sh \
    && chmod +x llvm.sh \
    && ./llvm.sh 21

# ---- install full LLVM 21 toolchain ----
RUN apt-get update && apt-get install -y \
    clang-21 \
    clangd-21 \
    lldb-21 \
    libc++-21-dev \
    libc++abi-21-dev \
    libclang-21-dev \
    && rm -rf /var/lib/apt/lists/*

# ---- make LLVM 21 the default ----
RUN update-alternatives --install /usr/bin/clang clang /usr/bin/clang-21 200 \
 && update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-21 200 \
 && update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-21 200 \
 && update-alternatives --install /usr/bin/lldb lldb /usr/bin/lldb-21 200 \
 && update-alternatives --auto clang \
 && update-alternatives --auto clang++ \
 && update-alternatives --auto clangd \
 && update-alternatives --auto lldb

# ---- sanity check (build-time) ----
RUN clang --version && clangd --version && clang++ --version

WORKDIR /workspace
