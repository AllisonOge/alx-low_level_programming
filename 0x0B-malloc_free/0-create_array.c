#include "main.h"
#include <stdlib.h>

/**
 * create_array - create an array of chars
 * @size: size of the array
 * @c: initial value
 *
 * Return: pointer to array if size is non-zero otherwise NULL
 */
char *create_array(unsigned int size, char c)
{
	
	unsigned int i;
	char *arr = NULL;

	if (size == 0)
		return (NULL);
	arr = (char *)  malloc(sizeof(char) * size);

	for (i = 0; i < size; i++)
		arr[i] = c;

	return (arr);
}
