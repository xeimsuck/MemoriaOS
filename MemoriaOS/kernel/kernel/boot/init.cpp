#include <stddef.h>

extern "C" void mos_do_global_ctors(void);

extern "C" void mos_init(void){
    mos_do_global_ctors();
}