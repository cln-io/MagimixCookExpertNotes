FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Core tools + ARM cross-compilation toolchain
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gcc-arm-none-eabi \
    binutils-arm-none-eabi \
    libnewlib-arm-none-eabi \
    gdb-multiarch \
    python3 \
    python3-pip \
    git \
    wget \
    curl \
    unzip \
    xxd \
    file \
    openjdk-17-jdk-headless \
    && rm -rf /var/lib/apt/lists/*

# Reverse engineering & firmware analysis Python tools
RUN pip3 install --no-cache-dir \
    capstone \
    keystone-engine \
    unicorn \
    pyelftools \
    intelhex \
    binwalk

# Radare2 (CLI reverse engineering framework)
RUN git clone --depth 1 https://github.com/radareorg/radare2.git /tmp/radare2 \
    && cd /tmp/radare2 \
    && sys/install.sh \
    && rm -rf /tmp/radare2

# Ghidra headless (for scripted decompilation)
ARG GHIDRA_VERSION=11.0.3
ARG GHIDRA_DATE=20240410
RUN wget -q "https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_${GHIDRA_VERSION}_build/ghidra_${GHIDRA_VERSION}_PUBLIC_${GHIDRA_DATE}.zip" \
    -O /tmp/ghidra.zip \
    && unzip -q /tmp/ghidra.zip -d /opt \
    && mv /opt/ghidra_${GHIDRA_VERSION}_PUBLIC /opt/ghidra \
    && rm /tmp/ghidra.zip

ENV GHIDRA_INSTALL_DIR=/opt/ghidra
ENV PATH="${PATH}:/opt/ghidra/support"

WORKDIR /firmware

COPY scripts/ /tools/
RUN chmod +x /tools/*.py 2>/dev/null || true

CMD ["/bin/bash"]
