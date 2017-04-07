#include "jpclib/collections/Array.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "jpclib/core/Functions.h"
#include "jpclib/core/Object.h"
#include "jpclib/math/stats.h"

static const float ArrayGrowthFactor = 1.6;

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

struct Array *Array_new() {
    return Array_with_capacity(0);
}

struct Array *Array_with_capacity(size_t capacity) {
    // Try to allocate a new Array.
    struct Array *array = malloc(sizeof(struct Array));
    if (!array) {
        return NULL;
    }

    // Initialize the data members.
    array->functions = &ArrayFunctions;
    array->objects = NULL;
    array->count = 0;
    array->capacity = 0;

    // Try to reserve exactly the requested capacity.
    if (!Array_reserve_exactly(array, capacity)) {
        Array_delete(array);
        return NULL;
    }

    return array;
}

struct Array *Array_copy(const struct Array *array) {
    // Try to create a new Array with capacity for the original's Objects.
    struct Array *copy = Array_with_capacity(Array_count(array));
    if (!array) {
        return NULL;
    }

    // Try to push a copy of each of the original's Objects to the new Array.
    for (size_t i = 0; i < Array_count(array); ++i) {
        void *object = Object_copy(Array_at_unsafe(array, i));
        if (!object) {
            Array_delete(copy);
            return NULL;
        }

        // This push can't fail. All allocations have already happened.
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
    // Fail if the Array counts are not equal.
    if (Array_count(array) != Array_count(other)) {
        return false;
    }

    // Fail if any Objects at equal indices are not equal.
    for (size_t i = 0; i < Array_count(array); ++i) {
        struct Object *object1 = Array_at_unsafe(array, i);
        struct Object *object2 = Array_at_unsafe(other, i);
        if (!Object_equals(object1, object2)) {
            return false;
        }
    }

    return true;
}

void Array_hash(const struct Array *array, struct SipHasher *hasher) {
    for (size_t i = 0; i < Array_count(array); ++i) {
        Object_hash(Array_at_unsafe(array, i), hasher);
    }
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
    // Fail if the given index is out of bounds.
    if (index >= Array_count(array)) {
        return NULL;
    }

    return Array_at_unsafe(array, index);
}

void *Array_at_unsafe(const struct Array *array, size_t index) {
    return array->objects[index];
}

bool Array_insert(struct Array *array, void *object, size_t index) {
    // Fail if the given index is out of bounds.
    if (index > Array_count(array)) {
        return false;
    }

    // Try to make sure the Array has room for at least one more Object.
    if (!Array_reserve(array, Array_count(array) + 1)) {
        return false;
    }

    // Move the Objects from the destination point onward up one index.
    void **source = array->objects + index;
    void **destination = array->objects + index + 1;
    size_t size = sizeof(void *) * (Array_count(array) - index);
    memmove(destination, source, size);

    // Insert the new Object.
    *source = object;
    ++array->count;

    return true;
}

bool Array_remove(struct Array *array, size_t index) {
    // Fail if the given index is out of range.
    if (index >= Array_count(array)) {
        return false;
    }

    // Delete the Object.
    void **destination = array->objects + index;
    Object_delete(*destination);
    --array->count;

    // Move the Objects past the removal point down one index.
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

void Array_clear(struct Array *array) {
    while (Array_pop(array));
}

bool Array_reserve(struct Array *array, size_t capacity) {
    // Succeed if the Array already has a large enough capacity.
    if (Array_capacity(array) >= capacity) {
        return true;
    }

    // Suggest a capacity and resize the Array to the greater of the two.
    size_t suggested = ArrayGrowthFactor * Array_capacity(array);
    return Array_reserve_exactly(array, max(capacity, suggested));
}

bool Array_reserve_exactly(struct Array *array, size_t capacity) {
    // Succeed if the Array already has a large enough capacity.
    if (Array_capacity(array) >= capacity) {
        return true;
    }

    // Try to reallocate the Object buffer.
    size_t size = sizeof(struct Object *) * capacity;
    void **objects = realloc(array->objects, size);
    if (!objects) {
        return false;
    }

    // Set the new Object buffer and capacity.
    array->objects = objects;
    array->capacity = capacity;

    return true;
}
