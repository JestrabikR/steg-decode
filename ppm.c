// ppm.c
// Řešení IJC-DU1, příklad b), 21.03.2023
// Autor: Radek Jestřabík, FIT
// Přeloženo: gcc 10.2

#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "ppm.h"

struct ppm *ppm_read(const char *filename) {
    struct ppm *img;
    FILE *fp;
    char buffer[16];

    fp = fopen(filename, "rb");
    if (!fp) {
        warning("Chyba při otevírání obrázku %s\n", filename);
        return NULL;
    }

    if (!fgets(buffer, sizeof(buffer), fp)) {
        warning("Buffer nebyl načten správně\n");
        goto close_file_return_null;
    }

    if (buffer[0] != 'P' || buffer[1] != '6') {
        warning("Formát obrázku není P6\n");
        goto close_file_return_null;
    }

    unsigned int xsize;
    unsigned int ysize;

    if (fscanf(fp, "%u %u", &xsize, &ysize) != 2) {
        warning("Chybná velikost obrázku\n");
        goto close_file_return_null;
    }

    int maxval;

    if (fscanf(fp, "%d", &maxval) != 1) {
        warning("Chybná barevná složka\n");
        goto close_file_return_null;
    }

    if (maxval != 255) {
        warning("Chybná velikost barevné složky\n");
        goto close_file_return_null;
    }

    img = (struct ppm *) malloc(sizeof(struct ppm) + 3 * xsize * ysize); 
    if (!img) {
        fclose(fp);
        error_exit("Chyba při alokaci paměti\n");
    }

    img->xsize = xsize;
    img->ysize = ysize;

    fgetc(fp);
    fread(img->data, 3 * img->xsize * img->ysize, 1, fp);

    fclose(fp);

    return img;

close_file_return_null:
    fclose(fp);
    return NULL;
}

void ppm_free(struct ppm *p) {
    if (p) {
        free(p);
    }
}