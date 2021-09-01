#include "search_algos.h"

/**
 * linear_skip - searches for a value in a linked list
 * @list: a pointer to the first element of the linked list
 * @value: value to search for
 * Return: linked list containing value
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp = list->express, *prev = list;

	if (temp == NULL)
		return (NULL);
	while (temp)
	{
		printf("Value checked at index [%lu] = [%d]\n", temp->index, temp->n);
		if (value > temp->n)
		{
			prev = temp;
			temp = temp->express;
		}
		else
			break;
	}
	if (temp == NULL)
		printf("Value found between indexes [%lu] and [%lu]\n", prev->index, prev->index);
	else
		printf("Value found between indexes [%lu] and [%lu]\n", prev->index, temp->index);
	while (prev)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}