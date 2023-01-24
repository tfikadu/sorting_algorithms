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
 * struct listint_s - Doubly linked list node
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

/* supplied functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* mandatory tasks */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* quick_sort() helpers */
int partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);

/* advanced tasks */
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
/* void sort_deck(deck_node_t **deck); */

/* cocktail_sort_list() helper */
void dll_adj_swap(listint_t **list, listint_t *left, listint_t *right);

/* merge_sort() helpers */
void PrintArray(int *array, int iBeg, int iEnd);
void CopyArray(int *array, int iBeg, int iEnd, int *work_copy);
void TopDownMerge(int *array, int iBeg, int iMid, int iEnd, int *work_copy);
void TopDownSplitMerge(int *work_copy, int iBeg, int iEnd, int *array);

/* heap_sort() helpers */
int iParent(int i);
int iLeftChild(int i);
void ConvertToHeap(int *array, size_t size);
void SiftDown(int *array, size_t size, int start, int end);

#endif /* SORT_H */
