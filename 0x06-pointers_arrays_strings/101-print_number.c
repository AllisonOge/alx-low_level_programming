#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer
 */
void print_number(int n)
{
	unsigned int nAbs;

	if (n < 0)
	{
		_putchar('-');
		nAbs = -n;
	} else
	{
		nAbs = n;
	}
	if (nAbs > 9)
		print_number(nAbs / 10);
	_putchar(nAbs % 10 + '0');
}
