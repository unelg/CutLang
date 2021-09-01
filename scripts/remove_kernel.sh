rm -rf $(jupyter --data-dir)/kernels/cutlang

#rm -rf $(jupyter --data-dir)/kernels/root

rm -rf "$jupyterLabAppDir/settings"

#rm -rf $CUTLANG_PATH/scripts/JsRoot620

isProd=$2
__debug(){
    if [ $isProd == "1" ]; then
        echo $1 > /dev/null 2>&1
    else
        echo $1
    fi
}

filecontrolJupyROOT(){
    if [ -f $2 ]; then
        __debug "File $2 exists. $1 is being removing" 
        __debug ""
        if [ "$1" == "__init__.py" ]; then
            cp "$2.bak" $2
            rm -rf "$2.bak"
        else
            rm -rf $2
        fi
    else
        __debug "ERROR: File $2 does not exists."
    fi
}
rmmJupyROOT(){
    if [ -d "$pythonJupyROOTSitePackagesPath/JupyROOT" ]; then
        __debug "Directory $pythonJupyROOTSitePackagesPath/JupyROOT exists." 
        filecontrolJupyROOT $1 "$pythonJupyROOTSitePackagesPath/JupyROOT/$1"
    else
        __debug "ERROR: Directory $pythonJupyROOTSitePackagesPath/JupyROOT does not exists."
    fi
}

rmmJupyROOT magics/cutlangmagic.py $1
rmmJupyROOT kernel/magics/cutlangmagic.py $1

rmmJupyROOT helpers/cutlang_utils.py $1

rmmJupyROOT kernel/cutlangkernel.py $1

rmmJupyROOT kernel/cutlangkernel.json $1

rmmJupyROOT __init__.py $1

rm -rf $CUTLANG_PATH/scripts/nbmain

# custom.js
cp "$1/etc/notebook/custom/custom.js.bak" "$1/etc/notebook/custom/custom.js"
rm -rf "$1/etc/notebook/custom/custom.js.bak"

cp "$1/etc/notebook/custom/custom.css.bak" "$1/etc/notebook/custom/custom.css"
rm -rf "$1/etc/notebook/custom/custom.css.bak"

rm -rf "$1/etc/notebook/custom/cutlang-logo-200x200.png"
rm -rf "$1/etc/notebook/custom/cutlang-logo-600x200.png"


filecontrolXADL(){
    rm -rf $2
}
rmXADL(){
    if [ -d "$pythonNotebookSitePackagesPath/notebook/static/components/codemirror/mode" ]; then
        __debug "Directory $pythonNotebookSitePackagesPath/notebook/static/components/codemirror/mode exists." 
        filecontrolXADL $1 "$pythonNotebookSitePackagesPath/notebook/static/components/codemirror/mode/text/x-adl/text/$1"
    else
        __debug "ERROR: Directory $pythonNotebookSitePackagesPath/notebook does not exists."
    fi
}

rmXADL x-adl.js $1

# remove_kernel

unset jupyterLabAppDir
unset pythonNotebookSitePackagesPath
unset pythonJupyROOTSitePackagesPath
unset __debug
unset filecontrolJupyROOT
unset rmmJupyROOT
unset filecontrolXADL
unset rmXADL