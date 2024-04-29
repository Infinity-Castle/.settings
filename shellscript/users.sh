#!/bin/bash

# Check if the 'who' command is available
if ! command -v who &> /dev/null; then
    echo "The 'who' command is not available on this system."
    exit 1
fi

# Get the list of logged-in users
users=$(who | awk '{print $1}' | sort | uniq)

# Check if there are any logged-in users
if [ -z "$users" ]; then
    echo "There are no users currently logged in."
else
    echo "Users currently logged in:"
    echo "$users"
fi