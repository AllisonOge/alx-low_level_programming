#include "3-calc.h"

/**
 * op_add - implements the add operation
 * @a: first integer
 * @b: second integer
 *
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - implments the sub operation
 * @a: first integer
 * @b: second integer
 *
 * Return: difference of a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - implements the mul operation
 * @a: first integer
 * @b: second integer
 *
 * Return: product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - implements the div operation
 * @a: first integer
 * @b: second integer
 *
 * Return: division of a by b
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - implements the mod operation
 * @a: first integer
 * @b: second integer
 *
 * Return: remainder of the division of a by b
 */
int op_mod(int a, int b)
{
	return (a % b);
}
