#include <stddef.h>
#include "function_pointers.h"

/**
 * int_index - search for an integer
 * @array: array to search
 * @size: number of elements in the array
 * @cmp: callback func to compare values
 *
 * Return: index of the first match, otherwize -1 if no matches or size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (!array || !cmp)
		return (-1);
	if (size <= 0)
		return (-1);

	while (i < size)
	{
		if (cmp(array[i]) != 0)
			return (i);
		i++;
	}
	return (-1);
}
