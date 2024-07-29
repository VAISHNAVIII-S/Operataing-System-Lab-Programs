#!/bin/bash
# Program to print the Fibonacci series.
echo "Enter the number of Fibonacci numbers to be printed: "
read n
# Initial Fibonacci numbers
f1=0
f2=1
echo "The first $n Fibonacci numbers are: "
for ((i=0; i<n; i++))
do
    if [ $i -eq 0 ]; then
        echo "$f1"
    elif [ $i -eq 1 ]; then
        echo "$f2"
    else
        f3=$((f1 + f2))
        echo "$f3"
        f1=$f2
        f2=$f3
    fi
done
