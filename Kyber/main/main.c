#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "kem.h"
#include "api.h"

// #include "esp_random.h"
// #include "bootloader_random.h"

void app_main (void)
{
    printf("Inicio con la opción %d\n\r", KYBER_K);
    unsigned char *pk, *sk;
    pk = (unsigned char*) malloc(KYBER_INDCPA_PUBLICKEYBYTES * sizeof(unsigned char));
    sk = (unsigned char*) malloc(KYBER_INDCPA_SECRETKEYBYTES * sizeof(unsigned char));

    if (crypto_kem_keypair(pk, sk) != 0) {
        printf("Generacion de claves fallida\n\r");
    } else {
        printf("Generacion de claves exitosa (%d bytes de clave publica y %d bytes de clave privada)\n\r", KYBER_INDCPA_PUBLICKEYBYTES, KYBER_INDCPA_SECRETKEYBYTES);
    }

    free(pk);
    free(sk);
}