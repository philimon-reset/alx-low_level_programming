#include "search_algos.h"

/**
 * exponential_search - searches for a value in an array of integers
 * @array: a pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: int
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t i = 1, mid;

	if (array == NULL)
		return (-1);

	while (i < size)
	{
		if (value > array[i])
		{
			printf("Value checked array[%lu] = [%lu]\n", i, array[i]);
			i = i * 2;
		}
		else
			break;
	}
	if (i >= size)
		printf("Value found between indexes [%lu] and [%lu]\n", i / 2, size - 1);
	else
		printf("Value found between indexes [%lu] and [%lu]\n", i / 2, i);
	array = array + (i / 2);
	mid = binary(array, (i / 2), value);
	if (mid == -1)
		return (-1);
	return (mid + i / 2);
}

/**
 * binary - searches for a value in an array of integers
 * @array: a pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: int
 */

int binary(int *array, size_t size, int value)
{
	size_t i, mid;
	int *temp = array;

	while (size > 0)
	{
		printf("Searching in array: ");
		for (i = 0; i < size - 1; i++)
		{
			printf("%d, ", array[i]);
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