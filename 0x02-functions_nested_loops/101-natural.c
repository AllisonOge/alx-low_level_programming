#include <stdio.h>

/**
 * main - computes the sum of the multiples of 3 and 5 up to 1024
 *
 * Return: Always 0
 */
int main(void)
{
	long total = 0;

	int i;

	for (i = 0; i < 1024; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			total += i;
	}
	printf("%ld\n", total);

	return (0);
}
