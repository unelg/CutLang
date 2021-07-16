directory_to_remove=$CONDA_PREFIX/bin/cutlang/runs
PATH=:$PATH:
PATH=${PATH//:$directory_to_remove:/:}
PATH=${PATH#:}; PATH=${PATH%:}

rm -rf $(jupyter --data-dir)/kernels/cutlang

rm $ROOTSYS/lib/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null
rm $ROOTSYS/lib/python3.9/site-packages/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null

rm $ROOTSYS/lib/JupyROOT/magics/cutlangmagic.py 2>>/dev/null
rm $ROOTSYS/lib/python3.9/site-packages/JupyROOT/magics/cutlangmagic.py 2>>/dev/null

unset CUTLANG_PATH