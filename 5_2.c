/*
 * Insertion sort of
 */
// #include "./lib/cheader.h"
#include "lib/sort.h"

int main() {
	int input[5] = {5, 4, 3, 2, 1};
	ListNode *head = array_to_list(input, 5);
	print_list(head);
	ListNode *new = list_insertion_sort(head);
	print_list(new);
}
