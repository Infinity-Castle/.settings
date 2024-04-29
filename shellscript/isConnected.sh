#!bin/bash

target="google.com"

output=$(ping -c 3 $target)

if [[output==*"3 received"]];then
    echo "Connected to a network"
else 
    echo "Not connected to a network"
fi