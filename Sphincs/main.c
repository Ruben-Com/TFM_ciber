#include <stdio.h>
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
    unsigned char pk[CRYPTO_PUBLICKEYBYTES], sk[CRYPTO_SECRETKEYBYTES];

    unsigned char m[] = "Esto es una prueba de la firma de mensajes utilizando Sphincs\n\r";
    unsigned char *sm, *m1;
    unsigned long long mlen = sizeof(m), smlen, mlen1;

    while (true) {


        printf("Inicio\n");
        if (crypto_sign_keypair(pk, sk)!= 0)
        {
            printf("Ha fallado\r\n");
        } else {
            printBstr("pk = ", pk, CRYPTO_PUBLICKEYBYTES);
            printBstr("sk = ", sk, CRYPTO_SECRETKEYBYTES);
        }


        m1 = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));
        sm = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));
        if (crypto_sign(sm, &smlen, m, mlen, sk) != 0)
        {
            printf("Ha fallado la firma del mensaje\r\n");
        } else {
            printf("smlen = %llu\n", smlen);
            printBstr("sm = ", sm, smlen);
        }



        if (crypto_sign_open(m1, &mlen1, sm, smlen, pk) != 0) {
            printf("Error al descifrar el mensaje\r\n");
        }

        if ( mlen != mlen1 ) {
            printf("El tamaño de los mensajes no coinciden\r\n", mlen1, mlen);
        }

        if ( memcmp(m, m1, mlen) ) {
            printf("El contenido de los mensajes no coincide\r\n");
        }

        printf("Mensaje original =\"%s\"\n\r", m);
        printf("Mensaje recuperado =\"%s\"\n\r", m1);


        free(m1);
        free(sm);
        printf("Terminado\n");
        sleep_ms(10000);
    }
}