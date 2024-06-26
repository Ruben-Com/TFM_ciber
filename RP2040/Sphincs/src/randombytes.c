/*
This code was taken from the SPHINCS reference implementation and is public domain.
*/

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
// #include <time.h>
#include "pico/rand.h"

#include "randombytes.h"

void randombytes(unsigned char *x, unsigned long long xlen){
    // srand(time(NULL));
    uint32_t aux = 0;
    for (int i = 0; i < xlen; i+=4){
        aux = get_rand_32();
        memcpy(x+i, &aux, min(4, xlen-1));
    }
}

// static int fd = -1;

// void randombytes(unsigned char *x, unsigned long long xlen)
// {
//     unsigned long long i;

//     if (fd == -1) {
//         for (;;) {
//             fd = open("/dev/urandom", O_RDONLY);
//             if (fd != -1) {
//                 break;
//             }
//             sleep(1);
//         }
//     }

//     while (xlen > 0) {
//         if (xlen < 1048576) {
//             i = xlen;
//         }
//         else {
//             i = 1048576;
//         }

//         i = (unsigned long long)read(fd, x, i);
//         if (i < 1) {
//             sleep(1);
//             continue;
//         }

//         x += i;
//         xlen -= i;
//     }
// }
