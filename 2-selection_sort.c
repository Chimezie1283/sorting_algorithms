#include "sort.h"

/**
 * selection_sort - sorts an array of integers using a selction sort
 * algorithm
 * @array: The array of integers to be sorted
 * @size: The amount of elements in array
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min_j, tep, n = (int)size;

	if (!array || size < 2)
		return;

	/* at every position in the given member array */
	for (i = 0; i < n - 1; i++)
	{
		/* scan from set position to the end, */
		min_j = i;
		for (j = i + 1; j < n; j++)
		{
			/* determines the minimum value of range */
			if (array[j] < array[min_j])
			{
				min_j = j;
			}
		}
		/* swap if lower than the start value range */
		if (min_j != i)
		{
			tep = array[i];
			array[i] = array[min_j];
			array[min_j] = tep;
			print_array(array, size);
		}
	}
}
