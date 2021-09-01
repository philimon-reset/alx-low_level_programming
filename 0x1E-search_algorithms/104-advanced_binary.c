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
	size_t i, mid;
	int *temp = array;

	if (array == NULL)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size - 1; i++)
		printf("%d, ", temp[i]);
	printf("%d\n", temp[i]);
	if (size % 2 == 0)
		mid = (size / 2) - 1;
	else
		mid = size / 2;
	if (value == temp[mid])
	{
		if ((temp[mid + 1] == temp[mid]) && (temp[mid - 1] != temp[mid]))
		{
			return (&(temp[mid]) - array);
		}
		else if (temp[mid - 1] == temp[mid])
			return (advanced_binary(temp, mid + 1, value));
		else
			return (&(temp[mid]) - array);
	}
	else if ((value > temp[mid]) && size > 1)
	{
		return (advanced_binary((temp + (mid + 1)), size / 2, value));
	}
	else if ((value < temp[mid]) && size > 1)
	{
		return (advanced_binary(temp, mid, value));
	}
	return (-1);
}
