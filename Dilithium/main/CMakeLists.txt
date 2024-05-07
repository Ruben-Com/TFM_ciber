idf_component_register(SRCS "rng.c" "PQCgenKAT_sign.c" "main.c" "sign.c" "packing.c" "polyvec.c" "poly.c" "ntt.c" "reduce.c" "rounding.c" "symmetric-shake.c" "symmetric-aes.c" "fips202.c" "aes256ctr.c" "randombytes.c"
                    INCLUDE_DIRS "$ENV{IDF_PATH}/components/esp_hw_support/include/" 
                    "$ENV{IDF_PATH}/components/bootloader_support/include/")