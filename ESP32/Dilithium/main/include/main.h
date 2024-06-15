#ifndef MAIN_H
#define MAIN_H

//Necesario para generación de números aleatorios
#ifdef __linux__
    #undef __linux__
#endif
#ifndef ESP32
    #define ESP32
#endif

#ifndef DILITHIUM_MODE
    #define DILITHIUM_MODE 3	/*{2,3,5}*/
#endif

void printBstr(char *S, unsigned char *A, unsigned long long L);

#endif
