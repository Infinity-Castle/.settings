#!/bin/bash

read -p "Enter value of n:" n

read -a numbers



echo "original array: ${numbers[@]}"

sorted=($(printf "%s\n" "${numbers[@]}" | sort -n))

echo "Sorted Array: ${sorted[@]}"