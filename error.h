// error.h
// Řešení IJC-DU1, příklad b), 21.03.2023
// Autor: Radek Jestřabík, FIT
// Přeloženo: gcc 10.2

#ifndef ERROR_H
#define ERROR_H

void warning(const char *fmt, ...);

void error_exit(const char *fmt, ...);

#endif