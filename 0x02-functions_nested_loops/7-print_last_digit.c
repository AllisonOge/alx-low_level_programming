#include "main.h"

/**
 * print_last_digit - print the last digit of a number
 * @n: number to be printed
 *
 * Return: last digit of the number
 */
int print_last_digit(int n)
{
	int last_digit = (n < 0) ? (-(unsigned int)n % 10) : ((unsigned int)n % 10);

	_putchar(last_digit + '0');

	return (last_digit);
}
