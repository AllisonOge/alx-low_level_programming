#include "main.h"

/**
 * times_table - prints the 9 times table
 */
void times_table(void)
{
	int i;

	int j;

	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			long product = i * j;

			if (product < 10)
				_putchar(product + '0');
			else
			{
				_putchar((product / 10) + '0');

				_putchar((product % 10) + '0');
			}

			if (j < 9)
			{
				_putchar(',');

				_putchar(' ');

				if (product < 10)
					_putchar(' ');
			}
			else
				_putchar('\n');
		}
}
