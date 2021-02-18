#include "holberton.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: captitalized letter
 *
 * Return: void function
 */

char *cap_string(char *s)
{
	int i = 0;
	char arr[] = {',', ';', '.', '!', '?', '"', '(', ')', '{',
		      '}', '\t', '\n', ' '};

	if (s[i] >= 'a' && s[i] <= 'z')
	{
		s[i] -= 32;
		i++;
	}
	while (s[i] != '\0')
	{
		if (separator(s[i]))
		{
			s[i + 1] -= 32;
		}
		else if ((str[i + 1] >= 'a' && str[i + 1] <= 'z'))
		{
			s[i + 1] -= 32;
		}
		i++;
	}
	return (s)
}

int separator (char c)
{
	char arr[13] = {',', ';', '.', '!', '?', '"', '(', ')', '{',
		      '}', '\t', '\n', ' '};
	int a, var;

	for (a = 0; a < 13; a++)
	{
		if (c == arr[a])
			var = 1;
	}
	return (var);
}