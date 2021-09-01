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
        1, 0, 2, 3, 5};
    size_t size = sizeof(array) / sizeof(array[0]);

    int num = 1;
    printf("Found %d at index: %d\n\n", num, exponential_search(array, size, num));
    return (EXIT_SUCCESS);
}