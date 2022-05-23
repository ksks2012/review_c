#include "circular_list.h"
#include "sort.h"
#include <stdio.h>

int ranom_in_range(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int partition(int *data, int length, int l, int r) {
	if(data == NULL || length <= 0 || l < 0 || r >= length) {
		assert(data);
	}
	int index = ranom_in_range(l, r);
	swap(data[index], data[r]);

	int small = l - 1;
	for(int i = l; i < r; ++i) {
		if(data[i] < data[r]) {
			++small;
			if(small != i) {
				swap(data[i], data[small]);
			}
		}
	}
	++small;
	swap(data[small], data[r]);
	return small;
}

void quick_sort(int *nums, int length, int l, int r) {
	if (l == r)
		return;

	int index = partition(nums, length, l, r);
	if(index > l)
		quick_sort(nums, length, l, index - 1);
	if(index < r)
		quick_sort(nums, length, index + 1, r);
}

void bubble_sort(int arr[], int len)
{
	int i, j, temp;
	bool flag = true;
	for (i = 0; i < len - 1 && flag; ++i) {
		flag = false;
		for (j = 0; j < len - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j+1]);
				flag = true;
			}
		}
	}
}

void merge_sort(int *nums, int left, int right, int *tmp) {
	if (left + 1 >= right) {
		return;
	}
	// divide
	int mid = left + (right - left) / 2;
	merge_sort(nums, left, mid, tmp);
	merge_sort(nums, mid, right, tmp);
	// conquer
	int p = left, q = mid, i = left;
	while (p < mid || q < right) {
		if (q >= right || (p < mid && nums[p] <= nums[q])) {
			tmp[i++] = nums[p++];
		} else {
			tmp[i++] = nums[q++];
		}
	}
	for (i = left; i < right; ++i) {
		nums[i] = tmp[i];
	}
}

ListNode* list_insertion_sort(ListNode *start) {
	if (!start || !start->next)
		return start;
	ListNode *left = start;
	ListNode *right = left->next;
	left->next = NULL; // sub linking ListNode

	printf("left: ");
	print_list(left);
	printf("right: ");
	print_list(right);

	left = list_insertion_sort(left);
	right = list_insertion_sort(right);

	for (ListNode *merge = NULL; left || right; ) {
		if (!right || (left && left->value < right->value)) {
			if (!merge) {
				start = merge = left; // init merge, start = left
			} else {
				// insert
				merge->next = left;
				merge = merge->next;
			}
			left = left->next; // left = NULL, finish loop
		} else {
			if (!merge) {
				start = merge = right; // init merge, start = right
			} else {
				merge->next = right;
				merge = merge->next;
			}
			right = right->next;
		}
	}
	return start;
}

ListNode* circular_list_insertion_sort(ListNode *start) {
	if (!start || start->next == start)
		return start;
	ListNode *left = start;
	ListNode *right = left->next;

	left->next = left;
	left->prev->next = right;
	right->prev = left->prev;
	left->prev = left;

	printf("left: ");
	print_circular_list(left);
	printf("right: ");
	print_circular_list(right);

	left = circular_list_insertion_sort(left);
	right = circular_list_insertion_sort(right);

	for (ListNode *merge = NULL; left || right != start;) {
		if (right == start || (left && left->value < right->value)) {
			if (!merge) {
				start = merge = left; // init merge, start = left
			} else {
				// insert
				left->prev = merge;
                left->next = merge->next;
                merge->next = left;
                left->next->prev = left;

				merge = merge->next;
			}
			left = NULL; // left = NULL, finish loop
		} else {
			if (!merge) {
				start = merge = right; // init merge, start = right
			} else {
				// when merge points to the left element
				if (merge == merge->next) {
					merge->next = right;
                    merge->prev = right->prev;
                    right->prev->next = merge;
                    right->prev = merge;
				}
                merge = merge->next;
			}
			right = right->next;
		}
	}
	return start;
}
