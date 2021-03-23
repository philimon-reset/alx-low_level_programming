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
	listint_t *c;
	listint_t *prev;
	unsigned int i = 0;

	prev = NULL;
	temp->n = n;
	temp->next = NULL;
	if (*head != NULL)
	{
		if (idx > list_len(*head))
		{
			return (NULL);
		}
		if (idx == 0)
		{
			temp->next = (*head);
			(*head) = temp;
		}
		for (c = (*head); (c != NULL) && (idx != 0); c = c->next, i++)
		{
			if ((i + 1) == idx)
			{
				prev = c;
			}
			if ((i) >= idx)
			{
				temp->next = c;
				if (prev != NULL)
					prev->next = temp;
				break;
			}
		}	
	}
	return (temp);
}

/**
 * list_len - a function that prints number of nodes.
 * @h: value of list
 *
 * Return: any data type list
 */
size_t list_len(const listint_t *h)
{
	const listint_t *temp = h;
	unsigned int node = 0;

	while (temp != NULL)
	{
		temp = temp->next;
		node++;
	}
	return (node);
}
