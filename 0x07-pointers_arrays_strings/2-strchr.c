#include "main.h"
#include <string.h>

/**
 * _strchr - search for a character in a sstring
 * @s: pointer to string to be searched
 * @c: character to be located
 *
 * Return: pointer to the first occurrence of the character c in the string s
 */
char *_strchr(char *s, char c)
{
	return (strchr(s, c));
}
