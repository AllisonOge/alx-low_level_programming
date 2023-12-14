#include <stdio.h>
#include "search_algos.h"


/**
 * binary_search_iterative - iterative binary search
 * @array: pointer to array of integers
 * @low: lower index
 * @high: higher index
 * @value: value to search for
 *
 * Return: index of the value found otherwise -1
 */
int binary_search_iterative(int *array, int low, int high, int value)
{
	int i;
	int mid;

	while (high >= low)
	{
		mid = low + (high - low) / 2;
		printf("Searching in array: ");
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

/**
 * exponential_search - a function that searches for a value
 * in a sorted array of integers using the Exponential search algorithm
 * @array: pointer to array of integers
 * @size: size of the array
 * @value: value to search for
 *
 * Return: first index of the value found otherwise -1
 */
int exponential_search(int *array, size_t size, int value)
{
	int bound = 1;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < (int)size && array[bound] < value)
	{
		printf("Value checked array[%d] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}
	printf("Value found between indexes [%d] and [%d]\n",
		   bound / 2, min_(bound + 1, (int)size - 1));
	return (binary_search_iterative(array, bound / 2,
			min_(bound + 1, (int)size - 1), value));
}
