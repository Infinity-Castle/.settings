#!/bin/bash

display_clock(){
    while true; do
        clear
        echo "Digital clock"
        echo "-------------"
        date +"%d %m %Y %T"
        sleep 1
    done
}

display_clock