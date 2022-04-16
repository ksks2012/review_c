#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "list_node.h"
#include "assert.h"

typedef enum bool {
	false,
	true
} bool;

typedef struct Queue {
	ListNode *begin;
	ListNode *end;

	int size;
}Queue;

Queue * queue_new(void);
void queue_delete(Queue *);
bool queue_is_empty(const Queue *);
void * queue_peek(const Queue *);
bool queue_enqueue(Queue *, void *);
void * queue_dequeue(Queue *);

#endif
