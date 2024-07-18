#include <string/memcpy.hpp>

void* memcpy(void* __restrict dest, const void* __restrict src, const size_t count){
    auto cdest = static_cast<unsigned char*>(dest);
    auto csrs = static_cast<const unsigned char*>(src);
    for(size_t i = 0; i < count; ++i) cdest[i] = csrs[i];
    return dest;
}