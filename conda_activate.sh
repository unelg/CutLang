export CUTLANG_PATH=$CONDA_PREFIX/bin/cutlang
export PATH=$CUTLANG_PATH/runs:$PATH
export CUTLANG_JUPYTER_DATA_DIR=$(jupyter --data-dir)

mkdir -p $CUTLANG_JUPYTER_DATA_DIR/kernels/cutlang

cp $CUTLANG_PATH/kernel/kernel.json $CUTLANG_JUPYTER_DATA_DIR/kernels/cutlang/kernel.json

cp $ROOTSYS/lib/JupyROOT/kernel/rootkernel.py $ROOTSYS/lib/JupyROOT/kernel/rootkernel_with_cutlang.py 2>>/dev/null
cp $ROOTSYS/lib/python3.9/site-packages/JupyROOT/kernel/rootkernel.py $ROOTSYS/lib/python3.9/site-packages/JupyROOT/kernel/rootkernel_with_cutlang.py 2>>/dev/null

cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $ROOTSYS/lib/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $ROOTSYS/lib/python3.9/site-packages/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null

cp $CUTLANG_PATH/kernel/magics/shellmagic.py $ROOTSYS/lib/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/shellmagic.py $ROOTSYS/lib/python3.9/site-packages/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null

cp $CUTLANG_PATH/kernel/cutlangmagic.py $ROOTSYS/lib/JupyROOT/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/cutlangmagic.py $ROOTSYS/lib/python3.9/site-packages/JupyROOT/magics/cutlangmagic.py 2>>/dev/null

cp $CUTLANG_PATH/kernel/shellmagic.py $ROOTSYS/lib/JupyROOT/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/shellmagic.py $ROOTSYS/lib/python3.9/site-packages/JupyROOT/magics/shellmagic.py 2>>/dev/null

echo "For examples see $CUTLANG_PATH/runs/"
echo "and for LHC analysis implementations, see"
echo "https://github.com/ADL4HEP/ADLLHCanalyses"