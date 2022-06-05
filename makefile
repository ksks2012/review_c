CFLAGS = -O2 -g -Wall -Wno-unused-variable

LIB = $(wildcard lib/*.c)
all: ${target}.out
# 3.out 4.out 5.out 5_1.out 5_2.out 5_3.out 5_4.out \
# 6.out 7.out 7_1.out 8.out 9.out 10.out 10_1.out 10_2.out

%.out: %.c $(LIB:%.c=%.o)
	gcc -o $@ $(CFLAGS) $^

clean:
	rm -rf *.o *.a *.out main
