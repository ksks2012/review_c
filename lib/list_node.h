#ifndef __LIST_NODE_H__
#define __LIST_NODE_H__

#ifndef BOOL
typedef enum bool {
	false,
	true
} bool;
#define BOOL
#endif

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
ListNode *reverse_linking_list(ListNode*);
void swap_pair(ListNode **);
void delete_linking_list(ListNode **);

void push_front(ListNode **, void *);
void push_back(ListNode **, void *);
void pop_front(ListNode **);
void pop_back(ListNode **);

#endif
