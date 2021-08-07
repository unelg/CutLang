mkdir -p $(jupyter --data-dir)/kernels/cutlang

cp $CUTLANG_PATH/kernel/kernel.json $(jupyter --data-dir)/kernels/cutlang/kernel.json

cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $ROOTSYS/lib/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $ROOTSYS/lib/python3.9/site-packages/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $ROOTSYS/lib/python3.8/site-packages/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $ROOTSYS/lib/python3.7/site-packages/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $ROOTSYS/lib/python3.6/site-packages/JupyROOT/kernel/magics/cutlangmagic.py 2>>/dev/null

cp $CUTLANG_PATH/kernel/magics/shellmagic.py $ROOTSYS/lib/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/shellmagic.py $ROOTSYS/lib/python3.9/site-packages/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/shellmagic.py $ROOTSYS/lib/python3.8/site-packages/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/shellmagic.py $ROOTSYS/lib/python3.7/site-packages/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/magics/shellmagic.py $ROOTSYS/lib/python3.6/site-packages/JupyROOT/kernel/magics/shellmagic.py 2>>/dev/null

cp $CUTLANG_PATH/kernel/cutlangmagic.py $ROOTSYS/lib/JupyROOT/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/cutlangmagic.py $ROOTSYS/lib/python3.9/site-packages/JupyROOT/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/cutlangmagic.py $ROOTSYS/lib/python3.8/site-packages/JupyROOT/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/cutlangmagic.py $ROOTSYS/lib/python3.7/site-packages/JupyROOT/magics/cutlangmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/cutlangmagic.py $ROOTSYS/lib/python3.6/site-packages/JupyROOT/magics/cutlangmagic.py 2>>/dev/null

cp $CUTLANG_PATH/kernel/shellmagic.py $ROOTSYS/lib/JupyROOT/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/shellmagic.py $ROOTSYS/lib/python3.9/site-packages/JupyROOT/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/shellmagic.py $ROOTSYS/lib/python3.8/site-packages/JupyROOT/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/shellmagic.py $ROOTSYS/lib/python3.7/site-packages/JupyROOT/magics/shellmagic.py 2>>/dev/null
cp $CUTLANG_PATH/kernel/shellmagic.py $ROOTSYS/lib/python3.6/site-packages/JupyROOT/magics/shellmagic.py 2>>/dev/null

# setup_kernel