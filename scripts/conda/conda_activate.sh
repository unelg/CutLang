export CUTLANG_PATH=$CONDA_PREFIX/bin/cutlang
export PATH=$CUTLANG_PATH/runs:$CUTLANG_PATH/scripts:$PATH

#source $CUTLANG_PATH/scripts/conda/root_unset_for_conda.sh

$CUTLANG_PATH/scripts/setup_kernel.sh $CONDA_PREFIX 1

echo "For examples see $CUTLANG_PATH/runs/"
echo "and for LHC analysis implementations, see"
echo "https://github.com/ADL4HEP/ADLLHCanalyses"