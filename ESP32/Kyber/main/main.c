#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "main.h"
#include "kem.h"
#include "api.h"
#include "esp_timer.h"

#include "randombytes.h"

void app_main (void)
{
    printf("Inicio con la opción %d\n\r", KYBER_K);

    // printf("Rand 1  = {46, 216, 222, 138, 243, 168, 235, 98, 147, 193, 144, 105, 109, 44, 224, 146, 06, 206, 244, 246, 240, 232, 157, 249, 172, 06, 16, 55, 142, 210, 18, 251}");
    // printf("Rand 2  = {179, 157, 148, 161, 216, 198, 30, 180, 183, 98, 150, 193, 60, 125, 68, 145, 152, 131, 43, 182, 212, 21, 155, 51, 77, 133, 52, 17, 19, 224, 249, 94}");
    // printf("Rand 3  = {9, 213, 140, 84, 62, 200, 241, 254, 53, 233, 77, 67, 53, 145, 45, 237, 67, 93, 47, 43, 166, 100, 211, 135, 174, 04, 149, 07, 205, 64, 91, 25}");

    //Generación de claves
    unsigned char *pk = (unsigned char*) malloc(CRYPTO_PUBLICKEYBYTES * sizeof(unsigned char));
    unsigned char *sk = (unsigned char*) malloc(CRYPTO_SECRETKEYBYTES * sizeof(unsigned char));

    // if (crypto_kem_keypair(pk, sk) != 0) {
    //     printf("Generacion de claves fallida\n\r");
    //     free(pk);
    //     free(sk);
    //     return;
    // } else {
    //     printf("Generacion de claves exitosa (%d bytes de clave publica y %d bytes de clave privada)\n\r", CRYPTO_PUBLICKEYBYTES, CRYPTO_SECRETKEYBYTES);
    //     printBstr("Clave publica = ", pk, CRYPTO_PUBLICKEYBYTES);
    //     printBstr("Clave privada = ", sk, CRYPTO_SECRETKEYBYTES);
    // }


    //Generación de texto cifrado y secreto compartido
    unsigned char *ct = (unsigned char*) malloc(CRYPTO_CIPHERTEXTBYTES * sizeof(unsigned char));
    unsigned char *ss_pub = (unsigned char*) malloc(CRYPTO_BYTES * sizeof(unsigned char));

    // if (crypto_kem_enc(ct, ss_pub, pk) != 0) {
    //     printf("Generacion de texto cifrado y secreto compartido fallida\n\r");
    //     free(pk);
    //     free(sk);
    //     free(ct);
    //     free(ss_pub);
    //     return;
    // } else {
    //     printf("Generacion de texto cifrado y secreto compartido exitosa (%d bytes de texto cifrado y %d bytes de secreto compartido)\n\r", CRYPTO_CIPHERTEXTBYTES, CRYPTO_BYTES);
    //     printBstr("Texto cifrado = ", ct, CRYPTO_CIPHERTEXTBYTES);
    //     // printBstr("Secreto compartido = ", ss_pub, CRYPTO_BYTES);
    // }


    //Generación de secreto compartido
    unsigned char *ss_priv = (unsigned char*) malloc(CRYPTO_BYTES * sizeof(unsigned char));

    // if (crypto_kem_dec(ss_priv, ct, sk) != 0) {
    //     printf("Generacion de secreto compartido fallida\n\r");
    //     free(pk);
    //     free(sk);
    //     free(ct);
    //     free(ss_pub);
    //     free(ss_priv);
    //     return;
    // } else {
    //     printf("Generacion de secreto compartido exitosa (%d bytes de secreto compartido)\n\r", CRYPTO_BYTES);
    //     printBstr("Secreto compartido pub  = ", ss_pub, CRYPTO_BYTES);
    //     printBstr("Secreto compartido priv = ", ss_priv, CRYPTO_BYTES);
    // }


    // //Comprobación de resultados
    // if (memcmp(ss_pub, ss_priv, (unsigned int) CRYPTO_BYTES) ) {
    //     printf("Comprobación fallida\n\r");
    // } else{
    //     printf("¡Comprobación superada!\n\r");
    // }

    printf("Gen, Enc, Dec\n\r");
    uint64_t time_ini, time_end;

    for(int c = 0; c < 1000; c++){
        time_ini = esp_timer_get_time();
        crypto_kem_keypair(pk, sk);
        time_end = esp_timer_get_time();
        printf("%llu,", time_end-time_ini);


        time_ini = esp_timer_get_time();
        crypto_kem_enc(ct, ss_pub, pk);
        time_end = esp_timer_get_time();
        printf("%llu,", time_end-time_ini);


        time_ini = esp_timer_get_time();
        crypto_kem_dec(ss_priv, ct, sk);
        time_end = esp_timer_get_time();
        printf("%llu\n\r", time_end-time_ini);
    }

    //Liberación de la memoria reservada
    free(pk);
    free(sk);

    free(ct);
    free(ss_pub);

    free(ss_priv);
}



void printBstr(char *S, unsigned char *A, unsigned long long L)
{
	unsigned long long  i;

	printf("%s", S);

	for ( i=0; i<L; i++ )
		printf("%02X", A[i]);

	if ( L == 0 )
		printf("00");

	printf("\n");
}