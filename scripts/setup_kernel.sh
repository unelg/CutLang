mkdir -p $(jupyter --data-dir)/kernels/cutlang
cp $CUTLANG_PATH/scripts/jupyter/kernel/cutlangkernel.json $(jupyter --data-dir)/kernels/cutlang/kernel.json
cp $CUTLANG_PATH/scripts/jupyter/cutlang-logo-200x200.png $(jupyter --data-dir)/kernels/cutlang/logo-64x64.png

#mkdir -p $(jupyter --data-dir)/kernels/root
#cp $1/etc/notebook/kernels/root/kernel.json $(jupyter --data-dir)/kernels/root/kernel.json
#cp $1/etc/notebook/kernels/root/logo-64x64.png $(jupyter --data-dir)/kernels/root/logo-64x64.png

jupyterLabAppDir=$(jupyter lab path | grep Application | awk -v RS='[: ]' 1 | grep jupyter/lab)
mkdir -p "$jupyterLabAppDir/settings"
cp "$CUTLANG_PATH/scripts/jupyter/settings/overrides.json" "$jupyterLabAppDir/settings/overrides.json"

pythonNotebookSitePackagesPath=$(dirname $(python -c "import notebook as _; print(_.__path__)" | awk -v RS="[:']" 1 | grep notebook))
pythonJupyROOTSitePackagesPath=$(dirname $(python -c "import JupyROOT as _; print(_.__path__)" | awk -v RS="[:']" 1 | grep JupyROOT))

isProd=$2
__debug(){
    if [ $isProd == "1" ]; then
        echo $1 > /dev/null 2>&1
    else
        echo $1
    fi
}

filecontrolJupyROOT(){
    if [ -f "$CUTLANG_PATH/scripts/jupyter/$1" ]; then
        __debug "File $CUTLANG_PATH/scripts/jupyter/$1 exists. $1 is being copying" 
        __debug ""
        if [ "$1" == "__init__.py" ]; then
            if [ -f "$3.bak" ]; then
                __debug "File $3.bak exists. Nothing" 
            else
                cp $3 "$3.bak"
            fi
        fi
        cp $2 $3
    else
        __debug "ERROR: File $CUTLANG_PATH/scripts/jupyter/$1 does not exists."
    fi
}
cpJupyROOT(){
    if [ -d "$pythonJupyROOTSitePackagesPath/JupyROOT" ]; then
        __debug "Directory $pythonJupyROOTSitePackagesPath/JupyROOT exists." 
        filecontrolJupyROOT $1 "$CUTLANG_PATH/scripts/jupyter/$1" "$pythonJupyROOTSitePackagesPath/JupyROOT/$1"
    else
        __debug "ERROR: Directory $pythonJupyROOTSitePackagesPath/JupyROOT does not exists."
    fi
}

cpJupyROOT magics/cutlangmagic.py $1
cpJupyROOT kernel/magics/cutlangmagic.py $1

cpJupyROOT helpers/cutlang_utils.py $1

cpJupyROOT kernel/cutlangkernel.py $1

cpJupyROOT kernel/cutlangkernel.json $1

cpJupyROOT __init__.py $1


# custom.js
if [ -f "$1/etc/notebook/custom/custom.js.bak" ]; then
    __debug "File $1/etc/notebook/custom/custom.js.bak exists. Nothing" 
else
    __debug "File $1/etc/notebook/custom/custom.js.bak does not exists. $1/etc/notebook/custom/custom.js is being copying"
    cp "$1/etc/notebook/custom/custom.js" "$1/etc/notebook/custom/custom.js.bak"
fi
cp "$CUTLANG_PATH/scripts/jupyter/custom/custom.js" "$1/etc/notebook/custom/custom.js"

if [ -f "$1/etc/notebook/custom/custom.css.bak" ]; then
    __debug "File $1/etc/notebook/custom/custom.css.bak exists. Nothing" 
else
    __debug "File $1/etc/notebook/custom/custom.css.bak does not exists. $1/etc/notebook/custom/custom.css is being copying"
    cp "$1/etc/notebook/custom/custom.css" "$1/etc/notebook/custom/custom.css.bak"
fi
cp "$CUTLANG_PATH/scripts/jupyter/custom/custom.css" "$1/etc/notebook/custom/custom.css"

cp "$CUTLANG_PATH/scripts/jupyter/cutlang-logo-200x200.png" "$1/etc/notebook/custom/cutlang-logo-200x200.png"
cp "$CUTLANG_PATH/scripts/jupyter/cutlang-logo-600x200.png" "$1/etc/notebook/custom/cutlang-logo-600x200.png"


filecontrolXADL(){
    xAdlDirname=$(dirname $3)
    mkdir -p $xAdlDirname
    cp $2 $3
}
cpXADL(){
    if [ -d "$pythonNotebookSitePackagesPath/notebook/static/components/codemirror/mode" ]; then
        __debug "Directory $pythonNotebookSitePackagesPath/notebook/static/components/codemirror/mode exists." 
        filecontrolXADL $1 "$CUTLANG_PATH/scripts/jupyter/$1" "$pythonNotebookSitePackagesPath/notebook/static/components/codemirror/mode/text/x-adl/text/$1"
    else
        __debug "ERROR: Directory $pythonNotebookSitePackagesPath/notebook does not exists."
    fi
}

cpXADL x-adl.js $1

# setup_kernel

unset __debug
unset filecontrolJupyROOT
unset cpJupyROOT
unset filecontrolXADL
unset cpXADL