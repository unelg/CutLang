#!/bin/bash

echo $'Efficacy Charts:\n' | tee ./efficacy_charts.txt 
cat ./raw_output.txt | grep -e Overall -e .adl -e SOD -e DELPHES | tee -a ./efficacy_charts.txt
echo $'Errors: \n' | tee ./errors.txt
cat ./raw_output.txt | grep -A5 -B5 --colour -i error -i warning -i check -i syntax | tee -a ./errors.txt
