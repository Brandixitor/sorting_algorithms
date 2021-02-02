#include "sort.h"

/**
 * swap_values - swaps 2 values in an array of ints
 *
 * @array: the array of ints
 * @i1: index of first value
 * @i2: index of 2nd value
 *
 * Return: the array with value
 */

void swap_values(int **array, ssize_t i1, ssize_t i2)
{
	int tmp;

	tmp = (*array)[i1];
	(*array)[i1] = (*array)[i2];
	(*array)[i2] = tmp;
}

/**
 * selection_sort - sorts an array of integers using selection sort
 *
 * @array: the array of integers
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			swap_values(&array, min, i);
			print_array(array, size);
		}
	}
}
