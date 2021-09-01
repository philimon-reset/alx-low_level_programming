#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    int array[] = {
        0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 54, 61, 62, 76, 99};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 0, exponential_search(array, size, 0));
    printf("Found %d at index: %d\n\n", 4, exponential_search(array, size, 4));
    printf("Found %d at index: %d\n", 99, exponential_search(array, size, 99));
    return (EXIT_SUCCESS);
}