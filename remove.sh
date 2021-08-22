directory_to_remove=$CUTLANG_PATH/runs
PATH=:$PATH:
PATH=${PATH//:$directory_to_remove:/:}
PATH=${PATH#:}; PATH=${PATH%:}

directory_to_remove=$CUTLANG_PATH/scripts
PATH=:$PATH:
PATH=${PATH//:$directory_to_remove:/:}
PATH=${PATH#:}; PATH=${PATH%:}

isProd="${1:-1}"
source $CUTLANG_PATH/scripts/remove_kernel.sh $ROOTSYS $isProd

unset CUTLANG_PATH
