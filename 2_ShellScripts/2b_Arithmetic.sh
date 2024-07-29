#!/bin/bash
# Program to demonstrate arithmetic operations using case

flag=0

until [[ $choice -eq 6 ]]
do
    echo "Enter the first number: "
    read num1
    
    echo "Enter the second number: "
    read num2

    echo "Enter the operation to be performed: "
    echo "1) Addition"
    echo "2) Subtraction"
    echo "3) Multiplication"
    echo "4) Division"
    echo "5) Modulo (Remainder)"
    echo "6) Exit"
    read choice

    case "${choice}" in
        1)
            res=$((num1 + num2))
            operation=Addition
            ;;
        2)
            res=$((num1 - num2))
            operation=Subtraction
            ;;
        3)
            res=$((num1 * num2))
            operation=Multiplication
            ;;
        4)
            if [[ $num2 -eq 0 ]]
            then
                echo "Cannot divide by 0"
                flag=1
            else
                res=$((num1 / num2))
                operation=Division
            fi
            ;;
        5)
            if [[ $num2 -eq 0 ]]
            then
                echo "Cannot calculate modulo with 0"
                flag=1
            else
                res=$((num1 % num2))
                operation=Modulo
            fi
            ;;
        6)
            echo "Thank you"
            break
            ;;
        *)
            echo "Wrong Operation chosen, enter again"
            flag=1
            ;;
    esac

    if [[ $flag -eq 1 ]]
    then
        flag=0
        continue
    fi

    echo "The result of the $operation operation is $res"
done
