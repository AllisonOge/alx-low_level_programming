#include "main.h"
#include <string.h>

/**
 * _strpbrk - search a string for any of a set of bytes
 * @s: pointer to string to be searched
 * @accept: pointer to substring used to search
 *
 * Return: a pointer to the bytes in s that matces on of the bytes in accept
 * Otherwise NULL
 */
char *_strpbrk(char *s, char *accept)
{
	return (strpbrk(s, accept));
}
