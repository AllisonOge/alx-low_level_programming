#include <stdio.h>
#include "variadic_functions.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
/*    int sum;

    sum = sum_them_all(2, 98, 1024);
    printf("%d\n", sum);
    sum = sum_them_all(4, 98, 1024, 402, -1024);
    printf("%d\n", sum); */
/*    print_numbers(", ", 4, 0, 98, -1024, 402); */
/*    print_strings(", ", 2, "Jay", "Django"); */
    print_all("ceis", 'B', 3, "stSchool");
    print_all(NULL, 23, "ALX is cool", 12.4, 'e');
    return (0);
}
