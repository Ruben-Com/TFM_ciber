#ifndef MAIN_H
#define MAIN_H

//Necesario para generación de números aleatorios
#ifdef __linux__
    #undef __linux__
#endif
#ifndef ESP32
    #define ESP32
#endif

#ifndef KYBER_K
    #define KYBER_K 3	/*{2,3,4}*/
#endif

#endif