#!/bin/bash

echo $'Efficacy Charts:\n' | tee ./efficacy_charts.txt 
cat ./raw_output.txt | grep -e Overall -e .adl -e SOD -e DELPHES | tee -a ./efficacy_charts.txt
