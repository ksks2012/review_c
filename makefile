CFLAGS = -O0 -g -Wall

LIB = $(wildcard lib/*.c)
all: 10_2.out
# 3.out 4.out 5.out 5_1.out 5_2.out 5_3.out 6.out 7.out 7_1.out 8.out 9.out 10.out 10_1.out 10_2.out

%.out: %.c $(LIB:%.c=%.o)
	gcc -o $@ $(CFLAGS) $^

clean:
	rm -rf *.o *.a *.out main
