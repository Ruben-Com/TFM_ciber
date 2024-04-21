#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "sign.h"
#include "api.h"

#include <inttypes.h>
// #include "sdkconfig.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "esp_chip_info.h"
// #include "esp_flash.h"
// #include "esp_system.h"
#include "esp_random.h"

#undef __linux__
#define ESP32


void app_main (void)
{
    printf("Inicio\n\r");
    uint8_t *pk, *sk;
    pk = (uint8_t*) malloc(pqcrystals_dilithium2_PUBLICKEYBYTES * sizeof(uint8_t));
    sk = (uint8_t*) malloc(pqcrystals_dilithium2_SECRETKEYBYTES * sizeof(uint8_t));
    printf("Alocao\n\r");

    // crypto_sign_keypair(pk, sk);
    pqcrystals_dilithium2_ref_keypair(pk, sk);
    printf("Llamada\n\r");

    // printf("Direccion publica: 0x%x\n\rDireccion privada: 0x%x\n\r\n\r", pk, sk);

    // printf("Clave publica: ");
    // for (int i = 0; i < pqcrystals_dilithium2_PUBLICKEYBYTES; i++)
    //     printf("%02x", pk[i]);

    // printf("\n\r\n\rClave privada: ");
    // for (int i = 0; i < pqcrystals_dilithium2_SECRETKEYBYTES; i++)
    //     printf("%02x", sk[i]);
    // printf("\n\r");

    free(pk);
    free(sk);
}