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
	int i, len = 5;

	char *p = s;

	char *v = "aeiou";

	char *code = "43071";

	for (; *p != '\0'; p++)
	{
		*p = tolower(*p);

		for (i = 0; i < len; i++)
			if (*p == v[i])
				*p = code[i];
	}

	return (s);
}
