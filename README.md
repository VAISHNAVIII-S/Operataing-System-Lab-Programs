# Operating System Lab Programs

This repository contains a collection of 12 lab programs related to the Operating System course. Each program is designed to help understand different concepts of operating systems such as process management, memory management, and CPU scheduling.

## Table of Contents

1. [Week 1 - Shell Scripting Basics](#week-1)
2. [Week 2 - Fibonacci and Arithmetic Operations](#week-2)
3. [Week 3 - Shell Scripts and Process Management](#week-3)
4. [Week 4 - Simulation of Commands](#week-4)
5. [Week 5 - File I/O Operations](#week-5)
6. [Week 6 - Producer-Consumer Problem](#week-6)
7. [Week 7 - Fibonacci and Prime Numbers](#week-7)
8. [Week 8 - Multithreading](#week-8)
9. [Week 9 - CPU Scheduling (SJF)](#week-9)
10. [Week 10 - CPU Scheduling (Priority)](#week-10)
11. [Week 11 - Round Robin Scheduling](#week-11)
12. [Week 12 - Mutex and Semaphores](#week-12)

## Week 1

*Exposure to Linux Operating System and Environment*

- Write Shell Scripts for the following:
  - Concatenation of two strings
  - Comparison of two strings
  - Maximum of three numbers

## Week 2

*Write Shell Scripts for the following:*

- Fibonacci series
- Arithmetic operation using case

## Week 3

*Write Shell Scripts for the following:*

- Finding largest of N numbers (storing numbers in an array)
- Generating prime numbers
- Reading two matrices and finding sum

## Week 4

*Simulation of ls, rm, cat and grep commands using system calls*

## Week 5

*Write a program to perform the following tasks using I/O system calls for file I/O:*

- Reading first 10 characters from file
- Skipping 5 characters from current position in the file
- Going to 5th last character in the file
- Going to the 3rd character in the file

## Week 6

*Program to implement Producer-consumer problem using the following shared memory methods:*

- Using shm_open and mmap
- Using shmget and shmat

## Week 7

*Write a program to generate and print Fibonacci series with the following requirements:*

- Parent program should create a child and distribute the task of generating Fibonacci series to its child.
- The code for generating Fibonacci series should reside in a different program.
- Child should write the generated Fibonacci series to a shared memory.
- Parent process has to print by retrieving the Fibonacci series from the shared memory.

*Write a program to generate and print Prime numbers between a given range (between M & N) with the following requirements:*

- M & N should be passed as command line arguments
- Error checking should be done to verify the required number of arguments at the command line

## Week 8

*Write a program with two threads and a main thread. Schedule the task of calculating the natural sum up to 'n' terms and factorial of 'n' on these threads.*

- The main thread should read 'n' from command line and pass it as parameter to remaining threads. Terminate the threads using system calls.

*Implement FCFS scheduling algorithm by defining the process structure.*

## Week 9

*Implement the following CPU scheduling algorithms by defining the process structure:*

- SJF
- SJF (Preemptive)

## Week 10

*Implement the following CPU scheduling algorithms by defining the process structure:*

- Priority
- Priority (Preemptive)

## Week 11

*Implement Round Robin CPU scheduling algorithm with arrival time by defining the process structure.*

## Week 12

*Implement the following using mutex and semaphores:*

- Producer – Consumer problem
- Reader’s writers’ problem

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
