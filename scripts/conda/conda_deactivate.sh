$CUTLANG_PATH/scripts/remove_kernel.sh $CONDA_PREFIX 1

source $CUTLANG_PATH/scripts/conda/oldroot_set_for_conda.sh

directory_to_remove=$CUTLANG_PATH/runs
PATH=:$PATH:
PATH=${PATH//:$directory_to_remove:/:}
PATH=${PATH#:}; PATH=${PATH%:}

directory_to_remove=$CUTLANG_PATH/scripts
PATH=:$PATH:
PATH=${PATH//:$directory_to_remove:/:}
PATH=${PATH#:}; PATH=${PATH%:}

unset CUTLANG_PATH
