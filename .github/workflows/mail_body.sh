#!/bin/bash

cd $HOME/work/CutLang/CutLang/.github/workflows/artifacts

. $HOME/work/CutLang/CutLang/build/bin/thisroot.sh
root --version 2>&1 | tee ./temp2.txt
echo "" | tee -a temp2.txt
cat raw_output.txt | grep -e error -e WARNING -e syntax -e CLA.sh | tee ./temp.txt

a=''
while IFS='' read -r i || [ -n "$i" ]; do
        if echo $i | grep -q -e "Check the input file"; then
                echo $a | tee -a temp2.txt
                echo $i | tee -a temp2.txt
                echo "" | tee -a temp2.txt
	elif echo $i | grep -q Aborted; then
		if echo $a | grep -q "Check the input file"; then
			a=$i
			continue
		else
	                echo $a | tee -a temp2.txt
        	        echo $i | tee -a temp2.txt
                	echo "" | tee -a temp2.txt
		fi
        elif echo $i | grep -q error; then
                echo $a | tee -a temp2.txt
        fi
        a=$i
done < ./temp.txt

rm temp.txt
mv temp2.txt temp.txt
