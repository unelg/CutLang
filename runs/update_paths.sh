#!/bin/bash

# Function to convert lines in a file to absolute paths
convert_to_abs_path() {
    local file=$1
    local tmpfile=$(mktemp)

    while IFS= read -r line; do
        # Convert the line to its absolute path
        if [[ -e "$line" ]]; then
            realpath "$line" >> "$tmpfile"
            
            # If the line points to another txt file, recurse
            if [[ "$line" == *.txt ]]; then
                convert_to_abs_path "$line"
            fi
        else
            echo "$line" >> "$tmpfile"  # Preserve the line if no file/folder matches
        fi
    done < "$file"

    # Move the temporary file contents to the original file
    mv "$tmpfile" "$file"
}

# Check for file input
if [[ $# -ne 1 ]]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

input_file=$1
if [[ ! -e $input_file ]]; then
    echo "File does not exist: $input_file"
    exit 1
fi

convert_to_abs_path "$input_file"

