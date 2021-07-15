mkdir $(jupyter --data-dir)/kernels/cutlang

cp $CUTLANG_PATH/kernel/kernel.json $(jupyter --data-dir)/kernels/cutlang/kernel.json
cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $ROOTSYS/lib/JupyROOT/kernel/magics/cutlangmagic.py
cp $CUTLANG_PATH/kernel/magics/cutlangmagic.py $ROOTSYS/lib/python3.9/site-packages/JupyROOT/kernel/magics/cutlangmagic.py
cp $CUTLANG_PATH/kernel/cutlangmagic.py $ROOTSYS/lib/JupyROOT/magics/cutlangmagic.py
cp $CUTLANG_PATH/kernel/cutlangmagic.py $ROOTSYS/lib/python3.9/site-packages/JupyROOT/magics/cutlangmagic.py