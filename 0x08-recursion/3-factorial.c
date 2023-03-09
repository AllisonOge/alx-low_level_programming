#include "main.h"

/**
 * factorial - factorial of a given number
 * @n: integer number
 *
 * Return: the factorial of number n
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}
