#include "holberton.h"

/**
 * _realloc - function that allocates memory for an array
 * @ptr: number of elements to be allocated
 * @old_size: size
 * @new_size: 
 *
 * Return: pointer to allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	int j = 0, i;
	void *s;

	if (old_size == new_size)
		return (ptr);
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr != NULL)
	{
		s = malloc(new_size);
		for (; j < min(old_size, new_size); j++)
		{
			(char *)s[j] = (char *)ptr[j]
		}
		free(ptr);
	}
	else
		return (NULL);
	return (s);
}

int min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}
