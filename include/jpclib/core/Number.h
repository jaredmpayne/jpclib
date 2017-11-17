#ifndef JPCLIB_CORE_NUMBER_H
#define JPCLIB_CORE_NUMBER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct Number;

struct Number *Number_with_bool(bool value);

struct Number *Number_with_char(char value);

struct Number *Number_with_unsigned_char(unsigned char value);

struct Number *Number_with_short(short value);

struct Number *Number_with_unsigned_short(unsigned short value);

struct Number *Number_with_int(int value);

struct Number *Number_with_unsigned_int(unsigned int value);

struct Number *Number_with_long(long value);

struct Number *Number_with_unsigned_long(unsigned long value);

struct Number *Number_with_long_long(long long value);

struct Number *Number_with_unsigned_long_long(unsigned long long value);

struct Number *Number_with_float(float value);

struct Number *Number_with_double(double value);

struct Number *Number_with_long_double(long double value);

struct Number *Number_with_i8(int8_t value);

struct Number *Number_with_u8(uint8_t value);

struct Number *Number_with_i16(int16_t value);

struct Number *Number_with_u16(uint16_t value);

struct Number *Number_with_i32(int32_t value);

struct Number *Number_with_u32(uint32_t value);

struct Number *Number_with_i64(int64_t value);

struct Number *Number_with_u64(uint64_t value);

struct Number *Number_with_size(size_t value);

void Number_delete(struct Number *number);

bool Number_bool_value(const struct Number *number);

char Number_char_value(const struct Number *number);

unsigned char Number_unsigned_char_value(const struct Number *number);

short Number_short_value(const struct Number *number);

unsigned short Number_unsigned_short_value(const struct Number *number);

int Number_int_value(const struct Number *number);

unsigned int Number_unsigned_int_value(const struct Number *number);

long Number_long_value(const struct Number *number);

unsigned long Number_unsigned_long_value(const struct Number *number);

long long Number_long_long_value(const struct Number *number);

unsigned long long Number_unsigned_long_long_value(const struct Number *number);

float Number_float_value(const struct Number *number);

double Number_double_value(const struct Number *number);

long double Number_long_double_value(const struct Number *number);

int8_t Number_as_i8(const struct Number *number);

uint8_t Number_as_u8(const struct Number *number);

int16_t Number_as_i16(const struct Number *number);

uint16_t Number_as_u16(const struct Number *number);

int32_t Number_as_i32(const struct Number *number);

uint32_t Number_as_u32(const struct Number *number);

int64_t Number_as_i64(const struct Number *number);

uint64_t Number_as_u64(const struct Number *number);

size_t Number_as_size(const struct Number *number);

#endif
