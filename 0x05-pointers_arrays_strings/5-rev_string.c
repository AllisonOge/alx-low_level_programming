#include "main.h"
#include <string.h>

/**
 * rev_string - reverse a string
 * @s: pointer to string
 */
void rev_string(char *s)
{
	size_t len = strlen(s);

	char *start = s;

	char *end = s + len - 1;

	while (start < end)
	{
		char temp = *start;

		*start++ = *end;

		*end-- = temp;
	}
}
