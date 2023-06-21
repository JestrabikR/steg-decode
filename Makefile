CC=gcc
CFLAGS= -g -std=c11 -pedantic -Wall -Wextra -O2
.PHONY: all clean run

all: steg-decode primes primes-i


bitset.o: bitset.c
	$(CC) $(CFLAGS) -c bitset.c

bitset-i.o: bitset.c
	$(CC) -DUSE_INLINE $(CFLAGS) -o $@ -c bitset.c

steg-decode.o: steg-decode.c error.h eratosthenes.h bitset.h ppm.h
	$(CC) $(CFLAGS) -c steg-decode.c

steg-decode: error.o ppm.o steg-decode.o eratosthenes.o bitset.o
	$(CC) $(CFLAGS) $^ -o $@ -lm

primes.o: primes.c eratosthenes.h bitset.h error.h
	$(CC) $(CFLAGS) -c primes.c

primes: primes.o error.o eratosthenes.o bitset.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

primes-i.o: primes.c eratosthenes.h bitset-i.o error.h
	$(CC) -DUSE_INLINE $(CFLAGS) -o $@ -c primes.c

primes-i: primes-i.o error.o bitset-i.o eratosthenes-i.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

eratosthenes.o: eratosthenes.c eratosthenes.h error.h bitset.h
	$(CC) $(CFLAGS) -o $@ -c eratosthenes.c

eratosthenes-i.o : eratosthenes.c eratosthenes.h error.h bitset.h
	$(CC) -DUSE_INLINE $(CFLAGS) -o $@ -c eratosthenes.c

error.o: error.c error.h
	$(CC) $(CFLAGS) -c error.c

error: error.o
	$(CC) $(CFLAGS) -o $@ $^

ppm.o: ppm.h ppm.c error.h
	$(CC) $(CFLAGS) -c ppm.c

run: primes primes-i
	ulimit -s 32768; ./primes
	ulimit -s 32768; ./primes-i

clean:
	rm -f *.o steg-decode primes primes-i
