#ifndef SORT_H
#define SORT_H


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**
 * struct listint_s - Doubly linked list node
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





void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_items(int *a, int *b);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
int partition(int *array, int low, int high, size_t size);
void hoare_qsort(int *array, int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_next(listint_t **list, listint_t *node);
size_t listint_len(const listint_t *h);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
int *int_array_init(size_t size);
int *int_array_copy(int *array, size_t size);
void top_down_merge(int *a, int *b, size_t size, size_t mid);
void top_down_split_merge(int *a, int *b, size_t size);
void merge_sort(int *array, size_t size);
void swap_values(int **array, ssize_t i1, ssize_t i2);
void heap_sort_sift_down(int *array, size_t size, size_t start, size_t end);
void heap_sort(int *array, size_t size);
int *int_array_init(size_t size);
void count_sort(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);
void compare(int *array, int dir, size_t size);
void merge(int *array, int dir, size_t size);
void sort(int *array, int dir, size_t size, size_t subsiz);
void bitonic_sort(int *array, size_t size);
void swap_next(deck_node_t **deck, deck_node_t *node);
size_t deck_len(const deck_node_t *h);
int card_to_int(deck_node_t *node);
void sort_deck(deck_node_t **deck);



#endif

