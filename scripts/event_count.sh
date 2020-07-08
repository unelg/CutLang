#!/bin/bash

export PATH=$PATH:$ROOTSYS/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib:.:/usr/lib:/usr/lib/system:../CLA/

root -l $1 <<-EOF
TTree *srctree = dynamic_cast<TTree*>(_file0->Get("events")); cout << srctree->GetEntries();
EOF
