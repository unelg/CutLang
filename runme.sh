#!/bin/bash

if [ ! -d "/path/to/dir" ]; then 
 git submodule add https://github.com/ADL4HEP/ADLLHCanalyses
fi

cd CLA;
make -j

if [  $? -eq 0 ]; then
 cd ../runs;
fi
