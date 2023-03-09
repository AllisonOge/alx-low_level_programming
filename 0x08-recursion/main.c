#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
/*    _puts_recursion("Puts with recursion"); */
/*    _print_rev_recursion("\nColton Walker"); */
/*    int n;

    n = _strlen_recursion("Corbin Coleman");
    printf("%d\n", n); */
    int r;

    r = factorial(1);
    printf("%d\n", r);
    r = factorial(5);
    printf("%d\n", r);
    r = factorial(10);
    printf("%d\n", r);
    r = factorial(-1024);
    printf("%d\n", r);
    return (0);
}
