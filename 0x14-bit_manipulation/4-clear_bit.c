#include "main.h"

/**
* clear_bit - sets the value of a bit to 0 at a given index
* @n: pointer to the integer number
* @index: index starting from 0 of the bit you want to set
*
* Description: To clear the bit at a specific index of an
* integer, we can use a bitwise AND operator with a mask
* that has a 0 bit at the index and 1 bits elsewhere. This
* will set the bit ar the given index to 0 while leaving
* all the other bits unchanged
*
* Return: 1 on success and -1 otherwise
  */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	mask = ~(1ul << index);
	*n &= mask;
	return (1);
}
