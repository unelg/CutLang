export CUTLANG_PATH="$( cd "$( dirname "${BASH_SOURCE[0]:-${(%):-%x}}" )" && pwd )"
export PATH=$CUTLANG_PATH/runs:$CUTLANG_PATH/scripts:$PATH


if python -c "import IPython" &> /dev/null; then
    echo "IPython is installed."
    isProd="${1:-1}"
    source $CUTLANG_PATH/scripts/setup_kernel.sh $ROOTSYS $isProd
    echo "done. CLA, CLA_compile,... are now available."
else
    echo "done. CLA, CLA_compile,... are now available."
    echo "But, IPython is not installed. You might want to install it if you want to use jupiter notebooks."
fi

