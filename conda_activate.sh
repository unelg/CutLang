if [ -n "${ROOTSYS}" ] ; then
   export old_rootsys_before_CLA=${ROOTSYS}
fi

export CUTLANG_PATH=$CONDA_PREFIX/bin/cutlang
export PATH=$CUTLANG_PATH/runs:$PATH
export CUTLANG_JUPYTER_DATA_DIR=$(jupyter --data-dir)

source $CUTLANG_PATH/root_reset_for_conda.sh

mkdir -p $CUTLANG_JUPYTER_DATA_DIR/kernels/cutlang

cp $CUTLANG_PATH/kernel/kernel.json $CUTLANG_JUPYTER_DATA_DIR/kernels/cutlang/kernel.json

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