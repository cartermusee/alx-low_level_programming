#include "main.h"

/**
 * get_endianness - system endiannes
 * Return: zero
 */

int get_endianness(void)
{
	unsigned long int p = 1;
	return (*(char *)&p);
}
