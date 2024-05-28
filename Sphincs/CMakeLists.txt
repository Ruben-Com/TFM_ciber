cmake_minimum_required(VERSION 3.13)

if (TARGET tinyusb_device)
    set(PARAMS "sphincs-haraka-128f")
    set(THASH "robust")
    
    add_compile_options(-Wall -Wextra -Wpedantic -Wconversion -Wmissing-prototypes -DPARAMS=sphincs-haraka-128f) #QUITAMOS -O3 -std=c99

    add_executable(sphincs)

    target_sources(sphincs PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/main.c
            ${CMAKE_CURRENT_LIST_DIR}/src/address.c
            ${CMAKE_CURRENT_LIST_DIR}/src/randombytes.c
            ${CMAKE_CURRENT_LIST_DIR}/src/merkle.c
            ${CMAKE_CURRENT_LIST_DIR}/src/wots.c
            ${CMAKE_CURRENT_LIST_DIR}/src/wotsx1.c
            ${CMAKE_CURRENT_LIST_DIR}/src/utils.c
            ${CMAKE_CURRENT_LIST_DIR}/src/utilsx1.c
            ${CMAKE_CURRENT_LIST_DIR}/src/fors.c
            ${CMAKE_CURRENT_LIST_DIR}/src/sign.c
            ${CMAKE_CURRENT_LIST_DIR}/src/haraka.c
            ${CMAKE_CURRENT_LIST_DIR}/src/hash_haraka.c
            ${CMAKE_CURRENT_LIST_DIR}/src/thash_haraka_robust.c
            )
    
    target_include_directories(sphincs PUBLIC
                    ${CMAKE_CURRENT_LIST_DIR}/include
                    ${CMAKE_CURRENT_LIST_DIR}/include/params)

    # pull in common dependencies
    target_link_libraries(sphincs pico_stdlib pico_rand)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(sphincs 1)
    pico_enable_stdio_uart(sphincs 0)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(sphincs)

    # add url via pico_set_program_url
    example_auto_set_url(sphincs)
elseif(PICO_ON_DEVICE)
    message(WARNING "not building sphincs because TinyUSB submodule is not initialized in the SDK")
endif()
