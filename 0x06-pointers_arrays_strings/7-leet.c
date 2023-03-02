#include "main.h"

/**
 * leet - encode string into 1337
 * @s: string
 *
 * Return: encode string
 */
char *leet(char *s)
{
	int i, len = 10;

	char *p = s;

	char *v = "aAeEoOtTlL";

	char *code = "4433007711";

	for (; *p != '\0'; p++)
		for (i = 0; i < len; i++)
			if (*p == v[i])
				*p = code[i];

	return (s);
}
