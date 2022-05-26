#include <stdlib.h>
#include <stdio.h>

/*
 * with error loop
 */
int number_of_one_error_loop(int n) {
	int count = 0;
	while(n) {
		if(n & 1)
			count++;
		n >>= 1;
	}
	return count;
}

/*
 * with error loop
 */
int number_of_one_error_loop_fixed(int n) {
	int count = 0;
	unsigned int flag  = 1;
	while(flag) {
		if(n & flag)
			count++;
		flag <<= 1;
	}
	return count;
}

/*
 * count nubmer of 1 in binary
 */
int number_of_one(int n) {
	int count = 0;
	while (n) {
		count++;
		n = (n - 1) & n;
	}
	return count;
}

int main() {
	printf("%d\n", number_of_one_error_loop(0x1234));
	// NOTE: infinite loop
	// printf("%d\n", number_of_one_error_loop(0x80000000));

	printf("%d\n", number_of_one_error_loop_fixed(0x1234));
	printf("%d\n", number_of_one_error_loop_fixed(0x80000000));

	printf("%d\n", number_of_one(0x1234));
	printf("%d\n", number_of_one(0x80000000));
}
