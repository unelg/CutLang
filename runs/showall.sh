#!/bin/bash

htxtfile=BP_1-card.ini
rootfile=histoOut-CLA.root
regname=preselection


printUsage() {
	echo "Usage: $0 [region_id=${regname}] [rootfile=${rootfile}]"
	exit 0
}

showAll() {
	cat ${htxtfile} | grep histo | grep -v Basics |  awk '{print $2}'| cut -f1 -d','| grep -v histo > histoname.txt
	root.exe -l -q -x showall.C"(\"${regname}\" , \"${rootfile}\")"
	exit 0
}

if [ $# == 0 ]; then
	showAll
elif [ $# == 1 ]; then
	if [ $1 == '-h' ]; then
		printUsage
	fi
	regname=$1
	htxtfile=BP_${regno}-card.ini
	showAll

elif [ $# == 2 ]; then
	regname=$1
	rootfile=$2
	htxtfile=BP_1-card.ini
	showAll
else
	printUsage
fi
