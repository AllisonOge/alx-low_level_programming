#include <stdio.h>
#include "search_algos.h"


/**
 * binary_search_recursive - recursive binary search
 * @array: pointer to array of integers
 * @low: lower index
 * @high: higher index
 * @value: value to search for
 *
 * Return: index of the value found otherwise -1
 */
int binary_search_recursive(int *array, int low, int high, int value)
{
	int i;
	int mid = low + (high - low) / 2;

	if (high >= low)
	{
		printf("Searching in array: ");
		for (i = low; i <= high; i++)
		{
			if (i < high)
				printf("%d, ", array[i]);
			if (i == high)
				printf("%d\n", array[i]);
		}

		if (value == array[mid])
		{
			if (mid == low || array[mid - 1] != value)
				return (mid);
			else
				return (binary_search_recursive(array, low, mid, value));
		}
		else if (value > array[mid])
			return (binary_search_recursive(array, mid + 1, high, value));
		else
			return (binary_search_recursive(array, low, mid - 1, value));
	}
	return (-1);
}

/**
 * advanced_binary - a function that searches for a value
 * in a sorted array of integers
 * @array: pointer to array of integers
 * @size: size of the array
 * @value: value to search for
 *
 * Return: first index of the value found otherwise -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	int low = 0;
	int high = (int)size - 1;

	if (array == NULL || size == 0)
		return (-1);
	return (binary_search_recursive(array, low, high, value));
}
