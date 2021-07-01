FROM ubuntu:20.04

RUN apt update && apt upgrade -y

SHELL ["/bin/bash", "-c"]

#bug fix
ENV DEBIAN_FRONTEND=noninteractive 

RUN apt install -y dpkg-dev cmake g++ gcc binutils libx11-dev libxpm-dev libxft-dev libxext-dev libssl-dev python3.8
RUN echo "alias python='python3.8'" >> ~/.bashrc

# Extra packages
#RUN apt install -y software-properties-common
#RUN add-apt-repository ppa:rock-core/qt4
#RUN apt update
#RUN apt install -y gfortran libpcre3-dev \
#xlibmesa-glu-dev libglew1.5-dev libftgl-dev \
#libmysqlclient-dev libfftw3-dev libcfitsio-dev \
#graphviz-dev libavahi-compat-libdnssd-dev \
#libldap2-dev libxml2-dev libkrb5-dev \
#libgsl0-dev libqt4-dev

WORKDIR /root_framework
RUN apt install -y wget
RUN wget https://root.cern/download/root_v6.24.00.Linux-ubuntu20-x86_64-gcc9.3.tar.gz
RUN tar -xzvf root_v6.24.00.Linux-ubuntu20-x86_64-gcc9.3.tar.gz && rm root_v6.24.00.Linux-ubuntu20-x86_64-gcc9.3.tar.gz
RUN echo "source /root_framework/root/bin/thisroot.sh" >> ~/.bashrc

#SHELL ["/bin/bash", "-c", "source /root_framework/root/bin/thisroot.sh"]

WORKDIR /CutLang
COPY . .

RUN apt install -y bison flex
# !!!!!!the following line must be removed from the comment line before deploying a new container!!!!!! (for production)
# RUN source /root_framework/root/bin/thisroot.sh && cd /CutLang/CLA && make
# !!!!!!the following line must be added to the comment line before deploying a new container!!!!!! (for production)
RUN source /root_framework/root/bin/thisroot.sh && cd /src/CLA && make
# !!!!!!the following line must be removed from the comment line before deploying a new container!!!!!! (for production)
# RUN echo "source /CutLang/setup.sh" >> ~/.bashrc
# !!!!!!the following line must be added to the comment line before deploying a new container!!!!!! (for production)
RUN echo "source /src/setup.sh" >> ~/.bashrc

WORKDIR /src

CMD [ "tail", "-f", "/dev/null" ]