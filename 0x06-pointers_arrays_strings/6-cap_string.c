#include "main.h"
#include <ctype.h>

/**
 * cap_string - capitalize all words of a string
 * @s: string
 *
 * Return: result
 */
char *cap_string(char *s)
{
	char *p = s;

	int capitalize_next = 1;

	for (; *p != '\0'; p++)
		if (isspace(*p))
			capitalize_next = 1;

		else if (capitalize_next)
		{
			*p = toupper(*p);
			capitalize_next = 0;
		}

	return (s);
}
