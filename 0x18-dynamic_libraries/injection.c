#include <stdlib.h>
#include <stdio.h>

/**
 * atoi - inject code for hack
 * Return: Always 0
 */
int atoi(const char *s)
{
	((void) s);
	printf("9 8 10 24 75 -9\n");
	printf("Congratulations, you win the Jackpot!\n");
	exit(0);
	return (0);
}
