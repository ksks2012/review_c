#include <stdlib.h>
#include <stdio.h>
#include <time.h>

long long recursive_feb(unsigned n) {
	if(n == 1 || n == 0)
		return 1;

	return recursive_feb(n - 1) + recursive_feb(n - 2);
}

long long loop_feb(unsigned n) {
	// int result[2] = {0, 1};

	if(n < 2)
		return 1;

	long long min_one = 1;
	long long min_two = 1;
	long long fib_n = 0;

	for(int i = 2; i <= n; i++) {
		fib_n = min_one + min_two;
		min_two = min_one;
		min_one = fib_n;
	}
	return fib_n;
}

int main() {
	int n = 5;

	printf("%lld\n", recursive_feb(n));
	printf("%lld\n", loop_feb(n));


	clock_t start, end;
	double recursive_cpu_time_used = 0;
	double loop_cpu_time_used = 0;

	for(int i = 0; i < 20; i++) {
		start = clock();
		long long recursive_result = recursive_feb(i);
		end = clock();
		recursive_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;

		start = clock();
		long long loop_result = loop_feb(i);
		end = clock();
		loop_cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;

		if(recursive_result != loop_result) {
			printf("%d diff %lld %lld\n", i, recursive_result, loop_result);
			return;
		}

	}
	printf("recursive_cpu_time_used: %.10f\n", recursive_cpu_time_used);
	printf("loop_cpu_time_used: %.10f\n", loop_cpu_time_used);
	return 0;
}
