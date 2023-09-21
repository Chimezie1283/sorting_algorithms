#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using a shell
 * sort algorithm, with gap sizes determined by a decreasing Knuth seqeuence
 * @array: The array of integers to be sorted
 * @size: The amount of elements in array
 */
void shell_sort(int *array, size_t size)
{
	int i, j, gap, n, Knuth_max, temp;

	if (!array || size < 2)
		return;

	n = (int)size;
	for (gap = 1; gap < n; gap = (gap * 3) + 1)
	{
		Knuth_max = gap;
	}
/* Start with the largest Knuth seq value less than n as gap, */
/* and work down sequence to 1 */
	for (gap = Knuth_max; gap > 0; gap = (gap - 1) / 3)
	{
		/* Do a gapped insertion sort for gap size. */
		for (i = gap; i < n; i++)
		{
			/* add array[i] to gap sorted elements; */
			/* save array[i] in temp in preparation be overwriten */
			temp = array[i];
			/* shift earlier gap-sorted elements up until the */
			/* correct location for array[i] is reached */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
/* works original array[i]) to its correct location */
			array[j] = temp;
		}
		print_array(array, size);
	}
}
