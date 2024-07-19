# options
set(CMAKE_CXX_FLAGS "-ffreestanding -O2 -Wall -fno-exceptions -fno-rtti")
set(CMAKE_C_FLAGS "-std=gnu99 -ffreestanding -O2 -Wall -Wextra")
set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_CURRENT_LIST_DIR}/${ARCH_DIR}/boot/link.ld -ffreestanding -O2 -nostdlib -nostdlib++ -lgcc")

# Sources
file(GLOB_RECURSE ARCH_SOURCES "${ARCH_DIR}/*.cpp" "${ARCH_DIR}/*.s")
file(GLOB_RECURSE KERNEL_SOURCES "kernel/*.cpp" )

# MemoriaOS
add_executable(MemoriaOS ${ARCH_SOURCES} ${KERNEL_SOURCES})
target_link_libraries(MemoriaOS libk++)
target_include_directories(MemoriaOS PUBLIC "include/")