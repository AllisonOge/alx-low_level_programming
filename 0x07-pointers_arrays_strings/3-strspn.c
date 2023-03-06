#include "main.h"
#include <string.h>

/**
 * _strspn - get the length of a prefix substring
 * @s: pointer to string
 * @accept: substring used to get length
 *
 * Return: number of bytes in the initial segment
 */
unsigned int _strspn(char *s, char *accept)
{
	return (strspn(s, accept));
}
