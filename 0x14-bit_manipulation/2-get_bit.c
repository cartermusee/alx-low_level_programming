#include "main.h"

/**
 * get_bit -  function that gives the value of a bit at a given index
 * @index: is the index, starting from 0 of the bit you want to get
 * @n: the number
 * Return:the value of the bit at index index or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int t;

	while (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	t = 1ul << index;
	if ((n & t) != 0)
	{
		return (1);
	}
	return (0);
}
