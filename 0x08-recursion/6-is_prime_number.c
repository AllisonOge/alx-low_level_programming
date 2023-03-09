#include "main.h"

/**
 * is_prime_number_helper - checks if number is prime
 * @n: input integer
 * @i: divisor to check
 *
 * Return: 1 or 0
 */
int is_prime_number_helper(int n, int i)
{
	if (n <= 2)
		return ((n == 2) ? 1 : 0);
	if (n % i == 0)
		return (0);
	if (i * i > n)
		return (1);
	return (is_prime_number_helper(n, i + 1));
}

/**
 * is_prime_number - checks if number is prime
 * @n: input integer
 *
 * Return: 1 if the input is prime otherwise 0
 */
int is_prime_number(int n)
{
	return (is_prime_number_helper(n, 2));
}
