#ifndef JPCLIB_MATH_BYTES_H
#define JPCLIB_MATH_BYTES_H

#include <stdint.h>

/// Rotates bytes left by a given number of bits.
///
/// @param x
///     The bytes to be rotated left.
/// @param y
///     The number of bits to be rotated left by.
///
/// @return
///     The bytes rotated left by the given number of bits.
uint64_t rotate_left(uint64_t x, uint64_t y);

/// Rotates bytes right by a given number of bits.
///
/// @param x
///     The bytes to be rotated right.
/// @param y
///     The number of bits to be rotated right by.
///
/// @return
///     The bytes rotated right by the given number of bits.
uint64_t rotate_right(uint64_t x, uint64_t y);

#endif
