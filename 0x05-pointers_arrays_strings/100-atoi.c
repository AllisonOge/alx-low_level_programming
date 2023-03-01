#include "main.h"
#include <stdlib.h>
#include <ctype.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: converted string
 */
int _atoi(char *s)
{
	char cleaned_string[256];

	int i, j = 0;

	for (i = 0; s[i] != '\0'; i++)
		if (isdigit(s[i]) || (s[i] == '-' && j == 0))
		{
			cleaned_string[j] = s[i];
			j++;
		}
	cleaned_string[j] = '\0';

	return (atoi(cleaned_string));
}
