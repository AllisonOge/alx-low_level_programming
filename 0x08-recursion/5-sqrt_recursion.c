#include "main.h"

/**
 * _sqrt_helper - computes the natural square root
 * @n: number whose square root is to be found
 * @low: lower bound
 * @high: upper bound
 *
 * Return:
 */
int _sqrt_helper(int n, int low, int high)
{
	int mid = (low + high) / 2;

	int mid_squared = mid * mid;

	if (low > high)
		/* no natural square root */
		return (-1);

	if (mid_squared == n)
		return (mid);
	else if (mid_squared < n)
		return (_sqrt_helper(n, mid + 1, high));
	else
		return (_sqrt_helper(n, low, mid - 1));
}

/**
 * _sqrt_recursion - natural square root of a number
 * @n: integer number
 *
 * Return: natural square of n
 */
int _sqrt_recursion(int n)
{
	return (_sqrt_helper(n, 0, n));
}
