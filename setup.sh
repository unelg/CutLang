export CUTLANG_PATH="$( cd "$( dirname "${BASH_SOURCE[0]:-${(%):-%x}}" )" && pwd )"
export PATH=$CUTLANG_PATH/runs:$CUTLANG_PATH/scripts:$PATH

$CUTLANG_PATH/scripts/setup_kernel.sh 2>> /dev/null