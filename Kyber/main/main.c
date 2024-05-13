#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "main.h"
#include "kem.h"
#include "api.h"

// #include "esp_random.h"
// #include "bootloader_random.h"

void app_main (void)
{
    printf("Inicio con la opción %d\n\r", KYBER_K);

    //Generación de claves
    unsigned char *pk, *sk;
    pk = (unsigned char*) malloc(CRYPTO_PUBLICKEYBYTES * sizeof(unsigned char));
    sk = (unsigned char*) malloc(CRYPTO_SECRETKEYBYTES * sizeof(unsigned char));

    if (crypto_kem_keypair(pk, sk) != 0) {
        printf("Generacion de claves fallida\n\r");
        free(pk);
        free(sk);
        return;
    } else {
        printf("Generacion de claves exitosa (%d bytes de clave publica y %d bytes de clave privada)\n\r", CRYPTO_PUBLICKEYBYTES, CRYPTO_SECRETKEYBYTES);
        // printBstr("Clave publica = ", pk, CRYPTO_PUBLICKEYBYTES);
        // printBstr("Clave privada = ", sk, CRYPTO_SECRETKEYBYTES);
    }


    //Generación de texto cifrado y secreto compartido
    unsigned char *ct, *ss_pub;
    ct = (unsigned char*) malloc(CRYPTO_CIPHERTEXTBYTES * sizeof(unsigned char));
    ss_pub = (unsigned char*) malloc(CRYPTO_BYTES * sizeof(unsigned char));

    if (crypto_kem_enc(ct, ss_pub, pk) != 0) {
        printf("Generacion de texto cifrado y secreto compartido fallida\n\r");
        free(ct);
        free(ss_pub);
        return;
    } else {
        printf("Generacion de texto cifrado y secreto compartido exitosa (%d bytes de texto cifrado y %d bytes de secreto compartido)\n\r", CRYPTO_CIPHERTEXTBYTES, CRYPTO_BYTES);
        // printBstr("Texto cifrado = ", ct, CRYPTO_CIPHERTEXTBYTES);
        printBstr("Secreto compartido = ", ss_pub, CRYPTO_BYTES);
    }


    //Generación de secreto compartido
    unsigned char *ss_priv;
    ss_priv = (unsigned char*) malloc(CRYPTO_BYTES * sizeof(unsigned char));

    if (crypto_kem_dec(ct, ss_priv, pk) != 0) {
        printf("Generacion de secreto compartido fallida\n\r");
        free(ss_priv);
        return;
    } else {
        printf("Generacion de secreto compartido exitosa (%d bytes de secreto compartido)\n\r", CRYPTO_BYTES);
        printBstr("Secreto compartido = ", ss_priv, CRYPTO_BYTES);
    }


    //Comprobación de resultados
    if (memcmp(ss_pub, ss_priv, CRYPTO_BYTES) ) {
        printf("Comprobación fallida\n\r");
    } else{
        printf("¡Comprobación superada!\n\r");
    }


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