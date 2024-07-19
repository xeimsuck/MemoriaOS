#include <stddef.h>
#include <terminal/terminal.hpp>

using func_ptr = void(*)();
extern func_ptr start_ctors[];
extern func_ptr end_ctors;

extern "C" void __do_ctors(void){
    tty.init();
    tty.write("start do_ctors\n");
    start_ctors[0]();
    tty.write("end do_ctors\n");
}