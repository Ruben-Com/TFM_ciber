#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pico/stdlib.h"
#include "api.h"


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
    printf("Inicio con la opción %s\n\r", xstr(PARAMS));

    //Generación de claves
    unsigned char pk[CRYPTO_PUBLICKEYBYTES], sk[CRYPTO_SECRETKEYBYTES];

    //Firma de mensaje
    unsigned char m[] = "Esto es una prueba de la firma de mensajes utilizando Sphincs.";
    unsigned char *sm;
    unsigned long long mlen = sizeof(m), smlen;

    //Comprobación de la firma
    unsigned char *m1;
    unsigned long long mlen1;

    while (true) {

        //Generación de claves
        printf("Inicio\n");
        if (crypto_sign_keypair(pk, sk)!= 0){
            printf("Generacion de claves fallida\n\r");
        } else {
            printf("Generacion de claves exitosa (%d bytes de clave publica y %d bytes de clave privada)\n\r", CRYPTO_PUBLICKEYBYTES, CRYPTO_SECRETKEYBYTES);
            // printBstr("Clave publica = ", pk, CRYPTO_PUBLICKEYBYTES);
            // printBstr("Clave privada = ", sk, CRYPTO_SECRETKEYBYTES);
        }


        //Firma de mensaje
        m1 = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));
        sm = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));

        if (crypto_sign(sm, &smlen, m, mlen, sk) != 0){
            printf("Firma de mensaje fallida\n\r");
        } else {
            printf("Firma del mensaje exitosa (%llu bytes de firma)\n\r", smlen);
            // printBstr("Firma del mensaje = ", sm, smlen);
        }


        //Comprobación de la firma
        if (crypto_sign_open(m1, &mlen1, sm, smlen, pk) != 0) {
            printf("Comprobacion de la firma fallida\n\r");
        } else {
            if (mlen != mlen1) {
                printf("Longitud del mensaje original distinta a la longitud del mensaje recuperado\n\r");
            } else if (memcmp(m, m1, mlen)) {
                printf("Contenido del mensaje original distinto al contenido del mensaje recuperado\n\r");
            } else {
                printf("Comprobacion de la firma del mensaje exitosa (%llu bytes de mensaje)\n\r", mlen1);
                printf("Comprobacion de la firma del mensaje = \"%s\"\n\r", m1);
            }
        }


        //Liberación de la memoria reservada
        free(m1);
        free(sm);
        sleep_ms(10000);
    }
}