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
 * heap_sort_sift_down - applies the sift down method to the array
 *
 * @array: the array of ints
 * @size: size of the array
 * @start: wanted start index
 * @end: wanted end index
 */

void heap_sort_sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start, child, swap;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
		{
			return;
		}
		else
		{
			swap_values(&array, root, swap);
			print_array(array, size);
			root = swap;
		}
	}
}

/**
 * heap_sort - sorts an array of integers using heap sort (sift-down)
 *
 * @array: the array of integers
 * @size: the size of the array
 */

void heap_sort(int *array, size_t size)
{
	size_t end = size - 1, start;

	if (size < 2)
		return;

	for (start = (size - 2) / 2; (int)start >= 0; start--)
		heap_sort_sift_down(array, size, start, size - 1);

	while (end > 0)
	{
		swap_values(&array, end, 0);
		print_array(array, size);
		end--;
		heap_sort_sift_down(array, size, 0, end);
	}
}
