#include "sort.h"

/**
 * insertion_sort_list - This sorts a doubly linked list of integers in ascending
 * order using an insertion sort algorithm
 * @list: The doubly linked list of integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *lead, *folow, *new, *tep;

	if (!list || !(*list) || !((*list)->next))
		return;

	/* dance begins with 1st from house left following */
	folow = (*list);
	/* and next dancer to house right leading */
	lead = (*list)->next;
	while (lead)
	{
		new = lead->next;
		while (folow && lead->n < folow->n)
		{
			/* lead and follow swap positions */
			if (folow->prev)
				folow->prev->next = lead;
			else
				/* if lead makes it to house left, now head */
				*list = lead;
			if (lead->next)
				lead->next->prev = follow;
			tep = lead->next;
			lead->next = folow;
			lead->prev = folow->prev;
			folow->next = tep;
			folow->prev = lead;
			print_list(*list);
			/* compare next pair, flowing to house left */
			folow = lead->prev;
		}
		/* lead sorted to left, new cycle starts @ right leading edge */
		lead = new;
		if (lead)
			folow = lead->prev;
	}
}
