export CUTLANG_PATH="$( dirname $( cd "$( dirname "${BASH_SOURCE[0]:-${(%):-%x}}" )" && pwd ) )"
export PATH=$CUTLANG_PATH/runs:$CUTLANG_PATH/scripts:$PATH