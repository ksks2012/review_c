#ifndef __LIST_NODE_H__
#define __LIST_NODE_H__

typedef enum bool {
	false,
	true
} bool;

typedef struct ListNode
{
	/* data */
	void * value;
	struct ListNode *next;
	struct ListNode *prev;
}ListNode;


ListNode* node_new(void *);
ListNode* array_to_list(int *, int);
void print_list(const ListNode *);

void push_front(ListNode **, void *);
void push_back(ListNode **, void *);
void pop_front(ListNode **);
void pop_back(ListNode **);

#endif
