#include <stdio.h>
#include <stdlib.h>

/**
 * Calculates the average of the grades.
 */
double calculateAverage(double * grades, int numGrades) {
    double sum = 0.0;
    double average = 0.0;

    for (int i = 0; i < numGrades; i++) {
        sum += *(grades + i);
    } // for

    if (numGrades > 0) {
        average = sum / numGrades;
    } // if

    return (average);
} // calculateAverage

/**
 * Prints the grades and compares them to the average.
 */
void printGrades(double * grades, int numGrades, double average) {
    printf("The average of %d grades is %f.\n", numGrades, average);

    for (int i = 0; i < numGrades; i++) {
        printf("%d. The grade of %f is ", i + 1, *(grades + i));

        if (*(grades + i) >= average) {
            printf(">= the average.\n");
        } else {
            printf("< the average.\n");
        } // if
    } // for
} // printGrades

/**
 * Maps out its dynamic memory usage as the program executes to solve a simple
 * problem of computing the average grade of a list of grades and determining which
 * grades are >= or < the average. Processes grades from standard input (inputted
 * by a user or redirected from an input file) and store them on the heap.
 */
int main() {
    double * grades;

    int numGrades = 0;
    int allocatedGrades = 5;

    double first; // Stores the first value
    double input; // Stores the input
    double average; // Stores the average

    int bytes = 0;
    int countAllocs = 0;
    int countFrees = 0;
    int totalBytes = 0;

    int i = 0;
    int j = 1;

    //Reading input from user
    printf("Enter a list of grades below where each grade is separated by newline character.\n");
    printf("After the last grade is entered, enter a negative value to end the list.\n");
    scanf("%lf", &input);

    if (input >= 0) {
        first = input;
        bytes = 40;
        totalBytes = 40;
        numGrades++;

        grades = (double *) malloc(allocatedGrades * sizeof(double));
        countAllocs++;

        printf("Allocated %d bytes to the heap at %p.\n", bytes, (void *)grades);

        while (input >= 0) {
            *(grades + i) = input;

            printf("Stored %lf in the heap at %p.\n", input, (void *)(grades + i));
            i++;

            if (numGrades == allocatedGrades) {
                printf("Stored %d grades (%d bytes) to the heap at ", numGrades, bytes);
                printf("%p.\n", (void *)grades);
                printf("Heap at %p is full.\n", (void *)grades);

                allocatedGrades += 5;
                free(grades);
                if (grades == NULL) {
                    printf("NULL\n");
                } else {
                    printf("NOT FREED\n");
                }
                grades = (double *) malloc(allocatedGrades * sizeof(double));
                countAllocs++;

                bytes += 40;
                totalBytes += bytes;
                printf("Allocated %d bytes to the heap at %p.\n", bytes, (void *)grades);

                for (int i = 0; i < numGrades; i++) {
                    *(grades + i) = *(grades - numGrades - j + i);
                } // for

                printf("Copied %d grades from ", allocatedGrades - 5);
                printf("%p to %p.\n", (void *)(grades - numGrades - j), (void *)grades);
                printf("Freed %d bytes from the heap at ", bytes - 40);
                printf("%p.\n", (void *)(grades - numGrades - j));
                j++;

                countFrees++;

            } // if

            scanf("%lf", &input);

            if (input >= 0) {
                numGrades++;
            } // if
        } // while
    } // if

    // Calculates the average
    *grades = first;
    average = calculateAverage(grades, numGrades);

    // Prints the grades
    printGrades(grades, numGrades, average);

    // Frees the memory
    if (numGrades > 0) {
        free(grades);
        countFrees++;
        printf("Freed %d bytes from the heap at %p.\n", bytes, (void *)grades);
    } // if

    printf("total heap usage: %d allocs, %d frees, ", countAllocs, countFrees);
    printf("%d bytes allocated\n", totalBytes);

    return 0;
}
