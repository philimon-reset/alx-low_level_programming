#include "search_algos.h"

/**
 * advanced_binary - searches for a value in an array of integers
 * @array: a pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: int
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t i;
	int mid, temp;

	if (array == NULL)
		return (-1);
	printf("Searching in array: ");
	for (i = 0; i < size - 1; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[size - 1]);
	if (size == 1)
	{
		if (*array == value)
			return (0);
		return (-1);
	}
	if (size == 2)
	{
		if (array[0] == value)
			return (0);
		if (array[1] == value)
			return (1);
	}
	mid = size % 2 == 0 ? (size / 2) - 1 : size / 2;
	if (array[mid] >= value)
		return (advanced_binary(array, size / 2, value));
	if (array[mid] < value)
	{
		temp = advanced_binary(array + mid + 1, size / 2, value);
		return (temp != -1 ? temp + (mid + 1) : -1);
	}
	return (-1);
}
