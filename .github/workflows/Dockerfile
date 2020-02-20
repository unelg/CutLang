FROM ubuntu:18.04

RUN apt update

RUN apt install -y git dpkg-dev cmake g++ gcc binutils libx11-dev libxpm-dev \
libxft-dev libxext-dev

RUN apt install -y gfortran libssl-dev libpcre3-dev \
xlibmesa-glu-dev libglew1.5-dev libftgl-dev \
libmysqlclient-dev libfftw3-dev libcfitsio-dev \
graphviz-dev libavahi-compat-libdnssd-dev \
libldap2-dev python-dev libxml2-dev libkrb5-dev \
libgsl0-dev libqt4-dev

RUN apt install -y wget bison flex 
RUN mkdir base ; cd base ; git clone http://github.com/root-project/root.git
RUN mkdir build ; cd build ; cmake ../base/root ; cmake --build . --target install -- -j4

COPY ../ / 
COPY ./deploy.sh /
COPY ./root.conf /
RUN chmod +x run.sh
ENTRYPOINT ["./deploy.sh"]
