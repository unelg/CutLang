FROM rootproject/root:6.24.00-ubuntu20.04

RUN apt update

RUN apt install python3-pip -y
RUN pip install jupyterlab metakernel
RUN mkdir -p $(jupyter --data-dir)/kernels/cutlang

RUN apt install -y bison flex make
RUN echo "alias python=python3" >> ~/.bashrc
RUN echo "source /src/setup.sh" >> ~/.bashrc

RUN echo "cp /src/kernel/kernel.json $(jupyter --data-dir)/kernels/cutlang/kernel.json" >> ~/.bashrc
RUN echo "cp /src/kernel/magics/cutlangmagic.py $ROOTSYS/lib/JupyROOT/kernel/magics/cutlangmagic.py" >> ~/.bashrc
RUN echo "cp /src/kernel/cutlangmagic.py $ROOTSYS/lib/JupyROOT/magics/cutlangmagic.py" >> ~/.bashrc

WORKDIR /src

CMD [ "tail", "-f", "/dev/null" ]