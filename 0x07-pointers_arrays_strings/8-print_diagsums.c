#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of two diagonals of a square matrix of
 * integers
 * @a: square matrix
 * @size: size of matrix
 */
void print_diagsums(int *a, int size)
{
	int i, sum1 = 0, sum2 = 0;

	/* iterate over the diagonal from top-left to bottom right*/
	for (i = 0; i < size; i++)
		sum1 += *(a + i * size + i);

	/* iterate ove the diagonal from bottom-left to top-right */
	for (i = 0; i < size; i++)
		sum2 += *(a + (size - 1 - i) * size + i);

	printf("%d, %d\n", sum1, sum2);
}
