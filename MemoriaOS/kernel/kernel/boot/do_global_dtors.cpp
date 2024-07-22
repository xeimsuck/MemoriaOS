#include <stddef.h>

using func_ptr = void(*)();
extern func_ptr mos_start_dtors[];
extern func_ptr mos_end_dtors;

extern "C" void mos_do_global_dtors(void){
    for (size_t i = 0; mos_start_dtors[i]!=mos_end_dtors; ++i) {
        mos_start_dtors[i]();
    }
}