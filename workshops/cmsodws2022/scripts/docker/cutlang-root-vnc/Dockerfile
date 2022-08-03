FROM rootproject/root:6.26.04-ubuntu22.04

WORKDIR /usr/local

COPY ./workshops/cmsodws2022/scripts/docker/cutlang-root-vnc/packages.txt packages.txt
COPY ./workshops/cmsodws2022/scripts/docker/cutlang-root-vnc/requirements.txt requirements.txt

# Set PATH to pickup virtualenv by default
ENV PATH=/usr/local/venv/bin:"${PATH}"
RUN apt-get -qq -y update && \
    DEBIAN_FRONTEND=noninteractive apt-get -qq -y install --no-install-recommends $(cat packages.txt) && \
    yes | unminimize && \
    apt-get -y autoclean && \
    apt-get -y autoremove && \
    rm -rf /var/lib/apt/lists/* && \
    python -m venv /usr/local/venv && \
    . /usr/local/venv/bin/activate && \
    python -m pip --no-cache-dir install --upgrade pip setuptools wheel && \
    python -m pip --no-cache-dir install --requirement requirements.txt && \
    python -m pip list && \
    ln --symbolic --force /bin/bash /bin/sh && \
    ln -sf /usr/share/zoneinfo/UTC /etc/localtime


# CutLang dependencies
RUN apt-get update -y
RUN apt-get install python3-pip -y
RUN pip install jupyterlab notebook metakernel

RUN apt-get install -y bison flex make wget git
RUN apt-get install -y nano


# Add 0mq to /usr/local
# unfortunately, ZeroMQ doesn't have a release yet that contains the PPOLL feature that is needed for roofit parallelism
# the ROOT team for now uses tihs specific commit hash, so we do the same 
ARG ZMQ_TAG=7c2df78b49a3aa63e654b3f3526adf71ed091534
# see: https://github.com/root-project/root/blob/8e9ee7f04a89156af4f9a142579e1d0c75ee398d/builtins/zeromq/libzmq/CMakeLists.txt#L17
WORKDIR /code
RUN git clone https://github.com/zeromq/libzmq.git 0mq && \
    cd 0mq && git checkout "${ZMQ_TAG}" && cd - && \
    cmake \
    -DCMAKE_INSTALL_PREFIX=/code/local \
    -S 0mq \
    -B build \
    && cmake build -LH \
    && cmake \
    --build build \
    --clean-first \
    --parallel $(($(nproc) - 1)) \
    && cmake --build build --target install \
    && cd / \
    && cp -r /code/local/* /usr/local/venv \
    && rm -rf /code

# Add XRootD under /usr/local
ARG XROOTD_TAG=v5.4.3
WORKDIR /code
RUN git clone --depth 1 https://github.com/xrootd/xrootd.git \
    --branch "${XROOTD_TAG}" \
    --single-branch \
    xrootd \
    && cmake \
    -DCMAKE_INSTALL_PREFIX=/usr/local/venv \
    -DPIP_VERBOSE=ON \
    -S xrootd \
    -B build \
    && cmake build -LH \
    && cmake \
    --build build \
    --clean-first \
    --parallel $(($(nproc) - 1)) \
    && cmake --build build --target install \
    && cd / \
    && rm -rf /code

RUN git clone --depth 1 --single-branch https://github.com/novnc/noVNC.git /usr/local/novnc

RUN groupadd -g 1000 cmsusr && adduser --uid 1000 --gid 1000 cmsusr --disabled-password && \
    usermod -aG sudo cmsusr && \
    chown -R cmsusr:cmsusr /usr/local/venv

RUN echo "source /usr/local/vnc_utils.sh" >> /home/cmsusr/.bashrc && \
    echo "source /usr/local/vnc_utils.sh" >> /home/cmsusr/.zshrc && \
    printf '\nexport PATH=/usr/local/venv/bin:"${PATH}"\n' >> /home/cmsusr/.bashrc

COPY ./workshops/cmsodws2022/scripts/docker/cutlang-root-vnc/vnc/vnc_utils.sh /usr/local/vnc_utils.sh

WORKDIR /CutLang
COPY . .

RUN cd /CutLang/CLA && make clean && make
RUN echo "alias python=python3" >> /home/cmsusr/.bashrc
RUN echo "source /CutLang/setup.sh" >> /home/cmsusr/.bashrc

RUN echo "echo For examples see \$CUTLANG_PATH/runs/" >> /home/cmsusr/.bashrc
RUN echo "echo and for LHC analysis implementations, see" >> /home/cmsusr/.bashrc
RUN echo "echo https://github.com/ADL4HEP/ADLLHCanalyses" >> /home/cmsusr/.bashrc

WORKDIR /src

RUN mkdir -p /code && \
    chown -R cmsusr:cmsusr /code && \
    chmod 777 /code && \
    mkdir -p /CutLang && \
    chown -R cmsusr:cmsusr /CutLang && \
    chmod 777 /CutLang && \
    chown -R cmsusr:cmsusr /opt/root/lib/JupyROOT && \
    chmod 777 /opt/root/lib/JupyROOT && \
    chown -R cmsusr:cmsusr /opt/root/etc && \
    chmod 777 /opt/root/etc

USER cmsusr
ENV USER cmsusr
ENV HOME /home/cmsusr
ENV GEOMETRY 1920x1080

RUN mkdir -p ${HOME}/.vnc
ADD --chown=cmsusr:cmsusr ./workshops/cmsodws2022/scripts/docker/cutlang-root-vnc/vnc/passwd ${HOME}/.vnc/passwd
ADD --chown=cmsusr:cmsusr ./workshops/cmsodws2022/scripts/docker/cutlang-root-vnc/.rootrc ${HOME}/.rootrc

CMD [ "tail", "-f", "/dev/null" ]
