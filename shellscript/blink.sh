#!/bin/bash

# Array of color codes
colors=("1;31" "1;32" "1;33" "1;34" "1;35" "1;36")

for ((i=0; i<1000; i++))
do
    if ((i%2!=0));then
        clear
        sleep 0.5
        continue
    fi
    # Get the color index for the current iteration
    color_index=$((i % ${#colors[@]}))
    
    # Set the text color and bold formatting
    echo -e "\033[${colors[$color_index]}mHello World\033[0m"
    sleep 0.5
    clear
done