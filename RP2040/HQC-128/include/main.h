#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

//Necesario para generación de números aleatorios
#ifdef __linux__
    #undef __linux__
#endif
#ifndef RP2040
    #define RP2040
#endif

void printBstr(char *S, unsigned char *A, unsigned long long L);

#endif