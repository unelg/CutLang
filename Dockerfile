FROM rootproject/root:6.24.00-ubuntu20.04

WORKDIR /CutLang
COPY . .

RUN apt update

RUN apt install python3-pip -y
RUN pip install jupyterlab notebook metakernel

RUN apt install -y bison flex make wget git

RUN cd /CutLang/CLA && make clean && make
RUN echo "alias python=python3" >> ~/.bashrc
RUN echo "source /CutLang/setup.sh" >> ~/.bashrc

RUN echo "echo For examples see \$CUTLANG_PATH/runs/" >> ~/.bashrc
RUN echo "echo and for LHC analysis implementations, see" >> ~/.bashrc
RUN echo "echo https://github.com/ADL4HEP/ADLLHCanalyses" >> ~/.bashrc

WORKDIR /src

CMD [ "tail", "-f", "/dev/null" ]
