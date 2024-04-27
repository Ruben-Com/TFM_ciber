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
#include "bootloader_random.h"
#include <stddef.h>
#include <stdint.h>

#undef __linux__
#define ESP32

#define ROL2(a, offset) ((a << offset) ^ (a >> (64-offset)))


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

    // uint64_t shift, shift1=(uint64_t)0x0000000000000081ULL, shift2=0x1;
    // esp_fill_random(&shift, sizeof(uint64_t));
    // printf("Value: %llu\tShift: %llu\tShift back: %llu\tShift largo: %llu\n\r",
    //         shift, shift >> 32, (shift << 32) >> 32, shift << 40);
    // printf("Value: %llu\tShift: %llu\tShift back: %llu\tShift largo: %llu\n\r",
    //         shift1, shift1 >> 32, (shift1 << 32) >> 32, shift1 << 40);
    // printf("Value: %llu\tShift: %llu\tShift back: %llu\tShift largo: %llu\n\r",
    //         shift2, shift2 >> 32, (shift2 << 32) >> 32, shift2 << 40);

    // uint64_t aux, aux1=(uint64_t)0x8000000080008081ULL, aux2, aux3;
    // printf("Dir aux : %p\t Val aux : %lld\n\r", &aux, aux);
    // printf("Dir aux1: %p\t Val aux1: %lld\n\r", &aux1, aux1);
    // printf("Dir aux2: %p\t Val aux2: %lld\n\r\n\r", &aux2, aux2);
    // printf("Dir aux3: %p\t Val aux3: %lld\n\r\n\r", &aux3, aux3);

    // for(int i = 0; i<10; i++){
    //     esp_fill_random(&aux, sizeof(uint64_t));
    //     bootloader_fill_random(&aux3, sizeof(uint64_t));
    //     aux1 ^= aux;
    //     aux2 = ROL2(aux1, 43);

    //     printf("Dir aux : %p\t Val aux : %lld\n\r", &aux, aux);
    //     printf("Dir aux1: %p\t Val aux1: %lld\n\r", &aux1, aux1);
    //     printf("Dir aux2: %p\t Val aux2: %lld\n\r", &aux2, aux2);
    //     printf("Dir aux3: %p\t Val aux3: %lld\n\r", &aux3, aux3);
    // }


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