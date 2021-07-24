directory_to_remove=$CONDA_PREFIX/bin/cutlang/runs
PATH=:$PATH:
PATH=${PATH//:$directory_to_remove:/:}
PATH=${PATH#:}; PATH=${PATH%:}

#rm -rf $CUTLANG_JUPYTER_DATA_DIR/kernels/cutlang

#rm $ROOTSYS/lib/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.9/site-packages/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.8/site-packages/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.7/site-packages/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.6/site-packages/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null

#rm $ROOTSYS/lib/JupyROOT/magics/cutlangmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.9/site-packages/JupyROOT/magics/cutlangmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.8/site-packages/JupyROOT/magics/cutlangmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.7/site-packages/JupyROOT/magics/cutlangmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.6/site-packages/JupyROOT/magics/cutlangmagic.py 2>>/dev/null

#rm $ROOTSYS/lib/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.9/site-packages/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.8/site-packages/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.7/site-packages/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.6/site-packages/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null

#rm $ROOTSYS/lib/JupyROOT/magics/shellmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.9/site-packages/JupyROOT/magics/shellmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.8/site-packages/JupyROOT/magics/shellmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.7/site-packages/JupyROOT/magics/shellmagic.py 2>>/dev/null
#rm $ROOTSYS/lib/python3.6/site-packages/JupyROOT/magics/shellmagic.py 2>>/dev/null

source $CUTLANG_PATH/root_set_for_conda.sh

unset CUTLANG_PATH
unset CUTLANG_JUPYTER_DATA_DIR

#if [ -n "${old_rootsys_before_CLA}" ] ; then
#   source $old_rootsys_before_CLA/bin/thisroot.sh
#fi

#unset old_rootsys_before_CLA