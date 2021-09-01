#include "search_algos.h"

/**
 * jump_list - searches for a value in an array of integers
 * @list: a pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: int
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t a = 0, b = 0;
	listint_t *temp = list;

	if (temp == NULL)
		return (-1);

	while ((array[b] < value) && (b) < size)
	{
		a = b;
		printf("Value checked array[%lu] = [%d]\n", b, array[b]);
		b += sqrt(size);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", a, b);
	for (; a <= size - 1; a++)
	{
		printf("Value checked array[%lu] = [%d]\n", a, array[a]);
		if (array[a] == value)
			return (a);
	}
	return (NULL);
}