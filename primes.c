// primes.c
// Řešení IJC-DU1, příklad a), 21.03.2023
// Autor: Radek Jestřabík, FIT
// Přeloženo: gcc 10.2

#include <time.h>
#include <stdio.h>

#include "bitset.h"
#include "eratosthenes.h"

#define N 230000000
#define PRINT_COUNT 10

int main() {

    clock_t start = clock();

    bitset_create(arr, N);
    
    Eratosthenes(arr);

    bitset_index_t primes[PRINT_COUNT] = {0};
    int primes_length = PRINT_COUNT;

    for (bitset_index_t i = N-1; i > 0; i--) {
        if (primes_length == 0)
            break;

        if (!bitset_getbit(arr, i))
            primes[--primes_length] = i;
    }

    for (int i = 0; i < PRINT_COUNT; i++) {
        printf("%lu\n", primes[i]);
    }
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
}