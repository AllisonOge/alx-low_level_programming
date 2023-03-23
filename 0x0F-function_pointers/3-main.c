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
	char *op;
	int (*op_func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	op = argv[2];
	op_func = get_op_func(op);

	if (op_func == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	result = op_func(num1, num2);

	if ((*op == '/' || *op == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", result);
	return (0);
}

