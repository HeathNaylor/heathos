#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "drivers/vga.cpp"
 
/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
 
/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

size_t strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}
 
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
 
size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

using namespace kernel::drivers;
 
void terminal_initialize(void) 
{
	terminal_row = 0;
	terminal_column = 0;

    terminal_color = vga::api::entry_color(
            vga::color::WHITE,
            vga::color::BLACK
            );

	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga::api::entry(' ', terminal_color);
		}
	}
}
 
void terminal_setcolor(uint8_t color) 
{
	terminal_color = color;
}
 
void terminal_put_entry_at(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga::api::entry(c, color);
}
 
void terminal_put_char(char c) 
{
    // Check for new lines
    if(c == '\n') {
        ++terminal_row;
        terminal_column = 0;
        return;
    }

	terminal_put_entry_at(c, terminal_color, terminal_column, terminal_row);

	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
}
 
void terminal_write(const char* data, size_t size) 
{
	for (size_t i = 0; i < size; i++)
		terminal_put_char(data[i]);
}
 
void terminal_write_string(const char* data) 
{
	terminal_write(data, strlen(data));
}
 
extern "C" void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();
 
	/* Newline support is left as an exercise. */
	terminal_write_string("Welcome to HeathOS Kernel\n\nTime for a change.\n");
	terminal_write_string(".");
}
