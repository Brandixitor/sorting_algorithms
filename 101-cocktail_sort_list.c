#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_next - swaps node with next node
 *
 * @list: address of pointer to head
 * @node: node to swap
 */

void swap_next(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * listint_len - returns the length of a linked list
 *
 * @h: head node to the list
 *
 * Return: the size of the list
 */

size_t listint_len(const listint_t *h)
{
	size_t cnt = 0;

	while (h != NULL)
	{
		cnt++;
		h = h->next;
	}

	return (cnt);
}

/**
 * cocktail_sort_list - sorts a list with cocktail shaker
 *
 * @list: the doubly linked list to sort
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1, lo = 0, hi, i = 0;
	listint_t *tmp;

	if (!list || !(*list) || !(*list)->next || listint_len(*list) < 2)
		return;
	tmp = *list;
	hi = (listint_len(*list) - 1);
	while (swapped)
	{
		swapped = 0;
		for (; i < hi; i++)
		{
			if (tmp->next->n < tmp->n)
			{
				swap_next(list, tmp);
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		for (; i > lo; i--)
		{
			if (tmp->prev->n > tmp->n)
			{
				swap_next(list, tmp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
		hi -= 1;
		lo += 1;
	}
}
