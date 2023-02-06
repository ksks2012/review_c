#include "./lib/cheader.h"

int main() {
	int input[4] = {1, 2, 3, 4};
	ListNode *head = array_to_list(input, 4);
	print_list(head);

	int insert = 5;
    insert_nth_last(&head, &insert, 2);
	print_list(head);

	int over_insert = 10;
    insert_nth_last(&head, &over_insert, 10);
	print_list(head);

	delete_linking_list(&head);
}
