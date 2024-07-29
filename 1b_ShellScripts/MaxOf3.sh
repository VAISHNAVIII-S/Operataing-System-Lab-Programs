#!/bin/bash
echo "ENTER THREE NUMBERS"
read num1
read num2
read num3
# Initialize largest to the first number
if [[ $num1 -gt $num2 ]]
then
    largest=$num1
else
    largest=$num2
fi
# Compare largest with the third number
if [[ $largest -lt $num3 ]]
then
    largest=$num3
fi
echo "THE LARGEST OF THREE NUMBERS IS $largest"
