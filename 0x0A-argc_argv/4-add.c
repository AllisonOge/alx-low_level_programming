#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * main - adds positive numbers
 * @argc: number of args
 * ~argv: array of pointers to args
 *
 * Return: 0 for success and 1 for error
 */
int main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		int i, sum = 0;
		bool error = false;

		for (i = 1; i < argc; i++)
			if (isdigit(*argv[i]))
				sum += atoi(argv[i]);
			else
			{
				error = true;
				break;
			}
		if (error)
		{
			printf("Error\n");
			return (1);
		}
		else
			printf("%d\n", sum);
	}
	else
		printf("0\n");
	return (0);
}
