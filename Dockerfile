FROM ubuntu:20.04

RUN apt update && apt upgrade -y

SHELL ["/bin/bash", "-c"] 

#bug fix
ENV DEBIAN_FRONTEND=noninteractive 

RUN apt install -y dpkg-dev cmake g++ gcc binutils libx11-dev libxpm-dev libxft-dev libxext-dev libssl-dev python3.8
RUN echo "alias python='python3.8'" >> ~/.bashrc

RUN cd ~
RUN apt install -y wget
RUN wget https://root.cern/download/root_v6.24.00.Linux-ubuntu20-x86_64-gcc9.3.tar.gz
RUN tar -xzvf root_v6.24.00.Linux-ubuntu20-x86_64-gcc9.3.tar.gz
RUN echo "source ~/bin/thisroot.sh" >> ~/.bashrc


WORKDIR /CutLang-dev
COPY . /CutLang-dev

RUN apt install -y bison flex

#RUN source ~/bin/thisroot.sh && cd /CutLang-dev/CLA && make

RUN echo "source /CutLang-dev/setup.sh" >> ~/.bashrc
