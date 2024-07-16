# options
set(CMAKE_CXX_FLAGS "-ffreestanding -O2 -Wall -Wextra -Werror -fno-exceptions -fno-rtti")
set(CMAKE_C_FLAGS "-std=gnu99 -ffreestanding -O2 -Wall -Wextra")
set(CMAKE_EXE_LINKER_FLAGS "-ffreestanding -O2 -nostdlib -nostdlib++ -lgcc")

# sources
file(GLOB_RECURSE libk++_SOURCES "sources/*.cpp")

# libk++
add_library(libk++ ${libk++_SOURCES})
target_include_directories(libk++ PUBLIC "include/")