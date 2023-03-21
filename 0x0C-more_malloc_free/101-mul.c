#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

/**
 * printString - print a string
 * @s: pointer to string
 */
void printString(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: pointer to array of pointers of string
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	int i;

	if (argc >= 3)
	{
		int d1, d2, len1, len2, j, carry, product, pos;
		bool error = false;
		char *num1, *num2, *message;
		unsigned long result = 0;

		num1 = argv[1];
		num2 = argv[2];
		len1 = strlen(num1);
		len2 = strlen(num2);
		/* iterate through each digit of num1 from right to left */
		for (i = 0; i < len1; i++)
		{
			if (isdigit(num1[len1 - i - 1]))
			{
				d1 = num1[len1 - 1 - i] - '0';
				carry = 0;
				/* iterate through each digit of num2 form right to left */
				for (j = 0; j < len2; j++)
				{
					if (isdigit(num2[len2 - 1 - j]))
					{
						d2 = num2[len2 - 1 - j] - '0';
						/* multiply the digits and add carry */
						product = d1 * d2 + carry;
						/* add the product to the result */
						pos = i + j;
						result += product * pow(10, pos);
						/* update the carry */
						carry = product / 10;
					}
					else
					{
						error = true;
						break;
					}
				}
				/* add the final carry to the result */
				if (carry > 0)
				{
					pos = i + len2;
					result += carry * pow(10, pos);
				}
			}
			else
			{
				error = true;
				break;
			}
		}
		if (error)
		{
			printString("Error\n");
			exit(98);
		}
		/* allocate memory for result */
		message = malloc((sizeof(char) * i) + 1);

		sprintf(message, "%lu\n", result);
		printString(message);
		free(message);
	}
	else
	{
		printString("Error\n");
		exit(98);
	}
	return (0);
}
