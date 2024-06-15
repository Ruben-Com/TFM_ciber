#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "pico/stdlib.h"
#include "api.h"
#include "randombytes.h"
#include "main.h"

// https://stackoverflow.com/a/1489985/1711232
#define PASTER(x, y) x##_##y
#define EVALUATOR(x, y) PASTER(x, y)
#define NAMESPACE(fun) EVALUATOR(PQCLEAN_NAMESPACE, fun)

#define CRYPTO_BYTES           NAMESPACE(CRYPTO_BYTES)
#define CRYPTO_PUBLICKEYBYTES  NAMESPACE(CRYPTO_PUBLICKEYBYTES)
#define CRYPTO_SECRETKEYBYTES  NAMESPACE(CRYPTO_SECRETKEYBYTES)
#define CRYPTO_CIPHERTEXTBYTES NAMESPACE(CRYPTO_CIPHERTEXTBYTES)
#define CRYPTO_ALGNAME         NAMESPACE(CRYPTO_ALGNAME)

// #define crypto_kem_keypair NAMESPACE(crypto_kem_keypair)
// #define crypto_kem_enc     NAMESPACE(crypto_kem_enc)
// #define crypto_kem_dec     NAMESPACE(crypto_kem_dec)

void
printBstr(char *S, unsigned char *A, unsigned long long L)
{
	unsigned long long  i;

	printf("%s", S);

	for ( i=0; i<L; i++ )
		printf("%02X", A[i]);

	if ( L == 0 )
		printf("00");

	printf("\n");
}

int main() {
    stdio_init_all();
    printf("Inicio\n\r");

    //Generación de claves
    //unsigned char pk[CRYPTO_PUBLICKEYBYTES], sk[CRYPTO_SECRETKEYBYTES];
    uint8_t *pk, *sk;

    while (true) {

        sleep_ms(30000);

        //Generación de claves
        printf("Inicio\n");

        pk = (uint8_t*) malloc(sizeof(uint8_t) * CRYPTO_PUBLICKEYBYTES);
        sk = (uint8_t*) malloc(sizeof(uint8_t) * CRYPTO_SECRETKEYBYTES);

        if (PQCLEAN_MCELIECE348864_CLEAN_crypto_kem_keypair(pk, sk)!= 0){
            printf("Generacion de claves fallida\n\r");
        } else {
            printf("Generacion de claves exitosa (%d bytes de clave publica y %d bytes de clave privada)\n\r", CRYPTO_PUBLICKEYBYTES, CRYPTO_SECRETKEYBYTES);
            // printBstr("Clave publica = ", pk, CRYPTO_PUBLICKEYBYTES);
            // printBstr("Clave privada = ", sk, CRYPTO_SECRETKEYBYTES);
        }

        free(pk);
        free(sk);

    }
}