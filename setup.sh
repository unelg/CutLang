export CUTLANG_PATH="$( cd "$( dirname "${BASH_SOURCE[0]:-${(%):-%x}}" )" && pwd )"
export PATH=$CUTLANG_PATH/runs:$PATH

$CUTLANG_PATH/scripts/setup_kernel.sh