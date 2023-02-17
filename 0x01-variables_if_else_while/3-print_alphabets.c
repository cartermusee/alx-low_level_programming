#include <stdio.h>

/**
 * main - Entry point
 * Return: Always 0 (success)
 */

int main(void)
{
	char alphabet, upper;

	alphabet = 'a';

	while (alphabet <= 'z')
	{
		upper = 'A';
		while (upper <= 'Z')
		{
			putchar(alphabet);
			alphabet++;
		}
		putchar(alphabet <= 'z');
		alphabet++;
	}
	putchar('\n');
	return (0);
}
