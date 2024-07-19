#include <terminal/terminal.hpp>
#include "../vga/vga.hpp"

terminal::terminal(){
    init();
    write("terminal::terminal\n");
}

void terminal::init(){
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    terminal_buffer = (uint16_t*)0xB8000;
    clear();
}

void terminal::set_color(uint8_t color){
    terminal_color = color;
}

uint8_t terminal::get_color() const {
    return terminal_color;
}

void terminal::put_entry_at(char c, uint8_t color, size_t x, size_t y){
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, color);
}

void terminal::put_char(char c){
    if(c=='\n'){
        if(++terminal_row==VGA_HEIGHT) terminal_row = 0;
        terminal_column = 0;
        return;
    }

    put_entry_at(c, terminal_color, terminal_column, terminal_row);
    if(++terminal_column==VGA_WIDTH) {
        terminal_column = 0;
        if(++terminal_row==VGA_HEIGHT) terminal_row = 0;
    }
}

void terminal::write(const char* str, size_t len){
    for(size_t i = 0; i < len; ++i) put_char(str[i]);
}

void terminal::write(const char* str){
    write(str, strlen(str));
}

void terminal::clear(const char sym){
    terminal_row = 0;
    terminal_column = 0;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(sym, terminal_color);
        }
    }
}

terminal tty;