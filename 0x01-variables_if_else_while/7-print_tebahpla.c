#include <stdio.h>
#include <string.h>

/**
 * main - prints the lowercase alphabet in reverse
 *
 * Return: 0
 */
int main(void)
{
	char alphabets[] = "abcdefghijklmnopqrstuvwxyz";

	unsigned long i;

	for (i = strlen(alphabets) + 1; i > 0; --i)
		putchar(alphabets[i - 1]);

	putchar('\n');

	return (0);
}
