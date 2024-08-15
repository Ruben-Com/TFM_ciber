cmake_minimum_required(VERSION 3.13)

if (TARGET tinyusb_device)    
    #add_compile_options(-Wall -Wextra -pedantic -Werror -Wpedantic -Wredundant-decls -Wcast-align -Wmissing-prototypes -DPQCLEAN_NAMESPACE=PQCLEAN_MCELIECE348864_CLEAN) #QUITAMOS -O3 -std=c99

    add_compile_options(-Wall -Wextra -Wpedantic -Wredundant-decls -Wcast-align -Wmissing-prototypes -DPQCLEAN_NAMESPACE=PQCLEAN_HQC192_CLEAN)

    add_executable(hqc-192)

    target_sources(hqc-192 PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/main.c
            ${CMAKE_CURRENT_LIST_DIR}/src/code.c
            ${CMAKE_CURRENT_LIST_DIR}/src/fft.c
            ${CMAKE_CURRENT_LIST_DIR}/src/gf.c
            ${CMAKE_CURRENT_LIST_DIR}/src/gf2x.c
            ${CMAKE_CURRENT_LIST_DIR}/src/hqc.c
            ${CMAKE_CURRENT_LIST_DIR}/src/kem.c
            ${CMAKE_CURRENT_LIST_DIR}/src/parsing.c
            ${CMAKE_CURRENT_LIST_DIR}/src/reed_muller.c
            ${CMAKE_CURRENT_LIST_DIR}/src/reed_solomon.c
            ${CMAKE_CURRENT_LIST_DIR}/src/shake_ds.c
            ${CMAKE_CURRENT_LIST_DIR}/src/shake_prng.c
            ${CMAKE_CURRENT_LIST_DIR}/src/vector.c

            ${CMAKE_CURRENT_LIST_DIR}/src/randombytes.c
            ${CMAKE_CURRENT_LIST_DIR}/src/fips202.c
            )
    
    target_include_directories(hqc-192 PUBLIC
                    ${CMAKE_CURRENT_LIST_DIR}/include)

    # pull in common dependencies
    target_link_libraries(hqc-192 pico_stdlib pico_rand)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(hqc-192 1)
    pico_enable_stdio_uart(hqc-192 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(hqc-192)

    # add url via pico_set_program_url
    example_auto_set_url(hqc-192)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building hqc-192 because TinyUSB submodule is not initialized in the SDK")
endif()
