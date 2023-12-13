#include <stdio.h>
#include "search_algos.h"


/**
 * linear_search - a function that searches for a value in an array
 * of integers using the linear search algorithm
 * @array: a pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located otherwise -1
 */
int linear_search(int *array, size_t size, int value)
{
	int i;

	if (array == NULL || size == 0)
		return (-1);

	for (i = 0; i < (int)size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (value == array[i])
			return (i);
	}
	return (-1);
}
