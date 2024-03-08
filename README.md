# Heap Dynamic Memory
This program tracks its dynamic memory usage as it executes to solve a simple problem of computing the average grade of a list of grades and determining which grades are greater than or less than the average. It processes grades from standard input (entered by a user or redirected from an input file) and stores them on the heap.

## Design Overview
The program dynamically allocates memory on the heap to store grades entered by the user. It increases the allocated memory size when needed and maintains statistics about memory allocation and deallocation. The design ensures efficient memory usage and proper management of memory resources.

## Functionality
The program dynamically allocates memory on the heap to store grades entered by the user. Upon execution, it prompts the user to input a list of grades, where each grade is separated by a newline character. After entering the grades, the user can terminate the input list by entering a negative value. The program dynamically adjusts the allocated memory size as needed to accommodate the entered grades, ensuring efficient memory usage. Once all grades are entered, the program calculates the average grade and compares each grade with the calculated average. It then prints whether each grade is greater than or less than the average. Additionally, the program tracks and displays statistics on memory allocation and deallocation during its execution, providing insights into its dynamic memory usage behavior.

## File Structure and Content
- **proj2.c**: contains the main logic of the program. It handles memory tracking, grade input from the user, calculation of the average grade, comparison of each grade with the average, and outputting the results. Additionally, it tracks statistics on memory allocation and deallocation throughout the program's execution.

## Compilation and Run
The program can be compiled by
'''
$ gcc proj2.c -o proj2.out
'''
and run by
'''
$ ./proj2.out <filepath>
'''
- <filepath>: the path of the file containing a list of grades.
