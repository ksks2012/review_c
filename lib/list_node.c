#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"

ListNode* node_new(void* value) {
	ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
	if(new_node == NULL)
		return NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->value = value;

	return new_node;
}


ListNode* array_to_list(int *arr, int size) {

	if(arr == NULL || size <= 0) {
		return NULL;
	}
	ListNode *head = NULL;
	for(int i = 0; i < size; i++) {
		push_back(&head, arr[i]);
	}
	return head;
}

void print_list(const ListNode *head) {
	ListNode const *ptr = head;
	while (ptr)
	{
		/* code */
		printf("%d -> ", ptr->value);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

ListNode* reverse_linking_list(ListNode *head) {
	ListNode *new = NULL;
	ListNode *ptr = node_new(NULL);
	ptr->next = head;

	while(ptr->next) {
		ListNode *new_node = node_new(ptr->next->value);
		if(new == NULL)
			new = new_node;
		else {
			new_node->next = new;
			new = new_node;
		}
		ptr = ptr->next;
	}

	return new;
}

// add node to front
void push_front(ListNode **head, void *input) {
	ListNode *new_node = node_new(input);
	if(*head == NULL) {
		*head = new_node;
		return;
	}
	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;
	return;
}

// add node to back
void push_back(ListNode **head, void *input) {
	ListNode **indirect = head;
	ListNode *new_node = node_new(input);
	while (*indirect)
	{
		indirect = &((*indirect)->next);
	}
	*indirect = new_node;
	new_node->prev = *indirect;
}

// TODO: first node

// add node on front
void pop_front(ListNode **head) {
	ListNode *tmp = *head;
	if(*head) {
		(*head) = ((*head)->next);
	}
	if(*head) {
		(*head)->prev = NULL;
	}
	free(tmp);
}

// add node on back
void pop_back(ListNode **head) {

}

// TODO: remove node
// TODO: rotate list
