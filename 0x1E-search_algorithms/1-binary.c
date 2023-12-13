#include <stdio.h>
#include "search_algos.h"


/**
 * binary_search - function that searches for a value in a sorted array of
 * 		   integers using the binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index where value is located otherwise -1
 */
int binary_search(int *array, size_t size, int value)
{
	int i;
	int low = 0;
	int high = (int)size - 1;
	int mid;

	if (array == NULL || size == 0)
		return (-1);

	while (high >= low)
	{
		mid = low + (high - low) / 2;
		printf("Searching in array:");
		for (i = low; i <= high; i++)
		{
			if (i < high)
				printf("%d, ", array[i]);
			if (i == high)
				printf("%d\n", array[i]);
		}

		if (value == array[mid])
			return (mid);
		else if (value > array[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}
