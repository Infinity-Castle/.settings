#!/bin/bash

# Take filename as input
read -p "Enter the filename: " filename

# Check if the file is executable
if [ -x "$filename" ]; then
    echo "$filename is executable."
    # Remove execute permissions
    chmod -x "$filename"
    echo "Execute permissions removed from $filename."
else
    echo "$filename is not executable."
fi
