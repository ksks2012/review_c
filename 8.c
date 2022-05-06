/*
 * Minimum number in rotate number array
 */
#include "./lib/cheader.h"

int min_number(int *numbers, int length) {
	if(numbers == NULL || length < 0)
		return -1;

	int left = 0;
	int right = length - 1;
	int mid = left;

	while(numbers[left] >= numbers[right]) {
		if(right - left == 1) {
			mid = right;
			break;
		}

		mid = (left + right) / 2;
		if(numbers[left] <= numbers[mid]) {
			left = mid;
		} else if(numbers[right] >= numbers[mid]) {
			right = mid;
		}
	}
	return numbers[mid];
}

int main() {
	int numbers[5] = {3, 4, 5, 1, 2};
	printf("%d\n", min_number(numbers, 5));

	return 0;
}
