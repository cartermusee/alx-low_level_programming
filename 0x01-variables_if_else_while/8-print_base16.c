#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (success)
 */

int main(void)
{
	int i;
	char lowercase;

	for (i = '0'; i <= '9'; i++)
	{
		putchar(i);
	}
	for (lowercase = 'a'; lowercase <= 'f'; lowercase++)
	{
		putchar(lowercase);
	}
	putchar('\n');
	return (0);
}
