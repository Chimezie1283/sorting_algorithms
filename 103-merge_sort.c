#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Print_Array - prints array of integers for range of indicies
 * @array: The array of values to be printed
 * @iBeg: The starting index value
 * @iEnd: The ending index value
 */
void Print_Array(int *array, int iBeg, int iEnd)
{
	int i;

	for (i = iBeg; i < iEnd; i++)
		if (i < iEnd - 1)
			printf("%i, ", array[i]);
		else
			printf("%i\n", array[i]);
}

/**
 * Copy_Array - simple 1 for 1 copy of source[] to dest[]
 * @source: array of values to be sorted
 * @iBeg: The starting index value
 * @iEnd: The ending index value
 * @dest: The array to store sorted integers
 */
void Copy_Array(int *source, int iBeg, int iEnd, int *dest)
{
	int i;

	for (i = iBeg; i < iEnd; i++)
		dest[i] = source[i];
}

/**
 * Top_DownMerge - sorts subsections ("runs") of source[] by ascending value
 * @source: The array of values to be sorted
 * @iBeg: The left run starting index value
 * @iMid: The right run starting index value
 * @iEnd: The right run ending index value
 * @dest: The array to store sorted integers
 */
void Top_DownMerge(int *source, int iBeg, int iMid, int iEnd, int *dest)
{
	int i, j, k;

	i = iBeg, j = iMid;

	printf("Merging...\n");
	printf("[left]: ");
	Print_Array(source, iBeg, iMid);
	printf("[right]: ");
	Print_Array(source, iMid, iEnd);
	/* While there are elements in the left or right runs... */
	for (k = iBeg; k < iEnd; k++)
	{
		/* If left run head exists and is <= existing right run head */
		if (i < iMid && (j >= iEnd || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	Print_Array(dest, iBeg, iEnd);
}

/**
 * TopDown_SplitMerge - recursive engine of merge_sort, splits working copy of
 * array into left and right runs, then merges with TopDownMerge
 * @source: The array of integers to be sorted
 * @iBeg: The starting index value
 * @iEnd: The ending index value
 * @dest: The array to store sorted integers
 */
void TopDown_SplitMerge(int *source, int iBeg, int iEnd, int *dest)
{
	int iMid;

	if (iEnd - iBeg < 2) /* if run size == 1 */
		return;     /* consider it sorted */
	/* split the run longer than 1 item into halves */
	iMid = (iEnd + iBeg) / 2;

	TopDown_SplitMerge(dest, iBeg, iMid, source);  /* sort left run */
	TopDown_SplitMerge(dest, iMid, iEnd, source);  /* sort right run */
	/* merge the resulting runs from array[] into work_copy[] */
	Top_DownMerge(source, iBeg, iMid, iEnd, dest);
}

/**
 * merge_sort - sorts an array of integers in ascending order using a
 * top-down merge sort algorithm
 * @array: The array of integers to be sorted
 * @size:The  amount of elements in array
 */
void merge_sort(int *array, size_t size)
{
	int *work_copy;

	if (!array || size < 2)
		return;

	work_copy = malloc(sizeof(int) * size);
	if (!work_copy)
		return;

	Copy_Array(array, 0, size, work_copy);
	TopDown_SplitMerge(work_copy, 0, size, array);

	free(work_copy);
}
