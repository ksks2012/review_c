#include <stdlib.h>
#include "./lib/circular_list.h"

int main() {
    ListNode *head = NULL;
    circular_push_front(&head, 51);
	circular_push_back(&head, 48);
    circular_push_front(&head, 72);
	circular_push_front(&head, 86);
    circular_insert_after(&head, 63, 51);
	circular_insert_after(&head, 64, 52);
    print_circular_list(head);

    return 0;
}
