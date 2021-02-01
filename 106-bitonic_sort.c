#include "sort.h"

/**
 * compare - compare and swap values based on dir
 *
 * @array: the array (or subarray) to sort
 * @dir: the direction of sorting
 * @size: the size of the array
 */

void compare(int *array, int dir, size_t size)
{
	size_t i, gap;
	int tmp;

	gap = size / 2;

	for (i = 0; i < gap; i++)
	{
		if ((array[i] > array[i + gap]) == dir)
		{
			tmp = array[i];
			array[i] = array[i + gap];
			array[i + gap] = tmp;
		}
	}

}

/**
 * merge - recursively merge 2 "semibitonic" subarrays
 *
 * @array: the array (or subarray) to sort
 * @dir: the direction of sorting
 * @size: the size of the array
 */

void merge(int *array, int dir, size_t size)
{
	size_t half = size / 2;

	if (size < 2)
		return;

	compare(array, dir, size);
	merge(array, dir, half);
	merge((array + half), dir, half);
}

/**
 * sort - recursively sorts using bitonic algorithm
 *
 * @array: the array (or subarray) to sort
 * @dir: the direction of sorting
 * @size: size of the full array
 * @subsiz: the size of the subarray
 */

void sort(int *array, int dir, size_t size, size_t subsiz)
{
	size_t half = (size / 2);

	if (size < 2)
		return;

	printf("Merging [%lu/%lu] (%s):\n", size, subsiz, (dir == 1) ? "UP" : "DOWN");
	print_array(array, size);
	sort(array, 1, half, subsiz);
	sort((array + half), 0, half, subsiz);
	merge(array, dir, size);
	printf("Result [%lu/%lu] (%s):\n", size, subsiz, (dir == 1) ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using
 * the Bitonic sort algorithm
 *
 * @array: the array to sort
 * @size: size of the array
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, 1, size, size);
}
