#include "main.h"

/**
 * _strncpy - similar to strncpy
 * @dest: pointer to destination
 * @src: pointer to source
 * @n: maximum number of bytes to copy
 * Return: pointer to destination
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
