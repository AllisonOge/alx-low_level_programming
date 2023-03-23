#include <stdio.h>
#include <stdlib.h>

/**
 * main: print the opcodes of its own main function
 * @argc: the number of command line arguments
 * @argv: an array of command line argument strings
 *
 * ReturnL always 0
 */
int main(int argc, char *argv[])
{
	int i, n_bytes;
	char *opcodes = (char *) main;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	n_bytes = atoi(argv[1]);

	if (n_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < n_bytes; i++)
		printf("%.2hhx ", opcodes[i]);
	printf("\n");

	return (0);
}
