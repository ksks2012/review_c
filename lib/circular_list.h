#ifndef __CIRCULAR_LIST_H__
#define __CIRCULAR_LIST_H__

#include "list_node.h"

void print_circular_list(const ListNode *);

void circular_push_front(ListNode **, void *);
void circular_push_back(ListNode **, void *);
void circular_insert_after(ListNode **, void *, void *);

void list_free(ListNode **);

#endif
