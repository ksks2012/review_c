/*
 * How many bits to change from number m to number n
 */

#include <stdlib.h>
#include <stdio.h>

int number_of_one(int n) {
	int count = 0;
	while (n) {
		count++;
		n = (n - 1) & n;
	}
	return count;
}

int main() {
	int m = 0x1234;
	int n = 0x4567;
	printf("%d\n", number_of_one(m ^ n));
}
