#include "./lib/cheader.h"

int main() {
	int input[4] = {1, 2, 3, 4};
	ListNode *head = array_to_list(input, 4);
	print_list(head);

	remove_nth_node(&head, 3);
	print_list(head);

	remove_nth_node(&head, 3);
	print_list(head);

	remove_nth_node(&head, 0);
	print_list(head);

	delete_linking_list(&head);
}
