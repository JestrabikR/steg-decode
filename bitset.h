// bitset.h
// Řešení IJC-DU1, příklad a), 21.03.2023
// Autor: Radek Jestřabík, FIT
// Přeloženo: gcc 10.2

#ifndef BITSET_H
#define BITSET_H

#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "error.h"

typedef unsigned long *bitset_t;
typedef unsigned long bitset_index_t;

#define ULONG_BITSIZE (CHAR_BIT * sizeof(unsigned long)) //CHAR_BIT = počet bitů v bajtu

#ifdef USE_INLINE

static inline void bitset_free(bitset_t jmeno_pole) {
    free(jmeno_pole);
    jmeno_pole = NULL;
}

static inline bitset_index_t bitset_size(const bitset_t jmeno_pole) {
    return jmeno_pole[0];
}

static inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz) {
    if (index >= bitset_size(jmeno_pole))
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bitset_size(jmeno_pole)-1);
    if (vyraz)
        (jmeno_pole)[index / ULONG_BITSIZE + 1] |= (1UL << (index % ULONG_BITSIZE));
    else
        (jmeno_pole)[index / ULONG_BITSIZE + 1] &= ~(1UL << (index % ULONG_BITSIZE));
}

static inline unsigned long bitset_getbit(bitset_t jmeno_pole, bitset_index_t index) {
    if ((unsigned long)index >= bitset_size(jmeno_pole))
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bitset_size(jmeno_pole)-1);
    return (((jmeno_pole)[index / ULONG_BITSIZE + 1] >> (index % ULONG_BITSIZE)) & 1);
}

#else

#define bitset_free(jmeno_pole) \
    free(jmeno_pole)

#define bitset_size(jmeno_pole) \
   jmeno_pole[0]

#define bitset_setbit(jmeno_pole, index, vyraz) \
    do { \
        if (index >= bitset_size(jmeno_pole)) \
            error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bitset_size(jmeno_pole)-1); \
        if (vyraz) \
            (jmeno_pole)[index / ULONG_BITSIZE + 1] |= (1UL << (index % ULONG_BITSIZE)); \
        else \
            (jmeno_pole)[index / ULONG_BITSIZE + 1] &= ~(1UL << (index % ULONG_BITSIZE)); \
    } while(0)

#define bitset_getbit(jmeno_pole, index) \
    (index >= bitset_size(jmeno_pole) \
        ? error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bitset_size(jmeno_pole)-1), 0 \
        : (((jmeno_pole)[index / ULONG_BITSIZE + 1] >> (index % ULONG_BITSIZE)) & 1))
#endif

#define bitset_create(jmeno_pole, velikost) \
    static_assert((velikost) > 0, "Velikost pole musí být kladná"); \
    static_assert((velikost) <= (ULONG_MAX / CHAR_BIT), "Pole je příliš velké"); \
    unsigned long jmeno_pole[(velikost + ULONG_BITSIZE - 1) / ULONG_BITSIZE] = {(velikost), 0};

#define bitset_alloc(jmeno_pole, velikost) \
    assert((velikost) > 0); \
    assert((velikost) <= ULONG_MAX / CHAR_BIT); \
    bitset_t jmeno_pole = (bitset_t) calloc(((velikost) + CHAR_BIT - 1) / CHAR_BIT * sizeof(unsigned long), sizeof(unsigned long)); \
    if (jmeno_pole == NULL) \
        error_exit("bitset_alloc: Chyba alokace paměti\n"); \
    jmeno_pole[0] = (velikost);

#endif
