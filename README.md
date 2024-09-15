# TFM_ciber

## ESP32
Los proyectos de este dispositivo están configurados como proyectos de la extensión de Espressif para VSCode.

Para ejecutarlo, es necesaria la instalación de la herramienta ESP-idf de Espressif y el uso de la extensión VSCode.
En esta extensión se deberá cargar el software mediante UART o, si se utiliza ESP-Prog, mediante JTAG.
Si se hace uso de ESP-Prog, también se debe instalar y activar OpenOCD.


## RP2040
Los proyectos para este dispositivo están diseñados como ejemplos de la herramienta Pico-SDK.

Para ejecutarlo, es necesario clonar el repositorio con dicha herramienta, incluir estos proyectos en el directorio de ejemplos y añadir dichos proyectos en el archivo CMakeLists.txt.
A continuación, hay que establecer la variable de entorno PICO_SDK_PATH al repositorio recién clonado, crear un directorio _build_ y ejecutar
    cd build && cmake ..
    cd project_name && make -j4
Una vez está creado el archivo .elf2, se debe conectar el dispositivo al computador y cargar este archivo.
