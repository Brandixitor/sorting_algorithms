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
 * count_sort - sorts an array of integers using counting sort
 *
 * @array: the array of integers
 * @size: the size of the array
 * @exp: the exponent value of 10
 */

void count_sort(int *array, size_t size, int exp)
{
	int *count = NULL, *output = NULL;
	size_t i;

	count = int_array_init(10 + 1);
	if (count)
	{
		/* Histogram of the number of times a key occurs within the input */
		for (i = 0; i < size; i++)
			count[(array[i] / exp) % 10] += 1;

		/* Prefix sum computation on count to determine the position range */
		for (i = 1; i <= 10; i++)
			count[i] += count[i - 1];

		output = int_array_init(size);
		if (output)
		{
			/* Moving each item into its sorted position in the output array */
			for (i = 0; i < size; i++)
			{
				output[count[(array[i] / exp) % 10] - 1] = array[i];
				count[(array[i] / exp) % 10] -= 1;
			}

			for (i = 0; i < size; i++)
				array[i] = output[i];

			free(output);
		}
		free(count);
	}
}

/**
 * radix_sort - sorts an array of integers using LSD radix sort
 *
 * @array: the array of integers
 * @size: the size of the array
 */

void radix_sort(int *array, size_t size)
{
	int k = -1, exp;
	size_t i;

	for (i = 0; i < size; i++)
		k = array[i] > k ? array[i] : k;

	for (exp = 1; k / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}
