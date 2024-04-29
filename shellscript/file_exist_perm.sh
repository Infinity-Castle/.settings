#!/bin/bash

read -p "Enter file name: " file_name

# check if doesn't exists

if [ -e "$file_name"];then
    echo "File doesn't exist"
fi

if [ -x "$file_name"]; then
    echo "File is executable"
else 
    echo "File is not executable"
fi