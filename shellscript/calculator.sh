#!/bin/bash

add(){
    echo "$1+$2" | bc
}

sub(){
    echo "$1-$2" | bc
}

multi(){
    echo "$1*$2" | bc
}

div(){
    echo "$1/$2" | bc
}

main(){
    echo "Welcome"

    while true; do
        echo "Select Operation"
        echo "1: Addition"
        echo "2: Subtraction"
        echo "3: Multiplication"
        echo "4: Division"
        echo "5: Exit"

        read -p "Enter first number:" num1
        read -p "Enter second number:" num2

        read -p "Enter your choice:" choice

        case $choice in
            1)
                result=$(add $num1 $num2)
                echo "Result: $result"
                ;;
            2)
                result=$(sub $num1 $num2)
                echo "Result: $result"
                ;;
            3)
                result=$(multi $num1 $num2)
                echo "Result: $result"
                ;;
            4)
                result=$(div $num1 $num2)
                echo "Result: $result"
                ;;
            5)
                exit 0
                ;;
            *)
                echo "invalid choice"
        esac

    done
}

main