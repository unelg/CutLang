export ROOTSYS=$CONDA_PREFIX
export CUTLANG_PATH=$ROOTSYS/bin/cutlang
export PATH=$CUTLANG_PATH/runs:$PATH

mkdir -p $(jupyter --data-dir)/kernels/cutlang

cp $CUTLANG_PATH/kernel/kernel.json $(jupyter --data-dir)/kernels/cutlang/kernel.json
cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $ROOTSYS/lib/python3.9/site-packages/JupyROOT/kernel/magics/cutlangmagic.py
cp $CUTLANG_PATH/kernel/cutlangmagic.py $ROOTSYS/lib/python3.9/site-packages/JupyROOT/magics/cutlangmagic.py