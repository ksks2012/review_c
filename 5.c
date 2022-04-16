#include "./lib/cheader.h"

ListNode* reverse_linking_list(ListNode *head) {
	ListNode *new = NULL;
	ListNode *ptr = head;

	if(head == NULL)
		return NULL;

	while(ptr) {
		ListNode *new_node = node_new(ptr->value);
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

int main() {
	int input[4] = {1, 2, 3, 4};
	ListNode *head = array_to_list(input, 4);
	print_list(head);
	print_list(reverse_linking_list(head));
	print_list(head);
}
