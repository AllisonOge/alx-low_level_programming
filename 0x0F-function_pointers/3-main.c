#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - programm that performs simple arithmetic operations
 * Usage: calc num1 operator num2
 * @argc: number of arguments
 * @argv: array pointers
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	if (!get_op_func(argv[2]))
	{
		printf("Error\n");
		exit(98);
	} else
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[3]);
		result = get_op_func(argv[2])(num1, num2);
		printf("%d\n", result);
	}
	return (0);
}

