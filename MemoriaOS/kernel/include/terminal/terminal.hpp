#ifndef MOS_KERNEL_TERMINAL_HPP
#define MOS_KERNEL_TERMINAL_HPP

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string/strlen.hpp>

class terminal {
public:
    terminal();
    void init();
    void write(const char* str, size_t len);
    void write(const char* str);
    void set_color(uint8_t color);
    uint8_t get_color() const;
    void put_char(char c);
    void clear(char sym = '\0');
private:
    void put_entry_at(char c, uint8_t color, size_t x, size_t y);

private:
    size_t terminal_row = 0;
    size_t terminal_column = 0;
    uint8_t terminal_color = 0;
    uint16_t* terminal_buffer = nullptr;
};

extern terminal tty;

#endif //MOS_KERNEL_TERMINAL_HPP
