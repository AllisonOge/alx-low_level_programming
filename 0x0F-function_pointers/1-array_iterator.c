#include <stddef.h>
#include "function_pointers.h"

/**
 * array_iterator - executes callback on array
 * @array: array pointer
 * @size: size of the array
 * @action: callback func
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i = 0;

	if (!action || !array)
		return;

	while (i < size)
	{
		action(array[i]);
		i++;
	}
}
