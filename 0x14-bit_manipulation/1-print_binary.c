#include "main.h"

/**
 * print_binary -  function that prints the binary representation of a number
 * @n: number
 * Return: 0
 */

void print_binary(unsigned long int n)
{
	unsigned long int start;
	int i;
	
	start = 1ul << (sizeof(unsigned long int)*8-1);
	while (start)
	{
		if (n & start)
		{
			_putchar('1');
			i = 1;
		}
		else if (i)
		{
			_putchar('0');
		}
		start = start >> 1;
	}
	if (!i)
	{
		_putchar('0');
	}
}
