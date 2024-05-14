#include <stdio.h>

#include "include/sign.h"
#include "include/api.h"

#ifdef __linux__
    #undef __linux__
#endif
#define ESP32

void app_main(void)
{
    printf("Inicio\n\r");
    uint8_t *pk = (uint8_t*) malloc(CRYPTO_PUBLICKEYBYTES * sizeof(uint8_t));
    uint8_t *sk = (uint8_t*) malloc(CRYPTO_SECRETKEYBYTES * sizeof(uint8_t));
    printf("Alocao\n\r");

    crypto_sign_keypair(pk, sk);
    printf("Llamada\n\r");

    free(pk);
    free(sk);
}
