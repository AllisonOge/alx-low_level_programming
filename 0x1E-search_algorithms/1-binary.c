#include <stdio.h>
#include "search_algos.h"


/**
 * binary_search_helper - Helper function for performing binary search
 * @array: pointer to array
 * @low: lowest index of subarray
 * @high: highest index of subarray
 * @value: value to search for
 *
 * Return: index where value is found otherwise -1
 */
int binary_search_helper(int *array, int low, int high, int value)
{
	int i;
	int mid = low + (high - low) / 2;

	if (high >= low)
	{
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
			return (binary_search_helper(array, mid + 1, high, value));
		return (binary_search_helper(array, low, mid - 1, value));
	}
	return (-1);
}

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
	int low = 0;
	int high = (int)size - 1;

	if (array == NULL || size == 0)
		return (-1);

	return (binary_search_helper(array, low, high, value));
}
