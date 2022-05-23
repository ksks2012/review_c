#include "circular_list.h"
#include <stdlib.h>
#include <stdio.h>

void print_circular_list(const ListNode *head) {
	ListNode *tmp = head;
	printf("Traversal in forward direction \n");
	for (; tmp->next != head; tmp = tmp->next)
	    printf("%d ", tmp->value);
	printf("%d ", tmp->value);
    printf("\nTraversal in reverse direction \n");
    struct node *last = head->prev;
    for (tmp = last; tmp->prev != last; tmp = tmp->prev)
	printf("%d ", tmp->value);
    printf("%d ", tmp->value);
    printf("\n");
}

void _process_null_head(ListNode **head, void *input) {
	ListNode *new_node = node_new(input);
	new_node->next = new_node->prev = new_node;
	*head = new_node;
}

void circular_push_front(ListNode **head, void *input) {
	if(!*head) {
		_process_null_head(head, input);
		return;
	}
	ListNode *last = (*head)->prev;
	ListNode *new_node = node_new(input);
	new_node->next = *head;
	new_node->prev = last;
	last->next = (*head)->prev = new_node;
	*head = new_node;
}

void circular_push_back(ListNode **head, void *input) {
	if(!*head) {
		_process_null_head(head, input);
		return;
	}
	ListNode *last = (*head)->prev;
	ListNode *new_node = node_new(input);
	new_node->next = *head;
	(*head)->prev = new_node;
	new_node->prev = last;
	last->next = new_node;
}

void circular_insert_after(ListNode **head, void *input, void *value_after) {
	if(!*head)
		return;
	ListNode *new_node = node_new(input);
	ListNode *tmp = *head;
	while (tmp != (*head)->prev && tmp->value != value_after)
		tmp = tmp->next;
	// return if there is no match value_after
	if(tmp->value != value_after)
		return;
	ListNode *next_node = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
	new_node->next = next_node;
	next_node->prev = new_node;
}

void list_free(ListNode **head) {
	ListNode *tmp = *head;
	ListNode *ptr = *head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;

	while(!ptr) {
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}
