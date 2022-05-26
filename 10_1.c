#include <stdlib.h>
#include <stdio.h>

/*
 *  Determine if an integer is a power of two
 */
int power_of_two(int n) {
	int count = 0;
	while (n) {
		count++;
		n = (n - 1) & n;
		if(count > 1)
			return 0;
	}
	return 1;
}

int main() {
	printf("%s\n", power_of_two(0x1234) == 1 ? "Yes": "NO");
	printf("%s\n", power_of_two(0x80000000)== 1 ? "Yes": "NO");
	printf("%s\n", power_of_two(0x1)== 1 ? "Yes": "NO");
}
