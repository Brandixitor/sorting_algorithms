#include "sort.h"
/**
 * shell_sort - Sort integers in an array
 * @array: array of integers
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	unsigned int i, j;
	unsigned int gap = 1;
	int tmp;

	if (!array || size < 2)
		return;
	while (gap < (size - 1) / 3)
		gap = gap * 3 + 1;
	for (gap = gap; gap > 0; gap = gap / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j > gap - 1 && array[j - gap] >= tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
