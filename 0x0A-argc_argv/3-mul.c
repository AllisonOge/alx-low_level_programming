#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiple two numbers
 * @argc: number of args
 * @argv: array of pointers to args
 *
 * Return: Always 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	if (argc >= 3)
	{
		int product = atoi(argv[1]) * atoi(argv[2]);

		printf("%d\n", product);
	}
	else
		printf("Error\n");
	return (0);
}
