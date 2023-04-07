#include "main.h"

/**
 *flip_bits - function that gets the bits to flip one number to another
 * @n: first number
 * @m: second number
 * Return: the number of bits you would need to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int number;

	unsigned long int i = 0;

	number = n ^ m;
	while (number)
	{
		i++;
		number &= (number - 1);
	}
	return (i);
}

