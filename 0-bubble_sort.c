#include "sort.h"

/**
 * swap - Swaps between two integers
 * @a: 1st ineteger
 * @b: 2nd integer
 */
void swap(int *a, int *b)
{
	int empty;

	empty = *a;
	*a = *b;
	*b = empty;
}


/**
 * bubble_sort - Sortes inetegers in an array
 * @array: array of integers
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	bool sorted;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		sorted = false;
		for (j = 0; j < size - i - 1 ; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				sorted = true;
				print_array(array, size);
			}
		}
		if (sorted == false)
			break;
	}
}
