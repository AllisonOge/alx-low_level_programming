#include "main.h"

/**
 * get_bit - computes the value of a bit at a given index
 * @n: integer number
 * @index: index starting from 0 of the bit to be returned
 *
 * Description: We use the bitwise AND operator with a mask
 * that has a 1 bit at the index and 0 bits eleswhere. If the
 * result of the bitwise AND operator is non-zero, then the
 * bit at the given index is 1, otherwise it is 0
 *
 * Return: value of the bit at index or -1 if error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		/* index is out of range */
		return (-1);
	}

	mask = 1ul << index;
	return ((n & mask) != 0);
}
