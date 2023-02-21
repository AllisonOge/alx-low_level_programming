#include "main.h"

/**
 * jack_bauer - prints every inute of the dat of Jack Bauer
 */
void jack_bauer(void)
{
	int min;

	int hour;

	for (hour = 0; hour < 24; hour++)
		for (min = 0; min < 60; min++)
		{
			_putchar((int)(hour / 10) + '0');
			_putchar((hour % 10) + '0');
			_putchar(':');
			_putchar((int)(min / 10) + '0');
			_putchar((min % 10) + '0');
			_putchar('\n');
		}
}
