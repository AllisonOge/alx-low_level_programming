#include "main.h"
#include <ctype.h>

/**
 * rot13 - encode a string using rot13
 * @s: string
 *
 * Return: encoded string
 */
char *rot13(char *s)
{
	int i;

	char *p = s;

	char r[] = "amnz";

	int code[] = {13, 13, -13, -13};

	for (; *p != '\0'; p++)
		for (i = 0; i < 4; i += 2)
			if ((*p >= tolower(r[i]) && *p <= tolower(r[i + 1]))
			|| (*p >= toupper(r[i]) && *p <= toupper(r[i + 1])))
			{
				*p += code[i];
				break;
			}
	return (s);
}
