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

#include "params.h"
#include "fips202.h"
#include "polyvec.h"
#include "packing.h"

#define POLY_UNIFORM_NBLOCKS ((768 + STREAM128_BLOCKBYTES - 1)/STREAM128_BLOCKBYTES)
void uniform(poly *a, const uint8_t seed[SEEDBYTES], uint16_t nonce)
{
  unsigned int i, ctr, off;
  unsigned int buflen = POLY_UNIFORM_NBLOCKS*STREAM128_BLOCKBYTES;
  uint8_t buf[POLY_UNIFORM_NBLOCKS*STREAM128_BLOCKBYTES + 2];
  stream128_state state;

  stream128_init(&state, seed, nonce);
  stream128_squeezeblocks(buf, POLY_UNIFORM_NBLOCKS, &state);

//   ctr = rej_uniform(a->coeffs, N, buf, buflen);

//   while(ctr < N) {
//     off = buflen % 3;
//     for(i = 0; i < off; ++i)
//       buf[i] = buf[buflen - off + i];

//     stream128_squeezeblocks(buf + off, 1, &state);
//     buflen = STREAM128_BLOCKBYTES + off;
//     ctr += rej_uniform(a->coeffs + ctr, N - ctr, buf, buflen);
//   }
}

void matrix_expand(polyvecl mat[K], const uint8_t rho[SEEDBYTES]) {
  unsigned int i, j;

  for(i = 0; i < K; ++i)
    for(j = 0; j < L; ++j)
      uniform(&mat[i].vec[j], rho, (i << 8) + j);
}

int keypair(uint8_t *pk, uint8_t *sk) {
    printf("Crypto\n\r");
    uint8_t seedbuf[2*SEEDBYTES + CRHBYTES];
    // uint8_t tr[SEEDBYTES];
    const uint8_t *rho, *rhoprime, *key;
    polyvecl mat[K];
    // polyvecl s1, s1hat;
    // polyveck s2, t1, t0;

//   uint32_t esp_random(void);
//   void esp_fill_random(void *buf, size_t len);

  /* Get randomness for rho, rhoprime and key */
//   randombytes(seedbuf, SEEDBYTES);
    esp_fill_random(&seedbuf, SEEDBYTES);
    for (int i = 0; i < SEEDBYTES; i++)
        printf("%02x", seedbuf[i]);
    printf("\n\r");
    shake256(seedbuf, 2*SEEDBYTES + CRHBYTES, seedbuf, SEEDBYTES);
    rho = seedbuf;
    rhoprime = rho + SEEDBYTES;
    key = rhoprime + CRHBYTES;
    printf("Crypto 2\n\r");

    /* Expand matrix */
    // polyvec_matrix_expand(mat, rho);
    matrix_expand(mat, rho);

    /* Sample short vectors s1 and s2 */
    // polyvecl_uniform_eta(&s1, rhoprime, 0);
    // polyveck_uniform_eta(&s2, rhoprime, L);

    // /* Matrix-vector multiplication */
    // s1hat = s1;
    // polyvecl_ntt(&s1hat);
    // polyvec_matrix_pointwise_montgomery(&t1, mat, &s1hat);
    // polyveck_reduce(&t1);
    // polyveck_invntt_tomont(&t1);

    // /* Add error vector s2 */
    // polyveck_add(&t1, &t1, &s2);

    // /* Extract t1 and write public key */
    // polyveck_caddq(&t1);
    // polyveck_power2round(&t1, &t0, &t1);
    // pack_pk(pk, rho, &t1);

    // /* Compute H(rho, t1) and write secret key */
    // shake256(tr, SEEDBYTES, pk, CRYPTO_PUBLICKEYBYTES);
    // pack_sk(sk, rho, tr, key, &t0, &s1, &s2);

    return 0;
}

void app_main (void)
{
    printf("Inicio\n\r");
    uint8_t *pk, *sk;
    pk = (uint8_t*) malloc(pqcrystals_dilithium2_PUBLICKEYBYTES * sizeof(uint8_t));
    sk = (uint8_t*) malloc(pqcrystals_dilithium2_SECRETKEYBYTES * sizeof(uint8_t));
    printf("Alocao\n\r");

    keypair(pk, sk);
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