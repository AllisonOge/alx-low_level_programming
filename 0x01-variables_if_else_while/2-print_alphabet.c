#include <stdio.h>
#include <string.h>

/**
 * main - print alphabet in lowercase
 *
 * Return: 0
 */
int main(void)
{
	char alphabets[] = "abcdefghijklmnopqrstuvwxyz";

	unsigned long i;

	for (i = 0; i < strlen(alphabets); i++)
		putchar(alphabets[i]);

	putchar('\n');

	return (0);
}
