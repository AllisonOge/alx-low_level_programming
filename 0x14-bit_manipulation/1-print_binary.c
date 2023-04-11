#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: integer number
 * Description: we used bitwize operation to convert decimal
 * to binary
 */
void print_binary(unsigned long int n)
{
	/* create a mask to extract each bit */
	unsigned long int mask;
	unsigned long int tmp = n;
	int len = 0;

	while (tmp)
	{
		tmp >>= 1;
		len++;
	}

	if (n == 0)
		len = 1;
	mask = 1ul << (len - 1);


	while (mask)
	{
		if (n & mask)
			_putchar('1');
		else
			_putchar('0');
		mask >>= 1; /* shift the mask to the next bit */
	}
}
