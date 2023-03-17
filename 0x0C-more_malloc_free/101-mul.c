#include "main.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: pointer to array of pointers of string
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		int d1, d2, i, j, carry, len1, len2, product, pos;
		bool error = false;
		char *num1, *num2;
		unsigned long long result;

		num1 = argv[1];
		num2 = argv[2];
		len1 = strlen(num1);
		len2 = strlen(num2);

		/* iterate through each digit of first digit from right to left */
		for (i = 0; i < len1; i++)
		{
			if (atoi(num1[i]) >= 0)
			{
				d1 = num1[len1 - 1 - i] - '0';
				carry = 0;

				/* iterate through each digit of num2 form right to left */
				for (j = 0; j < len2; j++)
				{
					if (atoi(num2[j]) >= 0)
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
			message = "Error\n";
			for (i = 0; i < strlen(message); i++)
				_putchar(message[i]);
			exit(98);
		}
		/* allocate memory for result */
		message = malloc((sizeof(char) * i) + 1);

		sprintf(message, "%d\n", result);
		for (i = 0; i < strlen(message); i++)
			_putchar(message[i]);
	}
	else
	{
		message = "Error\n";
		for (i = 0; i < strlen(message); i++)
			_putchar(message[i]);
		exit(98);
	}
	return (0);
}
