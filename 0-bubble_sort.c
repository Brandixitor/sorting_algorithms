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
 * bubble_sort - sorts an array of integers using bubble sort
 *
 * @array: the array of integers
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t n = size, new_n, i;

	while (n > 1)
	{
		new_n = 0;
		for (i = 1; i <= n - 1; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap_values(&array, i - 1, i);
				print_array(array, size);
				new_n = i;
			}
		}
		n = new_n;
	}
}
