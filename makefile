CFLAGS = -pg

LIB = $(wildcard lib/*.c)
all: 3.out

3.out: 3.c $(LIB:%.c=%.o)
	gcc -o $@ $(CFLAGS) $^

clean:
	rm -rf *.o *.a *.out main
