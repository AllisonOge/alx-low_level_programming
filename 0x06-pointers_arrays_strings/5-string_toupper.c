#include "main.h"
#include <ctype.h>

/**
 * string_toupper - change all lowercase letter to uppercase
 * @s: pointer to string
 *
 * Return: result
 */
char *string_toupper(char *s)
{
	char *p = s;

	for (; *p != '\0'; p++)
		*p = toupper(*p);

	return (s);
}
