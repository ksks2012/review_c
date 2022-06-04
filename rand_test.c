#include <time.h>
#include "lib/ks_random.h"

int main() {
    init_rand(time(NULL));

    long long int zero_count = 0;
    long long int one_count = 0;
    for(long long int i = 0; i < 1000000000; i++) {
        if(rand_range(0, 1))
            ++one_count;
        else
            ++zero_count;
    }
    printf("%lld %lld\n", one_count, zero_count);
    printf("rate: %.5f", (float)one_count / (float)zero_count);
}