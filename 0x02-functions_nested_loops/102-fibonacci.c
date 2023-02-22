#include <stdio.h>

/**
 * main - computes the first 50 fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{

	long n1 = 1, n2 = 2, next;

	int i;

	for (i = 1; i <= 50; i++)
	{
		(i < 50) ? printf("%ld, ", n1) : (printf("%ld", n1));

		next = n1 + n2;

		n1 = n2;

		n2 = next;
	}

	printf("\n");

	return (0);
}
