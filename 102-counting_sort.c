#include "sort.h"

/**
 * int_array_init - initializes an int array of size size filled with 0
 *
 * @size: the wanted size of the array
 *
 * Return: the new filled array, or NULL on failure
 */

int *int_array_init(size_t size)
{
	int *new = NULL;
	size_t i;

	new = malloc(sizeof(int) * size);
	if (new)
	{
		for (i = 0; i < size; i++)
			new[i] = 0;
	}

	return (new);
}

/**
 * counting_sort - sorts an array of integers using counting sort
 *
 * @array: the array of integers
 * @size: the size of the array
 */

void counting_sort(int *array, size_t size)
{
	int *count = NULL, *output = NULL, k = -1;
	size_t i;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
		k = array[i] > k ? array[i] : k;

	count = int_array_init(k + 1);
	if (count)
	{
		/* Histogram of the number of times a key occurs within the input */
		for (i = 0; i < size; i++)
			count[array[i]] += 1;

		/* Prefix sum computation on count to determine the position range */
		for (i = 1; i <= (size_t)k; i++)
			count[i] += count[i - 1];

		print_array(count, k + 1);

		output = malloc(sizeof(int) * size);
		if (output)
		{
			/* Moving each item into its sorted position in the output array */
			for (i = 0; i < size; i++)
			{
				output[count[array[i]] - 1] = array[i];
				count[array[i]] -= 1;
			}

			for (i = 0; i < size; i++)
				array[i] = output[i];

			free(output);
		}
		free(count);
	}
}
