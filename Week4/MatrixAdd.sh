#!/bin/bash

# Declare associative arrays to store matrices
declare -A X
declare -A Y
declare -A Z

# Read the first 3x3 matrix
echo "Enter the elements of the first 3x3 matrix:"
for ((i = 0; i < 3; i++)); do
    for ((j = 0; j < 3; j++)); do
        read -p "X[$i,$j]: " X[$i,$j]
    done
done

# Read the second 3x3 matrix
echo "Enter the elements of the second 3x3 matrix:"
for ((i = 0; i < 3; i++)); do
    for ((j = 0; j < 3; j++)); do
        read -p "Y[$i,$j]: " Y[$i,$j]
    done
done

# Display the input matrices
echo "The input matrices are:"
echo "Matrix X:"
for ((i = 0; i < 3; i++)); do
    for ((j = 0; j < 3; j++)); do
        echo -ne "${X[$i,$j]} "
    done
    echo
done

echo "Matrix Y:"
for ((i = 0; i < 3; i++)); do
    for ((j = 0; j < 3; j++)); do
        echo -ne "${Y[$i,$j]} "
    done
    echo
done

# Calculate and display the resultant matrix
echo "The resultant matrix Z (X + Y) is:"
for ((i = 0; i < 3; i++)); do
    for ((j = 0; j < 3; j++)); do
        Z[$i,$j]=$((X[$i,$j] + Y[$i,$j]))
        echo -ne "${Z[$i,$j]} "
    done
    echo
done







# Output:

# Enter the elements of the first 3x3 matrix:
# X[0,0]: 1
# X[0,1]: 2
# X[0,2]: 3
# X[1,0]: 5
# X[1,1]: 6
# X[1,2]: 1
# X[2,0]: 2
# X[2,1]: 3
# X[2,2]: 5
# Enter the elements of the second 3x3 matrix:
# Y[0,0]: 6
# Y[0,1]: 6
# Y[0,2]: 8
# Y[1,0]: 1
# Y[1,1]: 1
# Y[1,2]: 1
# Y[2,0]: 1
# Y[2,1]: 3
# Y[2,2]: 4
# The input matrices are:
# Matrix X:
# 1 2 3 
# 5 6 1 
# 2 3 5 
# Matrix Y:
# 6 6 8 
# 1 1 1 
# 1 3 4 
# The resultant matrix Z (X + Y) is:
# 7 8 11 
# 6 7 2 
# 3 6 9 
