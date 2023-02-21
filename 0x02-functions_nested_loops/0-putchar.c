#include <string.h>
#include "main.h"

/**
 * main - print _putchar
 *
 * Return: 0
 */
int main(void)
{
	char text[] = "_putchar\n";

	unsigned long i;

	for (i = 0; i < strlen(text); i++)
	{
		_putchar(text[i]);
	}

	return (0);
}
