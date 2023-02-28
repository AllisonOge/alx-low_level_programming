#include "main.h"
#include <string.h>

/**
 * puts2 - prints every other character of a string
 * @str: pointer to string
 */
void puts2(char *str)
{
	int i;

	for (i = 0; i <= (int)strlen(str) - 1; i++)
		if ((int) str[i] % 2 == 0)
			_putchar(str[i]);
	_putchar('\n');
}
