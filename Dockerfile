FROM rootproject/root:6.24.00-ubuntu20.04

WORKDIR /CutLang
COPY . .

RUN apt update

RUN apt install python3-pip -y
RUN pip install jupyterlab metakernel
RUN mkdir -p $(jupyter --data-dir)/kernels/cutlang

RUN apt install -y bison flex make wget

RUN cd /CutLang/CLA && make clean && make
RUN echo "source /CutLang/setup.sh" >> ~/.bashrc
RUN echo "alias python=python3" >> ~/.bashrc

RUN echo "cp /CutLang/kernel/kernel.json $(jupyter --data-dir)/kernels/cutlang/kernel.json" >> ~/.bashrc
RUN echo "cp /CutLang/kernel/magics/cutlangmagic.py $ROOTSYS/lib/JupyROOT/kernel/magics/cutlangmagic.py" >> ~/.bashrc
RUN echo "cp /CutLang/kernel/cutlangmagic.py $ROOTSYS/lib/JupyROOT/magics/cutlangmagic.py" >> ~/.bashrc

WORKDIR /src

CMD [ "tail", "-f", "/dev/null" ]
