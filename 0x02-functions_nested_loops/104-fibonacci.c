#include <stdio.h>

/**
 * main - prints the first 98 fibonacci series
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned int fibonacci[100] = {1, 2};

	/* compute the fibonacci sequence */
	int i;

	for (i = 2; i < 100; i++)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	/* print the first 98 fibonacci sequence */
	for (i = 0; i < 98; i++)
		(i < 97) ? printf("%u, ", fibonacci[i]) : printf("%u", fibonacci[i]);

	printf("\n");

	return (0);
}
