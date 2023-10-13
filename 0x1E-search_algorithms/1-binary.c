#include <stdio.h>
#include "search_algos.h"

/**
 * binary_search- function for linear search
 * @array:pointer to the array to check
 * @size:size of array
 * @value:the value to check for
 * Return:a negative 1 if array empty and value not found
 */

int binary_search(int *array, size_t size, int value)
{
	int l, r, mid;
	int i;

	l = 0;
	r = size - 1;
	if (array == NULL)
	{
		return (-1);
	}

	while (l <= r)
	{
		mid = l + (r - l) / 2;
		printf("Searching in array: ");
		for (i = l; i <= r; i++)
		{
			printf("%d", array[i]);
			if (i < r)
			{
				printf(", ");

			}
		}
		printf("\n");

		if (array[mid] == value)
		{
			return (value);
		}
		if (array[mid] < value)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return (-1);
}
