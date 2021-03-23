#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: pointer to a struct
 * @idx: index given
 * @n: data
 *
 * Return: struct needed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *temp = malloc(sizeof(listint_t));
	listint_t *current;
	listint_t *prev;
	int count = 0;

	prev = NULL;
	temp->n = n;
	temp->next = NULL;
	if ((idx < 0) || (idx > listint_len(*head)))
	{
	    return (NULL);
	}
	if (idx == 0)
	{
		temp->next = (*head);
		(*head) = temp;
	}
	for (current = (*head); current != NULL; current = current->next, count++)
	{
		if ((count + 1) == idx)
		{
			prev = current;
		}
		if ((count) >= idx)
		{
			break;
		}
	}
	temp->next = current;
	prev->next = temp;
	return (temp);
}

/**
 * listint_len - a function that prints number of nodes.
 * @h: value of list
 *
 * Return: any data type list
 */
size_t listint_len(const listint_t *h)
{
	const listint_t *temp = h;
	int node = 0;

	while (temp != NULL)
	{
		temp = temp->next;
		node++;
	}
	return (node);
}
