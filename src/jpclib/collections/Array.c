#include "jpclib/collections/Array.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "jpclib/core/Functions.h"
#include "jpclib/core/Object.h"
#include "jpclib/math/stats.h"

static const float GrowthFactor = 1.6;

static const struct Functions ArrayFunctions = {
    .copy_function = (CopyFunction)Array_copy,
    .delete_function = (DeleteFunction)Array_delete,
    .equals_function = (EqualsFunction)Array_equals,
};

struct Array {
    const struct Functions *functions;
    void **objects;
    size_t count;
    size_t capacity;
};

static bool Array_reserve_preemptively(struct Array *array, size_t capacity);

struct Array *Array_new() {
    struct Array *array = malloc(sizeof(struct Array));
    if (!array) {
        return NULL;
    }

    array->functions = &ArrayFunctions;
    array->objects = NULL;
    array->count = 0;
    array->capacity = 0;

    return array;
}

struct Array *Array_with_capacity(size_t capacity) {
    struct Array *array = Array_new();
    if (!array) {
        return NULL;
    }

    if (!Array_reserve(array, capacity)) {
        Array_delete(array);
        return NULL;
    }

    return array;
}

struct Array *Array_copy(const struct Array *array) {
    struct Array *copy = Array_with_capacity(Array_count(array));
    if (!array) {
        return NULL;
    }

    for (size_t i = 0; i < Array_count(array); ++i) {
        void *object = Object_copy(Array_at_unsafe(array, i));
        if (!object) {
            Array_delete(copy);
            return NULL;
        }

        Array_push(copy, object);
    }

    return copy;
}

void Array_delete(struct Array *array) {
    Array_clear(array);
    free(array->objects);
    free(array);
}

bool Array_equals(const struct Array *array, const struct Array *other) {
    if (Array_count(array) != Array_count(other)) {
        return false;
    }

    for (size_t i = 0; i < Array_count(array); ++i) {
        struct Object *object1 = Array_at_unsafe(array, i);
        struct Object *object2 = Array_at_unsafe(other, i);
        if (!Object_equals(object1, object2)) {
            return false;
        }
    }

    return true;
}

size_t Array_count(const struct Array *array) {
    return array->count;
}

bool Array_is_empty(const struct Array *array) {
    return !Array_count(array);
}

size_t Array_capacity(const struct Array *array) {
    return array->capacity;
}

void *Array_at(const struct Array *array, size_t index) {
    if (index >= Array_count(array)) {
        return NULL;
    }

    return Array_at_unsafe(array, index);
}

void *Array_at_unsafe(const struct Array *array, size_t index) {
    return array->objects[index];
}

bool Array_insert(struct Array *array, void *object, size_t index) {
    if (index > Array_count(array)) {
        return false;
    }

    if (!Array_reserve_preemptively(array, Array_count(array) + 1)) {
        return false;
    }

    void **source = array->objects + index;
    void **destination = array->objects + index + 1;
    size_t size = sizeof(void *) * (Array_count(array) - index);
    memmove(destination, source, size);

    *source = object;
    ++array->count;

    return true;
}

bool Array_remove(struct Array *array, size_t index) {
    if (index >= Array_count(array)) {
        return false;
    }

    void **destination = array->objects + index;
    Object_delete(*destination);
    --array->count;

    void **source = array->objects + index + 1;
    size_t size = sizeof(void *) * (Array_count(array) - index);
    memmove(destination, source, size);

    return true;
}

bool Array_push(struct Array *array, void *object) {
    return Array_insert(array, object, Array_count(array));
}

bool Array_pop(struct Array *array) {
    return Array_remove(array, Array_count(array) - 1);
}

bool Array_clear(struct Array *array) {
    if (Array_is_empty(array)) {
        return false;
    }

    while (Array_pop(array));

    return true;
}

bool Array_reserve(struct Array *array, size_t capacity) {
    if (Array_capacity(array) >= capacity) {
        return true;
    }

    size_t size = sizeof(struct Object *) * capacity;
    void **objects = realloc(array->objects, size);
    if (!objects) {
        return false;
    }

    array->objects = objects;
    array->capacity = capacity;

    return true;
}

bool Array_reserve_preemptively(struct Array *array, size_t capacity) {
    if (Array_capacity(array) >= capacity) {
        return true;
    }

    size_t suggested = GrowthFactor * Array_capacity(array);
    size_t chosen = max(capacity, suggested);

    return Array_reserve(array, chosen);
}
