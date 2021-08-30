#include "search_algos.h"

/**
 * binary_search - searches for a value in an array of integers
 * @array: a pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: int
 */

int binary_search(int *array, size_t size, int value)
{
	size_t i, mid;
	int *temp = array;

	while (size > 0)
	{
		printf("Searching in array: ");
		for (i = 0; i < size - 1; i++)
		{
			printf("%d,", array[i]);
		}
		printf("%d\n", array[i]);
		if (size % 2 == 0)
			mid = (size / 2) - 1;
		else
			mid = size / 2;
		if (value == array[mid])
			return (&(array[mid]) - temp);
		else if ((value > array[mid]) && size > 1)
		{
			array = array + (mid + 1);
			size = size / 2;
		}
		else if ((value < array[mid]) && size > 1)
			size = mid;
		else
			break;
	}
	return (-1);
}