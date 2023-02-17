#include <stdio.h>

/* betty style doc for function main goes there */
/**
 * main - Entry point
 * Return: Always 0 (success)
 */

int main(void)
{
	int m, c;

	for (m = 0; m <= 98; m++)
	{
		for (c = m + 1; c <= 99; c++)
		{
			putchar((m / 10) + '0');
			putchar((m % 10) + '0');
			putchar(' ');
			putchar((c / 10) + '0');
			putchar((c % 10) + '0');

			if (m == 98 && c == 99)
				continue;

			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}
