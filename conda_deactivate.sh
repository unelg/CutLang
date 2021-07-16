directory_to_remove=$ROOTSYS/bin/cutlang/runs
PATH=:$PATH:
PATH=${PATH//:$directory_to_remove:/:}
PATH=${PATH#:}; PATH=${PATH%:}
rm -rf $(jupyter --data-dir)/kernels/cutlang
rm $ROOTSYS/lib/python3.9/site-packages/JupyROOT/magics/cutlangmagic.py
rm $ROOTSYS/lib/python3.9/site-packages/JupyROOT/kernel/magics/cutlangmagic.py

unset ROOTSYS
unset CUTLANG_PATH