#include "main.h"

/**
* get_endianness - checks the endianess
*
* Description: We use bit shifting and masking operations to examine the byte
* order of a multi-byte integer value. If the first bytes is the value assigned
* then the system is little-endian otherwise big-endian.
* P.S. the implementation assumes the size of a char is 1 byte and the size of
* an int is 4 bytes.
*
* Return: 0 if big endian, 1 if little endian
*/
int get_endianness(void)
{
	int i = 1;
	char *p = (char *)&i;

	/* if the first byte of the integer is 1 then the system is litle-endian */
	if (*p == 1)
		return (1);
	else
		return (0);
}
