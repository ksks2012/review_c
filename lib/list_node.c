#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"

ListNode* node_new(void* value) {
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	if(head == NULL)
		return NULL;
	head->next = NULL;
	head->prev = NULL;
	head->value = value;

	return head;
}


ListNode* array_to_list(int *arr, int size) {

	if(arr == NULL || size <= 0) {
		return NULL;
	}
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	head->value = arr[0];

	ListNode *ptr = head;
	for(int i = 1; i < size; i++) {
		ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
		new_node->value = arr[i];
		ptr->next = new_node;
		ptr = ptr->next;
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
