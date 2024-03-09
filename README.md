# Heap Dynamic Memory
This project involves developing a C program to explore dynamic memory management and pointers by creating a program that computes the average grade of a list of grades. The program will also determine which grades are above or below the average. The primary focus is on understanding heap memory allocation and deallocation, pointer manipulation, and memory management in C programming.

## Design Overview
The project revolves around a C program structured to utilize dynamic memory allocation for storing grades on the heap. The design includes robust handling of memory allocation, ensuring efficient storage and management of grades while adhering to dynamic memory allocation principles.

## Functionality
`grade_processor.c`:
- Utilizes dynamic memory allocation and deallocation to store grades on the heap.
- Processes grades from standard input until a sentinel value (negative input) is encountered, indicating the end of input.
- Implements strategies to optimize memory usage, including resizing of memory allocation to accommodate additional grades efficiently.
- Computes the average grade from the input list of grades, excluding the sentinel value.
- Determines and prints grades that are above or below the computed average.

## File Structure and Content
```
heap-dynamic-memory/
├── grade_processor.c
├── Makefile
└── resources/
    ├── input1.txt
    ├── input2.txt
    ├── output1.txt
    └── output2.txt
```