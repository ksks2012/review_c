#ifndef __STACK_H__
#define __STACK_H__

#include "list_node.h"
#include "assert.h"

typedef struct Stack {
	ListNode *top;

	int size;
}Stack;

Stack * stack_new(void);
void stack_delete(Stack *);
bool stack_is_empty(const Stack *);
void * stack_top(const Stack *);
bool stack_push(Stack *, void *);
void * stack_pop(Stack *);

#endif
