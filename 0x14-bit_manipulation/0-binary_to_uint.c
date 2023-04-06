#include "main.h"
#include <stddef.h>
#include <stdio.h>


/**
 * binary_to_uint - function that converts a binary number to an unsigned int
 * @b:pointer to a char
 *
 * Return:the converted number or 0
 */


unsigned int binary_to_uint(const char *b)
{
	unsigned int j = 0;

	if (b == NULL)
	{
		return (0);
	}

	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
		{
			return (0);
		}
		j = (j << 1) + (*b - '0');
		b++;
	}
	return (j);
}
