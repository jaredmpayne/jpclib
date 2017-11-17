#include "jpclib/core/Object.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "jpclib/core/Functions.h"

struct Object {
    const struct Functions *functions;
};

int Object_compare(const void *object, const void *other) {
    const struct Object *object1 = (const struct Object *)object;
    const struct Object *object2 = (const struct Object *)other;

    if (object1->functions != object2->functions) {
        abort();
    }

    if (!object1->functions->compare_function) {
        abort();
    }

    return object1->functions->compare_function(object1, object2);
}

void *Object_copy(const void *object) {
    const struct Object *object1 = (const struct Object *)object;

    if (!object1->functions->copy_function) {
        abort();
    }

    return object1->functions->copy_function(object1);
}

void Object_delete(void *object) {
    struct Object *object1 = (struct Object *)object;

    if (!object1->functions->delete_function) {
        abort();
    }

    object1->functions->delete_function(object1);
}

bool Object_equals(const void *object, const void *other) {
    const struct Object *object1 = (const struct Object *)object;
    const struct Object *object2 = (const struct Object *)other;

    if (object1->functions != object2->functions) {
        abort();
    }

    if (!object1->functions->equals_function) {
        abort();
    }

    return object1->functions->equals_function(object1, object2);
}
