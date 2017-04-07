#include "jpclib/core/Optional.h"

#include <stdbool.h>
#include <stdlib.h>

#include "jpclib/core/Functions.h"
#include "jpclib/core/Object.h"

static const struct Functions OptionalFunctions = {
    .delete_function = (DeleteFunction)Optional_delete,
};

struct Optional {
    const struct Functions *functions;
    void *object;
    bool is_some;
};

struct Optional *Optional_none() {
    // Try to allocate a new Optional.
    struct Optional *optional = malloc(sizeof(struct Optional));
    if (!optional) {
        return NULL;
    }

    // Initialize the data members.
    optional->functions = &OptionalFunctions;
    optional->object = NULL;
    optional->is_some = false;

    return optional;
}

struct Optional *Optional_some(void *object) {
    // Try to create a new empty Optional.
    struct Optional *optional = Optional_none();
    if (!optional) {
        return NULL;
    }

    // Set the Optional to the given Object.
    Optional_set(optional, object);

    return optional;
}

void Optional_delete(struct Optional *optional) {
    Optional_reset(optional);
    free(optional);
}

struct Object *Optional_object(const struct Optional *optional) {
    if (Optional_is_none(optional)) {
        abort();
    }
    return optional->object;
}

bool Optional_is_some(const struct Optional *optional) {
    return optional->is_some;
}

bool Optional_is_none(const struct Optional *optional) {
    return !Optional_is_some(optional);
}

void Optional_set(struct Optional *optional, void *object) {
    // Reset the Optional if it already has an Object.
    if (Optional_is_some(optional)) {
        Optional_reset(optional);
    }

    // Give the Optional the given Object.
    optional->object = object;
    optional->is_some = true;
}

void Optional_reset(struct Optional *optional) {
    // Delete the Object if the Optional has one.
    if (Optional_is_some(optional)) {
        Object_delete(optional->object);
    }

    // Reset the Optional's data members.
    optional->object = NULL;
    optional->is_some = false;
}
