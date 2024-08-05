#!/bin/bash
# Program to generate the prime numbers within a given range

echo "Enter the lower bound: "
read n1
echo "Enter the upper bound: "
read n2

# Ensure n1 is at least 2 because there are no prime numbers less than 2
if [ "$n1" -lt 2 ]; then
    n1=2
fi

for ((i=n1; i<=n2; i++))
do
    flag=0
    if [ "$i" -eq 2 ]; then
        # 2 is a prime number
        echo -ne "$i "
        continue
    fi

    # Check if i is divisible by any number from 2 to sqrt(i)
    for ((j=2; j*j<=i; j++))
    do
        if [ $((i % j)) -eq 0 ]; then
            flag=1
            break
        fi
    done

    if [ $flag -eq 0 ]; then
        echo -ne "$i "
    fi
done
echo





#Output:
#  Enter the lower bound: 
#  5
#  Enter the upper bound: 
#  25
#  5 7 11 13 17 19 23 
