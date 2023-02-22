#include "main.h"

/**
 * print_times_table - prints the n times table
 * @n: integer
 */
void print_times_table(int n)
{
	if (n >= 0 && n <= 15)
	{
		int i;

		int j;

		for (i = 0; i <= n; i++)
			for (j = 0; j <= n; j++)
			{
				long product = i * j;

				if (j > 0)
				{
					_putchar(',');
					_putchar(' ');
					if (product < 100)
						_putchar(' ');
					if (product < 10)
						_putchar(' ');
				}
				if (product < 10)
					_putchar(product + '0');
				else if (product < 100)
				{
					_putchar((product / 10) + '0');
					_putchar((product % 10) + '0');
				}
				else
				{
					_putchar((product / 100) + '0');

					_putchar((product - 100) / 10 + '0');
					_putchar((product % 10) + '0');
				}
				if (j >= n)
					_putchar('\n');
			}
	}
}
