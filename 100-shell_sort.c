#include "sort.h"

/**
 * knuth_max_gap - gets the max gap according the Knuth sequence
 *
 * @size: the size of the array
 *
 * Return: the max gap
 */

size_t knuth_max_gap(size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = gap * 3 + 1;
	if (gap >= size)
		gap = (gap - 1) / 3;

	return (gap);
}

/**
 * shell_sort - sorts an array of integers using shell sort (Knuth sequence)
 *
 * @array: the array of integers
 * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 0, i, j;
	int tmp;

	gap = knuth_max_gap(size);
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];

			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];

			array[j] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
