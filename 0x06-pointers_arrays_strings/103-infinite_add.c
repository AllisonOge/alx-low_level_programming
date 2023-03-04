#include "main.h"
#include <string.h>

/**
 * infinite_add - add two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer used to store result
 * @size_r: buffer size
 *
 * Return: sum of two numbers
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = (int) strlen(n1);

	int len2 = (int) strlen(n2);

	int sum, carry = 0;

	int i = len1 - 1;

	int j = len2 - 1;

	int k = size_r - 2;

	while (i >= 0 || j >= 0 || carry != 0)
	{
		if (k < 0)
			return (0);
		sum = carry;
		if (i >= 0)
		{
			sum += n1[i] - '0';
			i--;
		}
		if (j >= 0)
		{
			sum += n2[j] - '0';
			j--;
		}
		carry = sum / 10;
		sum %= 10;
		r[k] = sum + '0';
		k--;
	}
	r[size_r - 1] = '\0';

	return (&r[k + 1]);
}
