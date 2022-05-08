/*
 * Minimum number in rotate number array
 */
#include "./lib/cheader.h"

int min_inorder(int *numbers, int left, int right) {
	int result = numbers[left];

	for(int i = left + 1; i <= right; i++) {
		if(result > numbers[i]) {
			result = numbers[i];
		}
	}

	return result;
}

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
		if(numbers[left] == numbers[mid] && numbers[left] && numbers[mid]) {
			return min_inorder(numbers, left, right);
		}

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
	int numbers2[5] = {1, 1, 1, 0, 1};
	printf("%d\n", min_number(numbers2, 5));

	return 0;
}
