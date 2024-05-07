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
    // uint8_t *pk, *sk;
    // pk = (uint8_t*) malloc(pqcrystals_kyber1024_PUBLICKEYBYTES * sizeof(uint8_t));
    // sk = (uint8_t*) malloc(pqcrystals_kyber1024_SECRETKEYBYTES * sizeof(uint8_t));
    
    // pqcrystals_kyber512_ref_keypair(pk, sk);

    // crypto_kem_keypair(pk, sk);

    unsigned char pk[CRYPTO_PUBLICKEYBYTES], sk[CRYPTO_SECRETKEYBYTES];
    int ret_val;

    if ( (ret_val = crypto_kem_keypair(pk, sk)) != 0) {
        printf("crypto_kem_keypair returned <%d>\n", ret_val);
    }

    printf("Terminado\n\r");

    // free(pk);
    // free(sk);
}