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
 * partition - selects a pivot point in the array
 *
 * @array: the array to sort
 * @lo: the lowest index of the partition to sort
 * @hi: the highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int pivot;
	ssize_t i, j;

	pivot = array[hi];
	i = lo;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_values(&array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[hi] < array[i])
	{
		swap_values(&array, i, hi);
		print_array(array, size);
	}

	return (i);
}

/**
 * _quick_sort - partitions the array, then sorts each partition
 *
 * @array: the array to sort
 * @lo: the lowest index of the partition to sort
 * @hi: the highest index of the partition to sort
 * @size: size of the array
 */

void _quick_sort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		_quick_sort(array, lo, pivot - 1, size);
		_quick_sort(array, pivot + 1, hi, size);
	}
}



/**
 * quick_sort - sorts an array of integers using quicksort
 *
 * @array: the array of integers
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	ssize_t lo = 0;
	ssize_t hi = (size - 1);

	if (!array || size < 2)
		return;

	_quick_sort(array, lo, hi, size);
}
