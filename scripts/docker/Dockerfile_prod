FROM rootproject/root:6.24.00-ubuntu20.04

WORKDIR /CutLang
COPY . .

RUN apt update

RUN apt install python3-pip -y
RUN pip install jupyterlab metakernel

RUN apt install -y bison flex make wget

RUN cd /CutLang/CLA && make clean && make
RUN echo "alias python=python3" >> ~/.bashrc
RUN echo "source /CutLang/setup.sh" >> ~/.bashrc

WORKDIR /src

CMD [ "tail", "-f", "/dev/null" ]
