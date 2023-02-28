#include "main.h"
#include <string.h>

/**
 * puts_half - prints half of a string
 * @str: pointer to a string
 */
void puts_half(char *str)
{
	size_t len = strlen(str);

	int i;

	if (len % 2 == 0)
		for (i = (int)len / 2; i < (int)len; i++)
			_putchar(*(str + i));
	else
		for (i = ((int)len - 1) / 2; i < (int)len - 1; i++)
			_putchar(*(str + i + 1));
	_putchar('\n');
}
