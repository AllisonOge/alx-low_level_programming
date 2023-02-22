#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued fibonacci terms
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long n1 = 1, n2 = 2, next, total = 0;
	while (n1<= 4000000)
	{
		if (n1 % 2 == 0)
			total += n1;

		next = n1 + n2;

		n1 = n2;

		n2 = next;
	}

	printf("%ld\n", total);

	return (0);
}
