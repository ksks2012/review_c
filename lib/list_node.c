#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list_node.h"

ListNode* node_new(void* value) {
	ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
	if(new_node == NULL)
		return NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->value = (typeof(value))value;
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

void reverse_linking_list(ListNode **head) {
	ListNode *prev = NULL;
	ListNode *ptr = (*head)->next;

	(*head)->next = prev;
	while (ptr)
	{
		prev = (*head);
		*head = ptr;
		ptr = ptr->next;
		(*head)->next = prev;
	}
}

void swap_pair(ListNode **head)
{
	for (; *head && (*head)->next; head = &((*head)->next->next)) {
		ListNode *tmp = *head;
		*head = (*head)->next;
		tmp->next = (*head)->next;
		(*head)->next = tmp;
	}
}

// free linking list
void delete_linking_list(ListNode **head) {
	while (*head) {
		ListNode *next = (*head)->next;
		free(*head);
		*head = next;
	}
}

void fisher_yates_shuffle(ListNode **head) {
	srand(time(NULL));
	int count = 0;
	ListNode **indirect = head;
	while (*indirect)
	{
		indirect = &((*indirect)->next);
		count++;
	}

	ListNode *new = NULL;
	ListNode **new_head = &new;
	ListNode **new_tail = &new;

	while (count)
	{
		int random = rand() % count;
        indirect = head;

        while (random--)
            indirect = &(*indirect)->next;

        ListNode *tmp = *indirect;
        *indirect = (*indirect)->next;

        tmp->next = NULL;
		// TODO:
        if (new) {
            (*new_tail)->next = tmp;
            new_tail = &(*new_tail)->next;
        } else 
            new = tmp; 

        count--;
	}
	

	*head = *new_head;
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

// pop node on front
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

// pop node on back
void pop_back(ListNode **head) {

}

// TODO: remove node
// TODO: rotate list
