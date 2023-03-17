#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocate memory for an array using malloc
 * @nmemb: number of array elements
 * @size: size of each element
 *
 * Return: a void pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *arr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	/* allocate memory for array */
	arr = malloc(nmemb * size);

	if (arr == NULL)
		return (NULL);

	return (arr);
}