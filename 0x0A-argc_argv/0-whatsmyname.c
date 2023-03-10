#include <stdio.h>
#include <libgen.h>

/**
 * main - prints name of file
 * @argc: number of arguments
 * @argv: array of pointers to arguments
 *
 * Return: Always 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", basename(argv[0]));
	return (0);
}
