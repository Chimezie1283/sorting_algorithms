#include "sort.h"

/**
 * bubble_sort - This sorts an array of integers in ascending order using
 * a bubble sort algorithm
 * @array: The array of integers to be sorted
 * @size: The amount of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int tep;
	bool swaped = true;

	if (!array || size < 2)
		return;

	n = size;
	while (swaped)
	{
		swaped = false;
		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				tep = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tep;
				swaped = true;
				print_array(array, size);
			}
		}
		/* optimize by logically elinating final swap from last loop */
		n--;
	}
}
