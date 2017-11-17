#ifndef JPCLIB_COLLECTIONS_ARRAY_H
#define JPCLIB_COLLECTIONS_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

struct Array;

struct Array *Array_new();

struct Array *Array_with_capacity(size_t capacity);

struct Array *Array_copy(const struct Array *array);

void Array_delete(struct Array *array);

bool Array_equals(const struct Array *array, const struct Array *other);

void Array_hash(const struct Array *array, struct SipHasher *hasher);

size_t Array_count(const struct Array *array);

bool Array_is_empty(const struct Array *array);

size_t Array_capacity(const struct Array *array);

void *Array_at(const struct Array *array, size_t index);

void *Array_at_unsafe(const struct Array *array, size_t index);

bool Array_insert(struct Array *array, void *object, size_t index);

bool Array_remove(struct Array *array, size_t index);

bool Array_push(struct Array *array, void *object);

bool Array_pop(struct Array *array);

void Array_clear(struct Array *array);

bool Array_reserve(struct Array *array, size_t capacity);

bool Array_reserve_exactly(struct Array *array, size_t capacity);

#endif
