#include <stdio.h>
#include <string.h>

#include "sign.h"
#include "api.h"
#include "main.h"

void app_main(void)
{
    printf("Inicio con la opción %d\n\r", DILITHIUM_MODE);

    //Generación de claves
    uint8_t *pk = (uint8_t*) malloc(CRYPTO_PUBLICKEYBYTES * sizeof(uint8_t));
    uint8_t *sk = (uint8_t*) malloc(CRYPTO_SECRETKEYBYTES * sizeof(uint8_t));

    if (crypto_sign_keypair(pk, sk) != 0) {
        printf("Generacion de claves fallida\n\r");
        free(pk);
        free(sk);
        return;
    } else {
        printf("Generacion de claves exitosa (%d bytes de clave publica y %d bytes de clave privada)\n\r", CRYPTO_PUBLICKEYBYTES, CRYPTO_SECRETKEYBYTES);
        // printBstr("Clave publica = ", pk, CRYPTO_PUBLICKEYBYTES);
        // printBstr("Clave privada = ", sk, CRYPTO_SECRETKEYBYTES);
    }


    //Firma de mensaje
    uint8_t m[] = "Esto es una prueba de la firma de mensajes utilizando Dilithium.";
    size_t mlen = sizeof(m), smlen;
    uint8_t *sm = (uint8_t *)calloc(mlen+CRYPTO_BYTES, sizeof(uint8_t));

    if (crypto_sign(sm, &smlen, m, mlen, sk) != 0) {
        printf("Firma de mensaje fallida\n\r");
        free(pk);
        free(sk);
        free(sm);
        return;
    } else {
        printf("Firma del mensaje exitosa (%d bytes de firma)\n\r", mlen+CRYPTO_BYTES);
        // printBstr("Firma del mensaje = ", sm, mlen+CRYPTO_BYTES);
    }


    //Comprobación de la firma
    size_t mlen1;
    uint8_t *m1 = (uint8_t *)calloc(mlen+CRYPTO_BYTES, sizeof(uint8_t));

    if (crypto_sign_open(m1, &mlen1, sm, smlen, pk) != 0) {
        printf("Comprobacion de la firma fallida\n\r");
        free(pk);
        free(sk);
        free(sm);
        free(m1);
        return;
    } else {
        if (mlen != mlen1) {
            printf("Longitud del mensaje original distinta a la longitud del mensaje recuperado\n\r");
            return;
        } else if (memcmp(m, m1, mlen)) {
            printf("Contenido del mensaje original distinto al contenido del mensaje recuperado\n\r");
            return;
        } else {
            printf("Comprobacion de la firma del mensaje exitosa (%d bytes de mensaje)\n\r", mlen1);
            printf("Comprobacion de la firma del mensaje = \"%s\"\n\r", m1);
        }
    }


    //Liberación de la memoria reservada
    free(pk);
    free(sk);

    free(m1);
    
    free(sm);
}


void
printBstr(char *s, unsigned char *a, unsigned long long l)
{
	unsigned long long  i;

	printf("%s", s);

	for ( i=0; i<l; i++ )
		printf("%02X", a[i]);

	if ( l == 0 )
		printf("00");

	printf("\n");
}