#!/bin/bash
# Program to find the largest of the given array of numbers

# Read the size of the array
echo "Enter the size of the array: "
read n

# Initialize the array
declare -a arr

# Read the elements of the array
echo "Enter the elements of the array: "
for ((i=0; i<n; i++))
do
    read arr[i]
done

# Initialize the max variable with the first element of the array
max=${arr[0]}

# Loop through the array to find the largest element
for ((i=1; i<n; i++))
do
    if (( arr[i] > max ))
    then
        max=${arr[i]}
    fi
done

# Print the largest number
echo "The largest of the given numbers is $max"




# Output:

# Enter the size of the array: 
# 6
# Enter the elements of the array: 
# 34
# 56
# 78
# 99
# 21
# 34
# The largest of the given numbers is 99
