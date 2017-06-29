#include "jpclib/math/bytes.h"

#include <stdint.h>

uint64_t rotate_left(uint64_t x, uint64_t y) {
    return (x << y) | (x >> (64 - y));
}

uint64_t rotate_right(uint64_t x, uint64_t y) {
    return (x >> y) | (x << (64 - y));
}
