#include <stdio.h>
#include "search_algos.h"


/**
 * interpolation_search - a function that searches for a value
 * in a sorted array of integers using the Interpolation search algorithm
 * @array: pointer to array of integers
 * @size: size of the array
 * @value: value to search for
 *
 * Return: index of the value found otherwise -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	int low = 0;
	int high = (int)size - 1;
	size_t mid;

	if (array == NULL || size == 0)
		return (-1);

	mid = low + (((double)(high - low) /
					    (array[high] - array[low])) *
					    (value - array[low]));

	while ((array[low] != array[high]) &&
		   (value >= array[low]) &&
		   (array[high] >= value))
	{
		printf("Value checked array[%d] = [%d]\n", (int)mid, array[mid]);
		if (value > array[mid])
			low = (int)(mid + 1);
		else if (value < array[mid])
			high = (int)(mid - 1);
		else
			return ((int)mid);
		mid = low + (((double)(high - low) /
					  (array[high] - array[low])) *
					  (value - array[low]));
	}
	if (value == array[low])
		return (low);
	printf("Value checked array[%d] is out of range\n", (int)mid);
	return (-1);
}
