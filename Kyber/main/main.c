#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "kem.h"
#include "api.h"

// #include "sdkconfig.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "esp_chip_info.h"
// #include "esp_flash.h"
// #include "esp_system.h"

// #include "esp_random.h"
// #include "bootloader_random.h"


void app_main (void)
{
    printf("Inicio\n\r");
    unsigned char *pk, *sk;
    pk = (unsigned char*) malloc(KYBER_INDCPA_PUBLICKEYBYTES * sizeof(unsigned char));
    sk = (unsigned char*) malloc(KYBER_INDCPA_SECRETKEYBYTES * sizeof(unsigned char));
    
    // pqcrystals_kyber512_ref_keypair(pk, sk);

    // crypto_kem_keypair(pk, sk);

    // unsigned char pk[CRYPTO_PUBLICKEYBYTES*2], sk[CRYPTO_SECRETKEYBYTES*2];
    int ret_val;

    if ( (ret_val = crypto_kem_keypair(pk, sk)) != 0) {
        printf("Crypto_kem_keypair returned <%d>\n\r", ret_val);
    }

    printf("Terminado\n\r");

    free(pk);
    free(sk);
}