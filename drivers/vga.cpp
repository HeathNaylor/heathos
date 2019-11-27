#include "vga.h"

/* Video Graphics Array Driver
 *
 * This driver provides a programming interface to control
 * and manage your VGA display
 */

namespace kernel::drivers::vga {
    /* Hardware text mode color constants. */
    inline uint8_t api::entry_color(enum color fg, enum color bg) {
        return fg | bg << 4;
    }

    inline uint16_t api::entry(unsigned char uc, uint8_t color) 
    {
        return (uint16_t) uc | (uint16_t) color << 8;
    }
}
