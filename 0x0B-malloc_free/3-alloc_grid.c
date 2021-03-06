#include "holberton.h"

/**
 * alloc_grid - function to create pointer to 2d array
 * @width: width
 * @height: height
 *
 * Return: NULL if size 0
 */

int **alloc_grid(int width, int height)
{
	int j = 0, i;
	int **array;

	if (width <= 0 || height <= 0)
		return (NULL);
	array = malloc(sizeof(int *) * height);
	if (array != NULL)
	{
		for (; j < height; j++)
		{
			array[j] = malloc(sizeof(int) * width);
			if (array[j] != NULL)
			{
				for (i = 0; i < width; i++)
					array[j][i] = 0;
			}
			else
			{
				while (j >= 0)
				{
					free(array[j]);
					j--;
				}
				free(array);
				return (NULL);
			}
		}
	}
	else
		return (NULL);
	return (array);
}
