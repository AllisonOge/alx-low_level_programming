#include <stdio.h>
#include <string.h>

/**
 * main - prints the alphabet in lowercase and uppercase
 *
 * Return: 0
 */
int main(void)
{
	char alphabets[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	unsigned long i;

	for (i = 0; i < strlen(alphabets); i++)
		putchar(alphabets[i]);

	putchar('\n');

	return (0);
}
