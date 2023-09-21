#include "sort.h"

/**
 * z_Parent - returns index of parent node for an array arranged as a binary
 * tree, for index i
 * @i: starting index to determine parent node index
 * Return: index of parent node
 */
int z_Parent(int i)
{
	return ((i - 1) / 2);
}

/**
 * z_LeftChild- returns index of left child branch for an array arranged as
 * a binary tree, for index i
 * @i: starting index to determine left child branch index
 * Return: index of left child node
 */
int z_LeftChild(int i)
{
	return ((2 * i) + 1);
}

/**
 * Convert2Heap - arranges array of integers into a heap/binary tree scheme
 * @array: The array of integers
 * @size: The number of elements in array
 */
void Convert2Heap(int *array, size_t size)
{
	int start;

	start = z_Parent(size - 1);

	while (start >= 0)
	{
		Shift_Down(array, size, start, size - 1);
		start--;
	}
}

/**
 * Shift_Down - shuffles heap/binary tree sorted array into array sorted by
 * ascending value
 * @array: array of values to be sorted in place, from heap to ascending
 * @size: number of elements in array
 * @start: starting index
 * @end: ending index
 */
void Shift_Down(int *array, size_t size, int start, int end)
{
	int root, swap, temp, child;

	root = start;

	while (z_LeftChild(root) <= end)
	{
		child = z_LeftChild(root);
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heap_sort - sorts array of integers in ascending order using a heap sort
 * sift-down alogrithm
 * @array: The array of values to be sorted
 * @size: The number of elements in array
 */
void heap_sort(int *array, size_t size)
{
	int iEnd, temp;

	if (!array || size < 2)
		return;

	Convert2Heap(array, size);

	iEnd =  (int)size - 1;
	while (iEnd > 0)
	{
		temp = array[iEnd];
		array[iEnd] = array[0];
		array[0] = temp;
		print_array(array, size);
		iEnd--;
		Shift_Down(array, size, 0, iEnd);
	}
}
