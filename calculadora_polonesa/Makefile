CC=gcc

CFLAGS=-Wall -Wextra -Werror -O0 -g -std=c11 -I.. 
LDLIBS=-lm

.PHONY: le p_f all clean


all: test
	./test

le.o: le.c
	$(CC) $(CFLAGS) -c le.c

p_f.o: p_f.c
	$(CC) $(CFLAGS) -c p_f.c

calc.o: calc.c
	$(CC) $(CFLAGS) -c calc.c


# coloque outras dependencias aqui


test: le.o p_f.o calc.o test.c


clean:
	rm -f *.o test


