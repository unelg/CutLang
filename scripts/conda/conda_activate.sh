#if [ -n "${ROOTSYS}" ] ; then
#   export old_rootsys_before_CLA=${ROOTSYS}
#fi

export CUTLANG_PATH=$CONDA_PREFIX/bin/cutlang
export PATH=$CUTLANG_PATH/runs:$CUTLANG_PATH/scripts:$PATH
export CUTLANG_JUPYTER_DATA_DIR=$(jupyter --data-dir)

#source $CUTLANG_PATH/scripts/conda/root_unset_for_conda.sh

mkdir -p $CUTLANG_JUPYTER_DATA_DIR/kernels/cutlang

cp $CUTLANG_PATH/kernel/kernel.json $CUTLANG_JUPYTER_DATA_DIR/kernels/cutlang/kernel.json

cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $CONDA_PREFIX/lib/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $CONDA_PREFIX/lib/python3.9/site-packages/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $CONDA_PREFIX/lib/python3.8/site-packages/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $CONDA_PREFIX/lib/python3.7/site-packages/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $CONDA_PREFIX/lib/python3.6/site-packages/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null

cp $CUTLANG_PATH/kernel/magics/shellmagic.py $CONDA_PREFIX/lib/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/shellmagic.py $CONDA_PREFIX/lib/python3.9/site-packages/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/shellmagic.py $CONDA_PREFIX/lib/python3.8/site-packages/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/shellmagic.py $CONDA_PREFIX/lib/python3.7/site-packages/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/shellmagic.py $CONDA_PREFIX/lib/python3.6/site-packages/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null

cp $CUTLANG_PATH/kernel/cutlangmagic.py $CONDA_PREFIX/lib/JupyROOT/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/cutlangmagic.py $CONDA_PREFIX/lib/python3.9/site-packages/JupyROOT/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/cutlangmagic.py $CONDA_PREFIX/lib/python3.8/site-packages/JupyROOT/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/cutlangmagic.py $CONDA_PREFIX/lib/python3.7/site-packages/JupyROOT/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/cutlangmagic.py $CONDA_PREFIX/lib/python3.6/site-packages/JupyROOT/magics/cutlangmagic.py 2>>/dev/null

cp $CUTLANG_PATH/kernel/shellmagic.py $CONDA_PREFIX/lib/JupyROOT/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/shellmagic.py $CONDA_PREFIX/lib/python3.9/site-packages/JupyROOT/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/shellmagic.py $CONDA_PREFIX/lib/python3.8/site-packages/JupyROOT/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/shellmagic.py $CONDA_PREFIX/lib/python3.7/site-packages/JupyROOT/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/shellmagic.py $CONDA_PREFIX/lib/python3.6/site-packages/JupyROOT/magics/shellmagic.py 2>>/dev/null

echo "For examples see $CUTLANG_PATH/runs/"
echo "and for LHC analysis implementations, see"
echo "https://github.com/ADL4HEP/ADLLHCanalyses"