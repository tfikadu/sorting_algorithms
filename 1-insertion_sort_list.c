#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using an insertion sort algorithm
 * @list: doubly linked list of integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *lead, *follow, *new, *temp;

	if (!list || !(*list) || !((*list)->next))
		return;

	/* dance begins with 1st from house left following */
	follow = (*list);
	/* and next dancer to house right leading */
	lead = (*list)->next;
	while (lead)
	{
		new = lead->next;
		while (follow && lead->n < follow->n)
		{
			/* lead and follow swap positions */
			if (follow->prev)
				follow->prev->next = lead;
			else
				/* if lead makes it to house left, now head */
				*list = lead;
			if (lead->next)
				lead->next->prev = follow;
			temp = lead->next;
			lead->next = follow;
			lead->prev = follow->prev;
			follow->next = temp;
			follow->prev = lead;
			print_list(*list);
			/* compare next pair, flowing to house left */
			follow = lead->prev;
		}
		/* lead sorted to left, new cycle starts @ right leading edge */
		lead = new;
		if (lead)
			follow = lead->prev;
	}
}
