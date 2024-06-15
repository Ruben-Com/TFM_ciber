#ifndef PQCLEAN_RANDOMBYTES_H
#define PQCLEAN_RANDOMBYTES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "main.h"

#ifdef _WIN32
/* Load size_t on windows */
#include <crtdefs.h>
#else
#ifdef __linux__
#include <unistd.h>
#endif /* __linux__ */
#endif /* _WIN32 */

#ifdef RP2040

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })
     
#endif

/*
 * Write `n` bytes of high quality random bytes to `buf`
 */
#define randombytes     PQCLEAN_randombytes
int randombytes(uint8_t *output, size_t n);

#ifdef __cplusplus
}
#endif

#endif /* PQCLEAN_RANDOMBYTES_H */
