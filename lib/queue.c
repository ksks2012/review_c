#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue * queue_new(void) {
	Queue *head = (Queue *)malloc(sizeof(Queue));
	if(head == NULL)
		return NULL;
	head->begin = NULL;
	head->end = NULL;
	head->size = 0;
	return head;
}
void queue_delete(Queue *queue) {
	if(queue == NULL)
		return;

	ListNode *cur = queue->begin;
	while(cur) {
		ListNode *tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	free(queue);
}

bool queue_is_empty(const Queue *queue) {
	if(queue == NULL || queue->begin == NULL)
		return true;

	return false;
}

void * queue_peek(const Queue *queue) {
	assert(!queue_is_empty(queue));

	return queue->begin->value;
}

bool queue_enqueue(Queue *queue, void* input) {
	assert(queue);

	ListNode *cur_node = node_new(input);

	// head == NULL
	if(queue->begin == NULL) {
		queue->begin = cur_node;
		queue->end = cur_node;
		queue->size++;
		return true;
	}

	queue->end->next = cur_node;
	cur_node->prev = queue->end;
	queue->end = cur_node;
	queue->size++;

	return true;
}

void * queue_dequeue(Queue *queue) {
	assert(!queue_is_empty(queue));

	void* pop_val = queue->begin->value;

	if(queue->begin == queue->end) {
		free(queue->begin);
		queue->begin = queue->end = NULL;
	} else {
		ListNode* tmp = queue->begin;
		queue->begin = queue->begin->next;
		queue->begin->prev = NULL;
		free(tmp);
	}
	queue->size--;
	return pop_val;
}
