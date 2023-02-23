#include <stdio.h>

/**
 * main - prints the first 98 fibonacci series
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long int n1, n2, next, n1_l, n1_f, n2_l, n2_f;

	int i;

	n1 = 1;

	n2 = 2;

	for (i = 1; i < 91; i++)
	{
		printf("%lu, ", n1);
		next = n1 + n2;
		n1 = n2;
		n2 = next;
	}

	/* split the numbers for large numbers */
	n1_f = n1 / 1000000000;
	n1_l = n1 % 1000000000;
	n2_f = n2 / 1000000000;
	n2_l = n2 / 1000000000;

	for (i = 91; i <= 98; i++)
	{
		printf("%lu", n1_f + (n1_l / 1000000000));
		(i < 98) ? printf("%lu, ", n1_l % 1000000000) : printf("%lu\n", n1_l % 1000000000);
		n2_f = n2_f + n1_f;
		n1_f = n2_f - n1_f;
		n2_l = n2_l + n2_l;
		n1_l = n2_l - n1_l;
	}

	return (0);
}
