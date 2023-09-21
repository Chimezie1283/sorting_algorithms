#ifndef SORT_H
#define SORT_H
#include <stddef.h>

/**
 * enum bool_e - manual definition of booleans, in case C99 stdbool.h not
 * available
 * @false: logical 0
 * @true: logical 1
 */
typedef enum bool_e
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - The doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Given functions prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* mandatory tasks prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* quick_sort() helpers prototypes */
int partision(int *array, int low, int high, size_t size);
void quiksot(int *array, int low, int high, size_t size);

/* advanced tasks prototypes */
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/* cocktail_sort_list() helper */
void dll_abj_swap(listint_t **list, listint_t *left, listint_t *right);

/* merge_sort() helpers prototypes */
void Print_Array(int *array, int iBeg, int iEnd);
void Copy_Array(int *array, int iBeg, int iEnd, int *work_copy);
void Top_DownMerge(int *array, int iBeg, int iMid, int iEnd, int *work_copy);
void TopDown_SplitMerge(int *work_copy, int iBeg, int iEnd, int *array);

/* heap_sort() helpers prototypes */
int z_Parent(int i);
int z_LeftChild(int i);
void Convert2Heap(int *array, size_t size);
void Shift_Down(int *array, size_t size, int start, int end);

#endif
