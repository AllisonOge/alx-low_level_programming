#include "main.h"
#include <string.h>

/**
 * _memcpy - copies memory area
 * @dest: pointer to memory area
 * @src: pointer to source to be copied
 * @n: number of bytes to copy
 *
 * Return: pointer to memory area dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	return (memcpy(dest, src, n));
}
