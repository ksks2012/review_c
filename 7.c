#include "./lib/stack.h"

/*
 *	use two stack to implement queue
 */

typedef struct CQueue
{
	/* data */
	Stack *st1;
	Stack *st2;
}CQueue;

void append_tail(CQueue *cqueue, void *value) {
	stack_push(cqueue->st1, value);
}

void* delete_head(CQueue *cqueue) {
	if(cqueue->st2->size <= 0) {

		while (cqueue->st1->size) {
			/* code */
			ListNode* tmp = stack_pop(cqueue->st1);
			stack_push(cqueue->st2, tmp);

		}

	}

	if(cqueue->st2->size == 0)
		return;

	ListNode* head = stack_pop(cqueue->st2);
	return head;
}


int main(){
	int input[3] = {1, 2, 3};

	CQueue *cqueue = (CQueue *)malloc(sizeof(CQueue));
	cqueue->st1 = stack_new();
	cqueue->st2 = stack_new();

	for(int i = 0; i < 3; i++) {
		append_tail(cqueue, input[i]);
	}
	for(int i = 0; i < 6; i++) {
		printf("%d\n", delete_head(cqueue));
		append_tail(cqueue, i * 2);
	}
}
