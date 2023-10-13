#include <stdio.h>
#include "search_algos.h"

/**
 * linear_search- function for linear search
 * @array:pointer to the array to check
 * @size:size of array
 * @value:the value to check for
 * Return:a negative 1 if array empty and value not found
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
	{
		return (-1);
	}

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (i);
		}
	}
	return (-1);
}
