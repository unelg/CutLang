#!/bin/bash

echo $'Efficacy Charts:\n' | tee ./efficacy_charts.txt 
cat ./raw_output.txt | grep -e Overall -e .adl -e SOD -e DELPHES | tee -a ./efficacy_charts.txt
echo $'Errors: \n' | tee ./errors.txt
cat ./raw_output.txt | grep -e 0x000 -e error -e segmentation -e WARNING -e ROOT -e aborting -e Fatal -e stack | tee -a ./errors.txt
