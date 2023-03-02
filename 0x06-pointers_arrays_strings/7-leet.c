#include "main.h"
#include <ctype.h>

/**
 * leet - encode string into 1337
 * @s: string
 *
 * Return: encode string
 */
char *leet(char *s)
{
	char *p = s;

	for (; *p != '\0'; p++)
	{
		*p = tolower(*p);

		if (*p == 'a')
			*p = '4';
		else if (*p == 'e')
			*p = '3';
		else if (*p == 'i')
			*p = '0';
		else if (*p == 'o')
			*p = '7';
		else if (*p == 'u')
			*p = '1';
	}

	return (s);
}
