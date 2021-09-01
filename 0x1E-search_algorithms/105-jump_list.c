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
	listint_t *temp = list, *b = list, *a = NULL;
	size_t val = 0;

	if (temp == NULL)
		return (NULL);
	while ((b->n < value) && (b->index) < size)
	{
		a = b;
		val += sqrt(size);
		if (val >= size)
		{
			val = size - 1;
			b = find(temp, val);
			printf("Value checked at index[%lu] = [%d]\n", b->index, b->n);
			break;
		}
		b = find(temp, val);
		printf("Value checked at index[%lu] = [%d]\n", b->index, b->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", a->index, b->index);
	while (a)
	{
		printf("Value checked at index[%lu] = [%d]\n", a->index, a->n);
		if (a->n == value)
			return (a);
		a = a->next;
	}
	return (NULL);
}

/**
 * find - find content of a listint_t
 *
 * @list: Pointer to the head of the list
 * @b: node with value to be found
 *
 * Return: list of index
 */
listint_t *find(listint_t *list, size_t b)
{
	printf("val is %lu\n", b);
	while (list)
	{
		if (list->index == b)
			return (list);
		list = list->next;
	}
	return (list);
}
