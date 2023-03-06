#include "main.h"
#include <string.h>

/**
 * _memset - fills memory with constant byte
 * @s: pointer to memory area
 * @b: byte to be filled
 * @n: times to fill byte
 *
 * Return: pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	return (memset(s, b, n));
}
