// ppm.h
// Řešení IJC-DU1, příklad b), 21.03.2023
// Autor: Radek Jestřabík, FIT
// Přeloženo: gcc 10.2

#ifndef PPM_H
#define PPM_H

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm *ppm_read(const char *filename);

void ppm_free(struct ppm *p);

#endif