#include "stdio.h"
#include "lib/sort.h"

int main() {
	int input[5] = {3, 4, 1, 2, 5};
	// quick_sort(input, 5, 0, 4);
	// bubble_sort(input, 5);
	int tmp[5] = {0};
	merge_sort(input, 0, 5, tmp);

	for(int i = 0; i < 5; i++) {
		printf("%d, ", input[i]);
	}
	printf("\n");
}
