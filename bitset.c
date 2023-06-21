// bitset.c
// Řešení IJC-DU1, příklad a), 21.03.2023
// Autor: Radek Jestřabík, FIT
// Přeloženo: gcc 10.2

#include "bitset.h"

#ifdef USE_INLINE

static inline void bitset_free(bitset_t jmeno_pole);
static inline bitset_index_t bitset_size(const bitset_t jmeno_pole);
static inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz);
static inline unsigned long bitset_getbit(bitset_t jmeno_pole, bitset_index_t index);

#endif