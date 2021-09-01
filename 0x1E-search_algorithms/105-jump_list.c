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
	size_t val = 0, S = 0;

	if (temp == NULL)
		return (-1);
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

void free_list(listint_t *list);

/**
 * create_list - Creates a single linked list
 *
 * @array: Pointer to the array to use to fill the list
 * @size: Size of the array
 *
 * Return: A pointer to the head of the created list (NULL on failure)
 */
listint_t *create_list(int *array, size_t size)
{
	listint_t *list;
	listint_t *node;

	list = NULL;
	while (array && size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
		{
			free_list(list);
			return (NULL);
		}
		node->n = array[size];
		node->index = size;
		node->next = list;
		list = node;
	}
	return (list);
}

/**
 * free_list - Deallocates a singly linked list
 *
 * @list: Pointer to the linked list to be freed
 */
void free_list(listint_t *list)
{
	listint_t *node;

	if (list)
	{
		node = list->next;
		free(list);
		free_list(node);
	}
}

/**
 * print_list - Prints the content of a listint_t
 *
 * @list: Pointer to the head of the list
 */
void print_list(const listint_t *list)
{
	printf("List :\n");
	while (list)
	{
		printf("Index[%lu] = [%d]\n", list->index, list->n);
		list = list->next;
	}
	printf("\n");
}

/**
 * find - find content of a listint_t
 *
 * @list: Pointer to the head of the list
 * @b: node with value to be found
 */
listint_t *find(const listint_t *list, size_t b)
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
