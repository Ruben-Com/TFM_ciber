idf_component_register(SRCS "PQCgenKAT_kem.c" "main.c" "src/kex.c" "src/kem.c" "src/indcpa.c" "src/polyvec.c" "src/poly.c" "src/cbd.c" "src/ntt.c" "src/reduce.c" "src/verify.c" "src/symmetric-shake.c" "src/symmetric-aes.c" "src/fips202.c" "src/randombytes.c"
                    INCLUDE_DIRS "include"
                    "$ENV{IDF_PATH}/components/esp_hw_support/include/" 
                    "$ENV{IDF_PATH}/components/bootloader_support/include/")