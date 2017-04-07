#ifndef JPCLIB_CORE_NUMBER_H
#define JPCLIB_CORE_NUMBER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/// Stores a value as any C scalar type.
struct Number;

/// Creates a Number initialized to the given `bool` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_bool(bool value);

/// Creates a Number initialized to the given `char` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_char(char value);

/// Creates a Number initialized to the given `unsigned char` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_unsigned_char(unsigned char value);

/// Creates a Number initialized to the given `short` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_short(short value);

/// Creates a Number initialized to the given `unsigned short` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_unsigned_short(unsigned short value);

/// Creates a Number initialized to the given `int` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_int(int value);

/// Creates a Number initialized to the given `unsigned` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_unsigned_int(unsigned int value);

/// Creates a Number initialized to the given `long` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_long(long value);

/// Creates a Number initialized to the given `unsigned long` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_unsigned_long(unsigned long value);

/// Creates a Number initialized to the given `long long` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_long_long(long long value);

/// Creates a Number initialized to the given `unsigned long long` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_unsigned_long_long(unsigned long long value);

/// Creates a Number initialized to the given `float` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_float(float value);

/// Creates a Number initialized to the given `double` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_double(double value);

/// Creates a Number initialized to the given `long double` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_long_double(long double value);

/// Creates a Number initialized to the given `int8_t` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_i8(int8_t value);

/// Creates a Number initialized to the given `uint8_t` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_u8(uint8_t value);

/// Creates a Number initialized to the given `int16_t` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_i16(int16_t value);

/// Creates a Number initialized to the given `uint16_t` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_u16(uint16_t value);

/// Creates a Number initialized to the given `int32_t` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_i32(int32_t value);

/// Creates a Number initialized to the given `uint32_t` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_u32(uint32_t value);

/// Creates a Number initialized to the given `int64_t` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_i64(int64_t value);

/// Creates a Number initialized to the given `uint64_t` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_u64(uint64_t value);

/// Creates a Number initialized to the given `size_t` value.
///
/// @param value
///     The value to initialize the Number with.
///
/// @return
///     Returns a new Number, or `NULL` if creation failed.
struct Number *Number_with_size(size_t value);

/// Deletes a Number.
///
/// @param number
///     The Number.
void Number_delete(struct Number *number);

/// Returns the Number's value expressed as a `bool`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `bool`.
bool Number_bool_value(const struct Number *number);

/// Returns the Number's value expressed as a `char`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `char`.
char Number_char_value(const struct Number *number);

/// Returns the Number's value expressed as a `unsigned char`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `unsigned char`.
unsigned char Number_unsigned_char_value(const struct Number *number);

/// Returns the Number's value expressed as a `short`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `short`.
short Number_short_value(const struct Number *number);

/// Returns the Number's value expressed as a `unsigned short`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `unsigned short`.
unsigned short Number_unsigned_short_value(const struct Number *number);

/// Returns the Number's value expressed as a `int`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `int`.
int Number_int_value(const struct Number *number);

/// Returns the Number's value expressed as a `unsigned int`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `unsigned int`.
unsigned int Number_unsigned_int_value(const struct Number *number);

/// Returns the Number's value expressed as a `long`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `long`.
long Number_long_value(const struct Number *number);

/// Returns the Number's value expressed as a `unsinged long`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `unsinged long`.
unsigned long Number_unsigned_long_value(const struct Number *number);

/// Returns the Number's value expressed as a `long long`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `long long`.
long long Number_long_long_value(const struct Number *number);

/// Returns the Number's value expressed as a `unsigned long long`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `unsigned long long`.
unsigned long long Number_unsigned_long_long_value(const struct Number *number);

/// Returns the Number's value expressed as a `float`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `float`.
float Number_float_value(const struct Number *number);

/// Returns the Number's value expressed as a `double`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `double`.
double Number_double_value(const struct Number *number);

/// Returns the Number's value expressed as a `long double`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `long double`.
long double Number_long_double_value(const struct Number *number);

/// Returns the Number's value expressed as a `int8_t`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `int8_t`.
int8_t Number_as_i8(const struct Number *number);

/// Returns the Number's value expressed as a `uint8_t`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `uint8_t`.
uint8_t Number_as_u8(const struct Number *number);

/// Returns the Number's value expressed as a `int16_t`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `int16_t`.
int16_t Number_as_i16(const struct Number *number);

/// Returns the Number's value expressed as a `uint16_t`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `uint16_t`.
uint16_t Number_as_u16(const struct Number *number);

/// Returns the Number's value expressed as a `int32_t`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `int32_t`.
int32_t Number_as_i32(const struct Number *number);

/// Returns the Number's value expressed as a `uint32_t`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `uint32_t`.
uint32_t Number_as_u32(const struct Number *number);

/// Returns the Number's value expressed as a `int64_t`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `int64_t`.
int64_t Number_as_i64(const struct Number *number);

/// Returns the Number's value expressed as a `uint64_t`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `uint64_t`.
uint64_t Number_as_u64(const struct Number *number);

/// Returns the Number's value expressed as a `size_t`.
///
/// @param number
///     The Number.
///
/// @return
///     Returns the Number's value expressed as a `size_t`.
size_t Number_as_size(const struct Number *number);

#endif
