#include "sort.h"
/**
 * swap_elem - Swap integers
 * @a: first element
 * @b: second element
 * Return: void
 */
void swap_elem(int *a, int *b)
{
	int empty;

	empty = *a;
	*a = *b;
	*b = empty;
}

/**
 * selection_sort - Sorts integers in an array
 * @array: The array containing integers
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min;

	if (!array || size < 2)
		return;
	i = 0;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		j = 1 + i;
		while (j < size)
		{
			if (array[j] < array[min])
				min = j;
			j++;
		}
		if (min != i)
		{
			swap_elem(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}
