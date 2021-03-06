#include "holberton.h"

/**
 * create_array - function to create array
 * @size: size of array
 * @c: specific char to initaliize
 *
 * Return: NULL if size 0
 */

char *create_array(unsigned int size, char c)
{
	char *str;

	if (size == 0)
		return (NULL);
	str = malloc(sizeof(char) * size);
	if (str != NULL)
	{
		while (size--)
		{
			str[size] = c;
		}
	}
	else
		return (NULL);
	return (str);
}
