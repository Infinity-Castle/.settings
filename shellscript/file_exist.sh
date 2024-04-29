#!/bin/bash
read -p "Enter the path to the file: " file_path
if [ -e "$file_path" ]; then
    echo "File '$file_path' exists."
else
    echo "File '$file_path' does not exist."
fi