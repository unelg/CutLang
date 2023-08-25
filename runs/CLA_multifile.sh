#!/bin/bash

# Default values
OUTPUT_TO_INPUT_DIR=false
KEEP_ORIGINAL_NAMES=false  # Flag to keep original output file names

# Capture first two positional arguments
FILELIST=$(realpath "$1")
DATATYPE="$2"
shift 2  # remove these two arguments from $@

# Variables to capture additional arguments
EXTRA_ARGS=""

# Parse remaining command line arguments
while [[ $# -gt 0 ]]
do
key="$1"

case $key in
    -i)
    ADLFILE="$2"
    shift # past argument
    shift # past value
    ;;
    -o)
    OUTPUT_TO_INPUT_DIR=true
    shift # past argument
    ;;
    -n)
    KEEP_ORIGINAL_NAMES=true
    shift # past argument
    ;;
    *)
    EXTRA_ARGS="$EXTRA_ARGS $1"  # Capture extra arguments
    shift # past unknown option
    ;;
esac
done

# Convert FILELIST entries to their full paths
TEMP_FILELIST=$(mktemp)
while IFS= read -r line; do
    realpath "$line" >> "$TEMP_FILELIST"
done < "$FILELIST"

# Fetch the full path of the ADL file
ADLFILE_FULL_PATH=$(realpath "$ADLFILE")

FILELIST_NAME=$(basename "$FILELIST" .txt)
ADLFILE_NAME=$(basename "$ADLFILE" .adl) # Assuming .adl extension; adjust as needed

# Check if all required arguments are provided
if [ -z "$DATATYPE" ] || [ -z "$FILELIST" ] || [ -z "$ADLFILE" ]; then
    echo "Usage: ./CLA_multifile.sh INPUT_FILELIST DATATYPE -i ADLFILE [-o] [-n] [EXTRA_ARGS...]"
    exit 1
fi

# Without the -o flag, create a single directory before the loop
if ! $OUTPUT_TO_INPUT_DIR; then
    OUTPUT_DIRECTORY="${FILELIST_NAME}_${ADLFILE_NAME}"
    if [[ -d $OUTPUT_DIRECTORY ]]; then
        # Determine the next available directory name with format directoryName(n)
        counter=1
        while [[ -d "$OUTPUT_DIRECTORY($counter)" ]]; do
            ((counter++))
        done

        OUTPUT_DIRECTORY="$OUTPUT_DIRECTORY($counter)"
    fi
    mkdir -p "$OUTPUT_DIRECTORY"
    cp "$FILELIST" "$OUTPUT_DIRECTORY/"
fi

# Initialize line counter
LINE_COUNTER=0

# Process each file in the filelist
while IFS= read -r DATAFILE
do
    ((LINE_COUNTER++)) # Increment line counter

    # Determine the base output filename
    INPUT_FILENAME=$(basename "$DATAFILE" .root)
    BASE_OUTPUT_FILE="histoOut-$LINE_COUNTER.root"

    # If -n is provided, keep the original name, else rename
    if ! $KEEP_ORIGINAL_NAMES; then
        BASE_OUTPUT_FILE="histoOut-$LINE_COUNTER.root"
    fi

    # If OUTPUT_TO_INPUT_DIR is true, create a new directory for every single file
    if $OUTPUT_TO_INPUT_DIR; then
        INPUT_DIR=$(dirname "$DATAFILE")
        SUBDIRECTORY="${FILELIST_NAME}_${ADLFILE_NAME}_${LINE_COUNTER}"

        if [[ -d "$INPUT_DIR/$SUBDIRECTORY" ]]; then
            # Determine the next available subdirectory name with format subDirectoryName(n)
            counter=1
            while [[ -d "$INPUT_DIR/$SUBDIRECTORY($counter)" ]]; do
                ((counter++))
            done

            SUBDIRECTORY="$SUBDIRECTORY($counter)"
        fi
        mkdir -p "$INPUT_DIR/$SUBDIRECTORY"
        cp "$FILELIST" "$INPUT_DIR/$SUBDIRECTORY"
        cd "$INPUT_DIR/$SUBDIRECTORY"
    else
        cd "$OUTPUT_DIRECTORY"
    fi

    # Run the CLA command
    if $KEEP_ORIGINAL_NAMES; then
    	CLA "$DATAFILE" "$DATATYPE" -i "$ADLFILE_FULL_PATH" -n $EXTRA_ARGS
    else
    	CLA "$DATAFILE" "$DATATYPE" -i "$ADLFILE_FULL_PATH" $EXTRA_ARGS
    fi
    # Rename the last created output file only if KEEP_ORIGINAL_NAMES is false
    # Get the name of the latest modified file
    LATEST_MODIFIED_FILE=$(ls -t | head -1)
    
    # Check if it matches the 'histoOut-' pattern and if $KEEP_ORIGINAL_NAMES is not set
    if [[ "$LATEST_MODIFIED_FILE" == histoOut-* ]] && ! $KEEP_ORIGINAL_NAMES; then
        mv "$LATEST_MODIFIED_FILE" "$BASE_OUTPUT_FILE"
    fi


    # Return to the original directory for the next iteration
    cd -

done < "$TEMP_FILELIST"

# Cleanup
rm "$TEMP_FILELIST"

