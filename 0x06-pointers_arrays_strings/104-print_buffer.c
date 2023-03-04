#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer
 * @b: char pointer
 * @size: integer argument
 */
void print_buffer(char *b, int size)
{
	if (size <= 0)
		printf("\n");

	int i, j;

	char c;

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
				printf("%02x", b[i + j] & 0xff);
			else
				printf(" ");

			if (j % 2 == 1)
				printf(" ");
		}

		printf(" ");

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
			{
				c = b[i + j];

				if (c >= 32 && c < 127)
					printf("%c", c);
				else
					printf(".");
			} else
				printf(" ");
		}

		printf("\n");
	}
}
