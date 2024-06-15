cmake_minimum_required(VERSION 3.13)

if (TARGET tinyusb_device)
    set(PARAMS "sphincs-haraka-128f")
    set(THASH "robust")
    
    #add_compile_options(-Wall -Wextra -pedantic -Werror -Wpedantic -Wredundant-decls -Wcast-align -Wmissing-prototypes -DPQCLEAN_NAMESPACE=PQCLEAN_MCELIECE348864_CLEAN) #QUITAMOS -O3 -std=c99

    add_compile_options(-Wall -Wextra -Wpedantic -Wredundant-decls -Wcast-align -Wmissing-prototypes -DPQCLEAN_NAMESPACE=PQCLEAN_MCELIECE348864_CLEAN)

    add_executable(mceliece348864)

    target_sources(mceliece348864 PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/main.c
            ${CMAKE_CURRENT_LIST_DIR}/src/aes256ctr.c
            ${CMAKE_CURRENT_LIST_DIR}/src/benes.c
            ${CMAKE_CURRENT_LIST_DIR}/src/bm.c
            ${CMAKE_CURRENT_LIST_DIR}/src/controlbits.c
            ${CMAKE_CURRENT_LIST_DIR}/src/crypto_int16.c
            ${CMAKE_CURRENT_LIST_DIR}/src/crypto_int32.c
            ${CMAKE_CURRENT_LIST_DIR}/src/crypto_uint16.c
            ${CMAKE_CURRENT_LIST_DIR}/src/crypto_uint32.c
            ${CMAKE_CURRENT_LIST_DIR}/src/crypto_uint64.c
            ${CMAKE_CURRENT_LIST_DIR}/src/decrypt.c
            ${CMAKE_CURRENT_LIST_DIR}/src/encrypt.c
            ${CMAKE_CURRENT_LIST_DIR}/src/gf.c
            ${CMAKE_CURRENT_LIST_DIR}/src/operations.c
            ${CMAKE_CURRENT_LIST_DIR}/src/pk_gen.c
            ${CMAKE_CURRENT_LIST_DIR}/src/root.c
            ${CMAKE_CURRENT_LIST_DIR}/src/sk_gen.c
            ${CMAKE_CURRENT_LIST_DIR}/src/synd.c
            ${CMAKE_CURRENT_LIST_DIR}/src/transpose.c
            ${CMAKE_CURRENT_LIST_DIR}/src/util.c
            ${CMAKE_CURRENT_LIST_DIR}/src/randombytes.c
            ${CMAKE_CURRENT_LIST_DIR}/src/fips202.c
            )
    
    target_include_directories(mceliece348864 PUBLIC
                    ${CMAKE_CURRENT_LIST_DIR}/include)

    # pull in common dependencies
    target_link_libraries(mceliece348864 pico_stdlib pico_rand)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(mceliece348864 1)
    pico_enable_stdio_uart(mceliece348864 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(mceliece348864)

    # add url via pico_set_program_url
    example_auto_set_url(mceliece348864)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building mceliece348864 because TinyUSB submodule is not initialized in the SDK")
endif()
