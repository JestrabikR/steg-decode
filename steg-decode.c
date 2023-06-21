// steg-decode.c
// Řešení IJC-DU1, příklad b), 21.03.2023
// Autor: Radek Jestřabík, FIT
// Přeloženo: gcc 10.2

#include <stdio.h>
#include "bitset.h"
#include "eratosthenes.h"
#include "ppm.h"

#define START_PRIME 101

int main(int argc, char **argv) {
    if (argc != 2)
        error_exit("Špatný počet argumetů\n");

    struct ppm *img = ppm_read(argv[1]);
    if (!img)
        error_exit("Obrázek nebylo možné načíst\n");

    int text_end_exists = 0;
    int char_bit_position = 0;

    unsigned long int img_size = 3 * img->xsize * img->ysize;

    bitset_alloc(img_data_arr, img_size);

    Eratosthenes(img_data_arr);

    unsigned char color_value = 0;
    unsigned char ch = 0;

    for (unsigned int i = START_PRIME; i < img_size; i++) {
        if (bitset_getbit(img_data_arr, i))
            continue;

        color_value = (unsigned char)img->data[i];
        ch |= (0x1 & color_value) << char_bit_position;
        char_bit_position++;
        
        if (char_bit_position == 8) {
            putchar(ch);
            if (ch == '\0') {
                text_end_exists = 1;
                printf("\n");
                break;
            }
            char_bit_position = 0;
            ch = 0;
        }

    }

    ppm_free(img);    
    bitset_free(img_data_arr);

    if (!text_end_exists)
        error_exit("Ukrytá zpráva není ukončena znakem '\\0'\n");

    return 0;
}