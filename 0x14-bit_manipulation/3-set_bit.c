#include "main.h"

/**
* set_bit - sets the value of a bit to 1 at a given index
* @n: pointer to integer number
* @index: index starting from 0 of the bit to be set
*
* Description: We will use the bitwise OR operator with a
* mask that has 1 bit at the index and 0 bits elsewhere.
* The function contains checks to validate the range of the
* index. the mask is created by shifting a 1 bit to the left
* by the index number then using the bitwise OR operator, we
* set the bit to 1 at the given index.
*
* Return: 1 on success or -1 on failure
*/
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		/* index out of range */
		return (-1);
	}

	mask = 1ul << index;
	*n |= mask;
	return (1);
}
