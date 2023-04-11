#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: integer number
 * Description: we used bitwize operation to convert decimal
 * to binary
 */
void print_binary(unsigned long int n)
{
	char buf[BUFFER_SIZE];
	int i = 0;

	/* extract binary digits from the decimal number */
	while (n > 0)
	{
		buf[i++] = (n & 1) ? '1' : '0';
		n >>= 1;
	}

	/* if the decimal is 0, the binary is also 0 */
	if (i == 0)
		buf[i++] =  '0';

	while (i > 0)
		_putchar(buf[--i]);
}
