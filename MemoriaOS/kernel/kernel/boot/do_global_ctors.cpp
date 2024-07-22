#include <stddef.h>

using func_ptr = void(*)();
extern func_ptr mos_start_ctors[];
extern func_ptr mos_end_ctors;

extern "C" void mos_do_global_ctors(void){
    for (size_t i = 0; mos_start_ctors[i]!=mos_end_ctors; ++i) {
        mos_start_ctors[i]();
    }
}