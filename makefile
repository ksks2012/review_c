CFLAGS = -pg

LIB = $(wildcard lib/*.c)
all: 7.out
# 3.out 4.out 5.out 6.out

7.out: 7.c $(LIB:%.c=%.o)
	gcc -o $@ $(CFLAGS) $^

6.out: 6.c $(LIB:%.c=%.o)
	gcc -o $@ $(CFLAGS) $^

5.out: 5.c $(LIB:%.c=%.o)
	gcc -o $@ $(CFLAGS) $^

4.out: 4.c $(LIB:%.c=%.o)
	gcc -o $@ $(CFLAGS) $^

3.out: 3.c $(LIB:%.c=%.o)
	gcc -o $@ $(CFLAGS) $^

clean:
	rm -rf *.o *.a *.out main
