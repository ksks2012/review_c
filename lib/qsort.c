#include "sort.h"

int ranom_in_range(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int partition(int *data, int length, int l, int r) {
	if(data == NULL || length <= 0 || l < 0 || r >= length) {
		assert(data);
	}
	int index = ranom_in_range(l, r);
	swap(data[l], data[r]);

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
