#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: array of integers
 * @n: number of elements of the array
 */
void reverse_array(int *a, int n)
{
	/* pointers to the beginning and end of the array */
	int *start = a;

	int *end = a + n - 1;

	/* swap elements until the pointers meet in the middle */
	while (start < end)
	{
		int temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
}
