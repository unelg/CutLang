#!/bin/bash

echo $'Errors: \n' | tee ./errors.txt
cat ./raw_output.txt | grep -A10 -B5 --colour -e error -e WARNING -e syntax -e Aborted | tee -a ./errors.txt
