#include "jpclib/core/Number.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "jpclib/core/Functions.h"

static const struct Functions NumberFunctions = {
    .delete_function = (DeleteFunction)Number_delete,
};

struct Number {
    const struct Functions *functions;
    uint8_t value[16];
};

struct Number *Number_with_value(const void *value, size_t size) {
    struct Number *number = malloc(sizeof(struct Number));
    if (!number) {
        return NULL;
    }

    number->functions = &NumberFunctions;
    memcpy(number->value, value, size);

    return number;
}

struct Number *Number_with_bool(bool value) {
    return Number_with_value(&value, sizeof(bool));
}

struct Number *Number_with_char(char value) {
    return Number_with_value(&value, sizeof(char));
}

struct Number *Number_with_unsigned_char(unsigned char value) {
    return Number_with_value(&value, sizeof(unsigned char));
}

struct Number *Number_with_short(short value) {
    return Number_with_value(&value, sizeof(short));
}

struct Number *Number_with_unsigned_short(unsigned short value) {
    return Number_with_value(&value, sizeof(unsigned short));
}

struct Number *Number_with_int(int value) {
    return Number_with_value(&value, sizeof(int));
}

struct Number *Number_with_unsigned_int(unsigned int value) {
    return Number_with_value(&value, sizeof(unsigned int));
}

struct Number *Number_with_long(long value) {
    return Number_with_value(&value, sizeof(long));
}

struct Number *Number_with_unsigned_long(unsigned long value) {
    return Number_with_value(&value, sizeof(unsigned long));
}

struct Number *Number_with_long_long(long long value) {
    return Number_with_value(&value, sizeof(long long));
}

struct Number *Number_with_unsigned_long_long(unsigned long long value) {
    return Number_with_value(&value, sizeof(unsigned long long));
}

struct Number *Number_with_float(float value) {
    return Number_with_value(&value, sizeof(float));
}

struct Number *Number_with_double(double value) {
    return Number_with_value(&value, sizeof(double));
}

struct Number *Number_with_long_double(long double value) {
    return Number_with_value(&value, sizeof(long double));
}

struct Number *Number_with_i8(int8_t value) {
    return Number_with_value(&value, sizeof(int8_t));
}

struct Number *Number_with_u8(uint8_t value) {
    return Number_with_value(&value, sizeof(uint8_t));
}

struct Number *Number_with_i16(int16_t value) {
    return Number_with_value(&value, sizeof(int16_t));
}

struct Number *Number_with_u16(uint16_t value) {
    return Number_with_value(&value, sizeof(uint16_t));
}

struct Number *Number_with_i32(int32_t value) {
    return Number_with_value(&value, sizeof(int32_t));
}

struct Number *Number_with_u32(uint32_t value) {
    return Number_with_value(&value, sizeof(uint32_t));
}

struct Number *Number_with_i64(int64_t value) {
    return Number_with_value(&value, sizeof(int64_t));
}

struct Number *Number_with_u64(uint64_t value) {
    return Number_with_value(&value, sizeof(uint64_t));
}

struct Number *Number_with_size(size_t value) {
    return Number_with_value(&value, sizeof(size_t));
}

void Number_delete(struct Number *number) {
    free(number);
}

uint64_t Number_hash(struct Number *number) {
    return Number_as_u64(number);
}

bool Number_bool_value(const struct Number *number) {
    return *(bool *)number->value;
}

char Number_char_value(const struct Number *number) {
    return *(char *)number->value;
}

unsigned char Number_unsigned_char_value(const struct Number *number) {
    return *(unsigned char *)number->value;
}

short Number_short_value(const struct Number *number) {
    return *(short *)number->value;
}

unsigned short Number_unsigned_short_value(const struct Number *number) {
    return *(unsigned short *)number->value;
}

int Number_int_value(const struct Number *number) {
    return *(int *)number->value;
}

unsigned int Number_unsigned_int_value(const struct Number *number) {
    return *(unsigned int *)number->value;
}

long Number_long_value(const struct Number *number) {
    return *(long *)number->value;
}

unsigned long Number_unsigned_long_value(const struct Number *number) {
    return *(unsigned long *)number->value;
}

long long Number_long_long_value(const struct Number *number) {
    return *(long long *)number->value;
}

unsigned long long Number_unsigned_long_long_value(const struct Number *number) {
    return *(unsigned long long *)number->value;
}

float Number_float_value(const struct Number *number) {
    return *(float *)number->value;
}

double Number_double_value(const struct Number *number) {
    return *(double *)number->value;
}

long double Number_long_double_value(const struct Number *number) {
    return *(long double *)number->value;
}

int8_t Number_as_i8(const struct Number *number) {
    return *(int8_t *)number->value;
}

uint8_t Number_as_u8(const struct Number *number) {
    return *(uint8_t *)number->value;
}

int16_t Number_as_i16(const struct Number *number) {
    return *(int16_t *)number->value;
}

uint16_t Number_as_u16(const struct Number *number) {
    return *(uint16_t *)number->value;
}

int32_t Number_as_i32(const struct Number *number) {
    return *(int32_t *)number->value;
}

uint32_t Number_as_u32(const struct Number *number) {
    return *(uint32_t *)number->value;
}

int64_t Number_as_i64(const struct Number *number) {
    return *(int64_t *)number->value;
}

uint64_t Number_as_u64(const struct Number *number) {
    return *(uint64_t *)number->value;
}

size_t Number_as_size(const struct Number *number) {
    return *(size_t *)number->value;
}
