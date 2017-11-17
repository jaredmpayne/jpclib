#ifndef JPCLIB_CORE_STRING_H
#define JPCLIB_CORE_STRING_H

#include <stdbool.h>
#include <stddef.h>

struct String;

struct String *String_new();

struct String *String_with_capacity(size_t capacity);

struct String *String_copy(const struct String *string);

void String_delete(struct String *string);

bool String_equals(const struct String *string, const struct String *other);

size_t String_count(const struct String *string);

bool String_is_empty(const struct String *string);

size_t String_capacity(const struct String *string);

char *String_characters(const struct String *string);

char String_at(const struct String *string, size_t index);

char String_at_unsafe(const struct String *string, size_t index);

bool String_insert(struct String *string, char character, size_t index);

bool String_remove(struct String *string, size_t index);

bool String_push(struct String *string, char character);

bool String_pop(struct String *string);

void String_clear(struct String *string);

bool String_reserve(struct String *string, size_t capacity);

bool String_reserve_exactly(struct String *string, size_t capacity);

#endif
