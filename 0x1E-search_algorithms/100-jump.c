#include <math.h>
#include <stdio.h>
#include "search_algos.h"


/**
 * jump_search - a function that searches for a value
 * in a sorted array of integers using the Jump search algorithm
 * @array: pointer to array of integers
 * @size: size of array
 * @value: value to search for
 *
 * Return: index of the searched value if found otherwise -1
 */
int jump_search(int *array, size_t size, int value)
{
	int low = 0;
	int high;

	if (array == NULL || size == 0)
		return (-1);
	high = (int)sqrt(size);
	while (array[min_(high, (int)size) - 1] < value)
	{
		printf("Value checked array[%d] = [%d]\n", low, array[low]);
		low = high;
		high = high + (int)sqrt(size);
		if (low >= (int)size)
			return (-1);
	}
	printf("Value found between indexes [%d] and [%d]\n", low, high);
	while (array[low] < value)
	{
		printf("Value checked array[%d] = [%d]\n", low, array[low]);
		low++;
		if (low == min_(high, (int)size))
			return (-1);
	}
	if (array[low] == value)
		return (low);
	else
		return (-1);
}
