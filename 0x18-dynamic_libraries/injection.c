int numbers[] = {9, 8, 10, 24, 75, 9};
/**
 * rand - override random generator function to return number combination
 *
 * Return: a sequence of numbers 9 8 10 24 75 9
 */
int rand()
{
	static int i = 0;
	int result = numbers[i];
	i = (i + 1) % 6;
	return (result - 1);
}
