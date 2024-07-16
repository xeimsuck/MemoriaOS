cmake_minimum_required(VERSION 3.28)
project(MemoriaOS VERSION 0.1 DESCRIPTION "Operatin System" LANGUAGES CXX C ASM)

set(ARCH "i686")
set(SYSDIR "$ENV{HOME}/MemoriaOS/sysroot")

set(CMAKE_CXX_STANDARD 23)

if (ARCH STREQUAL "i686")
    # arch dir
    set(ARCH_DIR "arch/i686")
    # compilers
    set(CMAKE_CXX_COMPILER "i686-elf-g++")
    set(CMAKE_C_COMPILER "i686-elf-gcc")
    set(CMAKE_ASM_COMPILER "i686-elf-as")
else ()
    message(FATAL_ERROR "Unknown architecture ${ARCH}")
endif ()

add_subdirectory("MemoriaOS/libc" libc)
add_subdirectory("MemoriaOS/libk++" libk++)
add_subdirectory("MemoriaOS/kernel" kernel)