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

#define crypto_kem_keypair NAMESPACE(crypto_kem_keypair)
#define crypto_kem_enc     NAMESPACE(crypto_kem_enc)
#define crypto_kem_dec     NAMESPACE(crypto_kem_dec)

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
    printf("Inicio con la opción %s\n\r", CRYPTO_ALGNAME);

    //Generación de claves
    unsigned char pk[CRYPTO_PUBLICKEYBYTES], sk[CRYPTO_SECRETKEYBYTES];
    // uint8_t *pk, *sk;

    //Generación de texto cifrado y secreto compartido
    uint8_t ct[CRYPTO_CIPHERTEXTBYTES];
    uint8_t ss_pub[CRYPTO_BYTES];

    //Generación de secreto compartido
    uint8_t ss_priv[CRYPTO_BYTES];

    while (true) {

        sleep_ms(10000);

        //Generación de claves
        // pk = (uint8_t*) malloc(sizeof(uint8_t) * CRYPTO_PUBLICKEYBYTES);
        // sk = (uint8_t*) malloc(sizeof(uint8_t) * CRYPTO_SECRETKEYBYTES);

        if (crypto_kem_keypair(pk, sk) != 0){
            printf("Generacion de claves fallida\n\r");
        } else {
            printf("Generacion de claves exitosa (%d bytes de clave publica y %d bytes de clave privada)\n\r", CRYPTO_PUBLICKEYBYTES, CRYPTO_SECRETKEYBYTES);
            printBstr("Clave publica = ", pk, CRYPTO_PUBLICKEYBYTES);
            printBstr("Clave privada = ", sk, CRYPTO_SECRETKEYBYTES);
        }


        //Generación de texto cifrado y secreto compartido
        if (crypto_kem_enc(ct, ss_pub, pk) != 0){
            printf("Generacion de texto cifrado y secreto compartido fallida\n\r");
        } else {
            printf("Generacion de texto cifrado y secreto compartido exitosa (%d bytes de texto cifrado y %d bytes de secreto compartido)\n\r", CRYPTO_CIPHERTEXTBYTES, CRYPTO_BYTES);
            printBstr("Texto cifrado = ", ct, CRYPTO_CIPHERTEXTBYTES);
        }


        //Generación de secreto compartido
        if (crypto_kem_dec(ss_priv, ct, sk) != 0) {
            printf("Generacion de secreto compartido fallida\n\r");
        } else {
            printf("Generacion de secreto compartido exitosa (%d bytes de secreto compartido)\n\r", CRYPTO_BYTES);
            printBstr("Secreto compartido pub  = ", ss_pub, CRYPTO_BYTES);
            printBstr("Secreto compartido priv = ", ss_priv, CRYPTO_BYTES);
        }


        //Comprobación de resultados
        if (memcmp(ss_pub, ss_priv, (unsigned int) CRYPTO_BYTES) ) {
            printf("Comprobación fallida\n\r");
        } else{
            printf("¡Comprobación superada!\n\r");
        }

        // free(pk);
        // free(sk);

    }
}