#include "sort.h"

/**
 * partision - scans a partition of an array of integers for values less than
 * pivot value, and swaps them with first value in partition, then swaps pivot
 * value with first value in partition
 * @array: The array of integers to be sorted
 * @low: The index in array that begins partition
 * @high: The index in array that ends partition
 * @size: The amount of elements in array
 * Return: new index at which to start new recursive partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, tep;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			tep = array[i];
			array[i] = array[j];
			array[j] = tep;
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	tep = array[i];
	array[i] = array[high];
	array[high] = tep;
	if (array[i] != array[high])
		print_array(array, size);
	return (i);
}

/**
 * quiksot - recursively sorts array of integers by separating into two
 * partitions, using Lomuto quick sort
 * @array: The array of integers to be sorted
 * @low: The index in array that begins partition
 * @high: The index in array that ends partition
 * @size: The amount of elements in array
 */
void quiksot(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partision(array, low, high, size);
		quiksot(array, low, p - 1, size);
		quiksot(array, p + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using a quick
 * sort algorithm, with Lomuto partition scheme
 * @array: The array of integers to be sorted
 * @size: The amount of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quiksot(array, 0, (int)size - 1, size);
}
