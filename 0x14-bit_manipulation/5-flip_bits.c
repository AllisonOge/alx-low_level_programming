#include "main.h"

/**
* flip_bits - computes the number of bits that would be flipped
* to get from one number to another
* @n: first integer number
* @m: second integer number
*
* Description: To compute the number of bits that would
* need to be flipped to convert one integer n to another m,
* we use the bitwise XOR operator. The result of the
* operation will have a 1 bit in each position where the
* corresponding bits of n and m are different and 0 bit
* where they are the same. Then we can count the number of
* 1 bits in the XOR result to determine the number of bits
* that would be flipped.
*
* Return: number of bits computed
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result)
	{
		if (xor_result & 1)
			count++;
		xor_result >>= 1;
	}

	return (count);
}
