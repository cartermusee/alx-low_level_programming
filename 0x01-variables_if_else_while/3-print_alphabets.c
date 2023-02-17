#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (success)
 */

int main(void)
{
	char alphabet, upper;

	alphabet = 'a';
	upper = 'Z';

	while (alphabet <= 'z' && upper <= 'Z')
	{
		putchar(alphabet <= 'z');
		alphabet++;
		upper++;
	}
	putchar('\n');
	return (0);
}
