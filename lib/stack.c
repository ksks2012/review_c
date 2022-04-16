#include <stdlib.h>
#include "stack.h"

// NOTE: maybe turn to list based?
Stack * stack_new(void) {
	Stack *head = (Stack *)malloc(sizeof(Stack));
	if(head == NULL)
		return NULL;
	head->top = NULL;
	head->size = 0;
	return head;
}

void stack_delete(Stack *stack) {
	if(stack == NULL)
		return;

	ListNode *cur = stack->top;
	while(cur) {
		ListNode *tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	free(stack);
}

bool stack_is_empty(const Stack *stack) {
	if(stack == NULL || stack->top == NULL)
		return true;

	return false;
}

void * stack_top(const Stack *stack) {
	assert(!stack_is_empty(stack));

	return stack->top->value;
}

bool stack_push(Stack *stack, void *input) {
	assert(stack);

	ListNode *cur_node = node_new(input);
	if(stack->top == NULL) {
		stack->top = cur_node;
		stack->size++;
		return true;
	}

	stack->top->next = cur_node;
	cur_node->prev = stack->top;
	stack->top = cur_node;
	stack->size++;

	return true;
}

void * stack_pop(Stack *stack) {
	assert(!queue_is_empty(stack));

	void* pop_val = stack->top->value;

	if(stack->top->prev != NULL) {
		ListNode* tmp = stack->top;
		stack->top = stack->top->prev;
		stack->top->next = NULL;
		free(tmp);
	} else {
		free(stack->top);
		stack->top = NULL;
	}

	stack->size--;
	return pop_val;
}
