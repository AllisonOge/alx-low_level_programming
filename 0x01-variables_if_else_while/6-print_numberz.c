#include <stdio.h>

/**
 * main - prints all single diit numbers
 *
 * Return: 0
 */
int main(void)
{
	unsigned long i;

	for (i = 0; i < 10; i++)
		putchar('0' + i);

	putchar('\n');

	return (0);
}
