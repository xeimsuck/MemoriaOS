#include <stddef.h>

extern "C" void mos_do_global_dtors(void);

extern "C" void mos_fini(void){
    mos_do_global_dtors();
}