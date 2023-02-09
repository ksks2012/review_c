#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list_node.h"

inline ListNode* node_new(void* value) {
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
		push_back(&head, &(arr[i]));
	}
	return head;
}

void print_list(const ListNode *head) {
	ListNode const *ptr = head;
	while (ptr)
	{
		/* code */
		printf("%d -> ", *((int *)(ptr->value)));
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

void insert_nth_last(ListNode **head, void *input, int n) {
	/*
		insert the node to list in n-th position from last
		if n > length of node then push in front
	*/
	ListNode **fast_ptr = head;
	ListNode **slow_ptr = head;
	ListNode *new_node = node_new(input);

	for(int i = 0; i < n; i++) {
		if (*fast_ptr == NULL) {
			push_front(head, input);
			return;
		}
		fast_ptr = &((*fast_ptr)->next);
	}

	while(*fast_ptr) {
		fast_ptr = &((*fast_ptr)->next);
		slow_ptr = &((*slow_ptr)->next);
	}
	new_node->next = (*slow_ptr)->next;
	(*slow_ptr)->next = new_node;
	new_node->prev = (*slow_ptr);
	new_node->next->prev = new_node;
}

void remove_nth_node(ListNode **head, int n) {
	ListNode **indirect = head;
	
	int count = 0;
	while (*indirect && count < n - 1)
	{
		indirect = &((*indirect)->next);
		count++;
	}
	// printf("%d ", *((int *)((*indirect)->value)));
	ListNode **tmp = (*indirect)->next;
	if(tmp == NULL) {
		return;
	}
	(*indirect)->next = (*indirect)->next->next;
	(*indirect)->prev = (*indirect);
	free(tmp);
}

inline void list_add_node(ListNode **list, ListNode *new_node) {
    new_node->next = *list;
    *list = new_node;
}

inline void list_concat(ListNode **left, ListNode *right) {
    while (*left)
        left = &((*left)->next);
    *left = right;
}
// TODO: remove node
// TODO: rotate list
