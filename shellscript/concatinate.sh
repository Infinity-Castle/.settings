#!/bin/bash

# Check if at least two arguments are provided
if [ "$#" -lt 2 ]; then
    echo "Usage: $0 <file1> <file2> [<file3>...]"
    exit 1
fi

# Loop through the arguments
for file in "$@"; do
    # Check if the file exists
    if [ ! -f "$file" ]; then
        echo "Error: $file does not exist."
        exit 1
    fi
done

# Concatenate the files
cat "$@"