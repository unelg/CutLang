#!/bin/bash

echo $'Errors: \n' | tee ./errors.txt
python3 filter_errors.py