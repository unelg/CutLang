#!/bin/bash

echo $'Efficiency Charts:\n\n' | tee ./final_res.txt 
cat ./output.txt | grep -e Overall -e .adl -e SOD -e DELPHES | tee -a ./final_res.txt
echo $'\n\nErrors:\n\n' | tee -a ./final_res.txt
cat ./output.txt | grep -e 0x000 -e error -e segmentation -e WARNING -e ROOT -e aborting -e Fatal -e stack | tee -a ./final_res.txt
sed -i 's/nan/[undefined]/g' final_res.txt
