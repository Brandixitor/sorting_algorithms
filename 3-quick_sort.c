#include "sort.h"

/**
 * swap - swap two intgers
 * @a: first element (integer)
 * @b: second element (integer)
 * Return: void
 */
void swap(int *a, int *b)
{
	int empty;

	empty = *a;
	*a = *b;
	*b = empty;
}

/**
 * lomuto - Takes last element as pivot
 * @array: array of integers
 * @beg: integer
 * @end: integer
 * @size: size of the array
 * Return: integer
 */
int lomuto(int *array, int beg, int end, size_t size)
{
	int piv = array[end];
	int i = (beg - 1);
	int j;

	for (j = beg; j <= end - 1; j++)
	{
		if (array[j] <= piv)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[end]);
	if (end != (i + 1))
		print_array(array, size);
	return (i + 1);
}

/**
 * sort - quick sort integer in an array
 * @array: array of integers
 * @beg: begining
 * @end: end
 * @size: size of the array
 * Return: void
 */
void sort(int *array, int beg, int end, size_t size)
{
	int idx;

	if (beg < end)
	{
		idx = lomuto(array, beg, end, size);
		sort(array, beg, idx - 1, size);
		sort(array, idx + 1, end, size);
	}
}

/**
 * quick_sort - Sorts integers in an array
 * @array: Array containing integers
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, 0, size - 1, size);
}
