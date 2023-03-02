#include "main.h"
#include <string.h>

/**
 * _strncat - concatenate two strings
 * @dest: pointer to destination
 * @src: pointer to source
 * @n: maximum number of bytes used from src
 *
 * Return: pointer to result of dest appended to src
 */
char *_strncat(char *dest, char *src, int n)
{
	return (strncat(dest, src, n));
}
