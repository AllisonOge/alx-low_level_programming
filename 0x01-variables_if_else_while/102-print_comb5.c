#include <stdio.h>

/**
 * main - prints all possible combinations of 2 2-digit numbers
 *
 * Return: 0
 */
int main(void)
{
	int i;

	int j;

	for (i = 0; i < 99; i++)
		for (j = i + 1; j < 100; j++)
		{
			putchar('0' + (int)i / 10);
			putchar('0' + i % 10);
			putchar(' ');
			putchar('0' + (int)j / 10);
			putchar('0' + j % 10);

			if (i < 98)
			{
				putchar(',');
				putchar(' ');
			}
		}
	putchar('\n');

	return (0);
}
