export CUTLANG_PATH="$( cd "$( dirname "${BASH_SOURCE[0]:-${(%):-%x}}" )" && pwd )"
export PATH=$CUTLANG_PATH/runs:$CUTLANG_PATH/scripts:$PATH

isProd="${1:-1}"
source $CUTLANG_PATH/scripts/setup_kernel.sh $ROOTSYS $isProd