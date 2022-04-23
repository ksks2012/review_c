#include "./lib/cheader.h"

int main() {
	int input[4] = {1, 2, 3, 4};
	ListNode *head = array_to_list(input, 4);
	print_list(head);
	for(int i = 10; i < 15; i++) {
		push_front(&head, i);
	}
	print_list(head);
	for(int i = 0; i < 5; i++) {
		pop_front(&head);
	}
	print_list(head);
}
