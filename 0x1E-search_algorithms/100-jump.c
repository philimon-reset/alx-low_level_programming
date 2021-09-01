#include "search_algos.h"

/**
 * jump_search - searches for a value in an array of integers
 * @array: a pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: int
 */

int jump_search(int *array, size_t size, int value)
{
	size_t a = 0, b = 0;

	if (array == NULL)
		return (-1);

	while ((array[b] < value) && (b) < size)
	{
		a = b;
		b += sqrt(size);
		if (b >= size)
		{
			b = size - 1;
			printf("Value checked array[%lu] = [%d]\n", b, array[b]);
			break;
		}
		printf("Value checked array[%lu] = [%d]\n", b, array[b]);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", a, b);
	for (; a <= size - 1; a++)
	{
		printf("Value checked array[%lu] = [%d]\n", a, array[a]);
		if (array[a] == value)
			return (a);
	}
	return (-1);
}
