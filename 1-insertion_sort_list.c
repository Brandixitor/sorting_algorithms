#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a linked list using insertion sort
 *
 * @list: the address of a pointer to the head of a list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *n1, *n2;

	if (list == NULL || *list == NULL)
		return;

	n1 = (*list)->next;

	while (n1 != NULL)
	{
		n2 = n1->next;
		while (n1->prev != NULL && n1->prev->n > n1->n)
		{
			n1->prev->next = n1->next;

			if (n1->next)
				n1->next->prev = n1->prev;

			n1->next = n1->prev;
			n1->prev = n1->next->prev;
			n1->next->prev = n1;

			if (!n1->prev)
				*list = n1;
			else
				n1->prev->next = n1;
			print_list(*list);
		}
		n1 = n2;
	}
}
