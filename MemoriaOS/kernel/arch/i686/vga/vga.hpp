#ifndef MOS_KERNEL_VGA_HPP
#define MOS_KERNEL_VGA_HPP

#ifndef _VGA_H
#define _VGA_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

static constexpr size_t VGA_WIDTH = 80;
static constexpr size_t VGA_HEIGHT = 25;

enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15,
};

static uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg){
    return bg<<4|fg;
}
static uint16_t vga_entry (unsigned char uc, uint8_t color){
    return (uint16_t) uc | (uint16_t) color << 8;
}

#endif //_VGA_H


#endif //MOS_KERNEL_VGA_HPP
