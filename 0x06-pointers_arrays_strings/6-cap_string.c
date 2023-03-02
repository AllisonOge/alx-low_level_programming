#include "main.h"
#include <ctype.h>
#include <string.h>

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

	char separators[] = " \t\n,.!?\"(){}";

	for (; *p != '\0'; p++)
		if (strchr(separators, *p) != NULL)
			capitalize_next = 1;

		else if (capitalize_next)
		{
			*p = toupper(*p);
			capitalize_next = 0;
		}

	return (s);
}
