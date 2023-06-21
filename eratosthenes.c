// eratosthenes.c
// Řešení IJC-DU1, příklad a), 21.03.2023
// Autor: Radek Jestřabík, FIT
// Přeloženo: gcc 10.2

#include "eratosthenes.h"
#include "bitset.h"
#include "error.h"
#include <math.h>

void Eratosthenes(bitset_t pole) {
    bitset_setbit(pole, 0, 1);
    bitset_setbit(pole, 1, 1);

    unsigned long velikost_pole = sqrt(bitset_size(pole));

    for (bitset_index_t i = 2; i <= velikost_pole; i++) {
        if (bitset_getbit(pole, i) == 0) {
            for (bitset_index_t j = i*i; j < bitset_size(pole); j+=i) {
                bitset_setbit(pole, j, 1);
            }
        }
    }
}