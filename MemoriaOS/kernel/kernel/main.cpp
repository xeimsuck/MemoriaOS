#include <stddef.h>
#include <terminal/terminal.hpp>

#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
#error "This terminal needs to be compiled with a ix86-elf compiler"
#endif

#if __STDC_HOSTED__
#error "This kernel needs to be compiled in freestanding implementation"
#endif

extern "C" void main(){
    tty.write("Welcome to MemoriaOS\n");
}