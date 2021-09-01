#include "search_algos.h"

/**
 * linear_skip - searches for a value in a linked list
 * @list: a pointer to the first element of the linked list
 * @value: value to search for
 * Return: linked list containing value
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *C = list->express, *p = list, *F = NULL;

	if (C == NULL)
		return (NULL);

	if (p->n == value)
		return (p);
	while (p->express)
	{
		printf("Value checked at index [%lu] = [%d]\n", C->index, C->n);
		if (value > C->n)
		{
			p = C;
			C = C->express;
		}
		else
			break;
	}
	if (C == NULL)
	{
		F = p;
		while (F->next)
			F = F->next;
		printf("Value found between indexes [%lu] and [%lu]\n", p->index, F->index);
	}
	else
		printf("Value found between indexes [%lu] and [%lu]\n", p->index, C->index);
	while (p)
	{
		printf("Value checked at index [%lu] = [%d]\n", p->index, p->n);
		if (p->n == value)
			return (p);
		p = p->next;
	}
	return (NULL);
}
