#include "search_algos.h"

/**
 * interpolation_search - searches for a value in an array of integers
 * @array: a pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: int
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t mid = 0, low = 0, high = size - 1;

	if (array == NULL)
		return (-1);
	if (array[0] == value)
	{
		printf("Value checked array[%lu] = [%d]\n", mid, array[mid]);
		return (mid);
	}

	if (size % 2 == 0)
		mid = (size / 2) - 1;
	else
		mid = size / 2;
	if (value == array[mid])
	{
		printf("Value checked array[%lu] = [%d]\n", mid, array[mid]);
		return (mid);
	}
	mid = probe(low, high, value, array);
	while (mid < size && low != high)
	{
		printf("Value checked array[%lu] = [%d]\n", mid, array[mid]);
		if (value == array[mid])
			return (mid);
		else if (value > array[mid])
			low = mid + 1;
		else if (value < array[mid])
			high = mid - 1;
		mid = probe(low, high, value, array);
	}
	printf("Value checked array[%lu] is out of range\n", mid);
	return (-1);
}

/**
 * probe - probe position
 * @l: lowest index
 * @h: highest index
 * @v: value to be found
 * @a: array to be used
 * Return: prob value
 */

size_t probe(size_t l, size_t h, int v, int *a)
{
	size_t prob;

	prob = l + (((double)(h - l) / (a[h] - a[l])) * (v - a[l]));
	return (prob);
}
