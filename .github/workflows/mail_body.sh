#!/bin/bash

cd $HOME/work/CutLang/CutLang/.github/workflows/artifacts

cat raw_output.txt | grep -e error -e WARNING -e syntax -e CLA.sh | tee ./temp.txt
a=''
for i in $(cat temp.txt | grep -A1 -e CLA.sh); do
  if [ $`echo $a | grep -q CLA.sh` == $`echo $i | grep -q CLA.sh` ]; then
    sed -i -e 's/$a//g' ./temp.txt
  fi
  a='$i'
done
