#ifndef __SORT_H__
#define __SORT_H__

#include <time.h>
#include <stdlib.h>
#include <assert.h>

#include "list_node.h"

#ifndef BOOL
typedef enum bool {
	false,
	true
} bool;
#endif

#define swap(x,y) {int t; (t)=(x); (x)=(y); (y)=(t);}

void quick_sort(int *, int, int, int);
void bubble_sort(int *, int);
void merge_sort(int *, int, int, int *);
// TODO:
// void counting_sort(void *v, int k);

void list_quick_sort(ListNode **);
ListNode* list_insertion_sort(ListNode *);
ListNode* circular_list_insertion_sort(ListNode *);

#endif
