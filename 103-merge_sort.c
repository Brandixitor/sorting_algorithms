#include "sort.h"

/**
 * int_array_copy - copies an int array of size size
 *
 * @array: the array to copy
 * @size: the wanted size of the copied array
 *
 * Return: the new copied array, or NULL on failure
 */

int *int_array_copy(int *array, size_t size)
{
	int *new = NULL;
	size_t i;

	new = malloc(sizeof(int) * size);
	if (new)
	{
		for (i = 0; i < size; i++)
			new[i] = array[i];
	}

	return (new);
}

/**
 * top_down_merge - merges the two arrays
 *
 * @a: the first array of integers
 * @b: the second array of integers
 * @size: the size of the final array
 * @mid: the middle index of the array
 */

void top_down_merge(int *a, int *b, size_t size, size_t mid)
{
	size_t i = 0, j = 0, k;

	for (k = 0; k < size; k++)
	{
		if (j >= size - mid || (i < mid && a[i] < (a + mid)[j]))
			b[k] = a[i++];
		else
			b[k] = (a + mid)[j++];
	}

	for (k = 0; k < size; k++)
		a[k] = b[k];
}

/**
 * top_down_split_merge - merges the two arrays
 *
 * @a: the first array of integers
 * @b: the second array of integers
 * @size: the size of the final array
 */

void top_down_split_merge(int *a, int *b, size_t size)
{
	size_t mid = size / 2 /*, i = 0, j = 0, k*/;

	if (size < 2)
		return;

	top_down_split_merge(a, b, mid);
	top_down_split_merge(a + mid, b + mid, size - mid);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(a, mid);
	printf("[right]: ");
	print_array(b + mid, size - mid);

	top_down_merge(a, b, size, mid);

	printf("[Done]: ");
	print_array(a, size);
}

/**
 * merge_sort - sorts an array of integers using merge sort
 *
 * @array: the array of integers
 * @size: the size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *work = NULL;

	work = int_array_copy(array, size);
	if (work)
	{
		top_down_split_merge(array, work, size);
		free(work);
	}
}
