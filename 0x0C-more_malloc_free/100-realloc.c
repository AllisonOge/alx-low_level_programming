#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocate a memory block using malloc and free
 * @ptr: pointer to the previously allocated memory
 * @old_size: size in bytes of the allocated space for ptr
 * @new_size: new size in bytes of the new memory block
 *
 * Return: void pointer to the reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newPtr;
	unsigned int i;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		newPtr = malloc(new_size);

	else if (new_size <= old_size)
		newPtr = ptr;
	else
	{
		/* reallocate memory */
		newPtr = malloc(new_size);
		if (newPtr == NULL)
			return (NULL);
		for (i = 0; i < old_size && i < new_size; i++)
			((char *)newPtr)[i] = ((char *)ptr)[i];
		free(ptr);
	}

	return (newPtr);
}
