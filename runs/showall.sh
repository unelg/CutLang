#!/bin/bash

htxtfile=BP_1-histos.txt
rootfile=histoOut-CLA.root
regno=1


printUsage() {
	echo "Usage: $0 [region_id=${regno}] [rootfile=${rootfile}]"
	exit 0
}

showAll() {
	cat ${htxtfile} | cut -f2 -d'"' | cut -f1 -d','  | grep -v Basics > histoname.txt
	root.exe -l -q -x showall.C"(${regno} , \"${rootfile}\")"
	exit 0
}

if [ $# == 0 ]; then

	showAll

elif [ $# == 1 ]; then
	if [ $1 == '-h' ]; then
		printUsage
	fi
	regno=$1
	htxtfile=BP_${regno}-histos.txt

	showAll

elif [ $# == 2 ]; then
	
	regno=$1
	rootfile=$2
	htxtfile=BP_${regno}-histos.txt

	showAll
else
	printUsage
fi
