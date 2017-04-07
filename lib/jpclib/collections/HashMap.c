#include "jpclib/collections/HashMap.h"

#include <math.h>
#include <stddef.h>
#include <stdlib.h>

#include "jpclib/collections/Array.h"
#include "jpclib/core/Functions.h"

static const float HashMapLoadFactor = 0.9;

static const struct Functions HashMapFunctions = {
    .delete_function = (DeleteFunction)HashMap_delete,
};

struct HashMap {
    const struct Functions *functions;
    struct Array *table;
    size_t count;
};


struct HashMap *HashMap_new() {
    return HashMap_with_capacity(0);
}

struct HashMap *HashMap_with_capacity(size_t capacity) {
    // Try to allocate a new HashMap.
    struct HashMap *map = malloc(sizeof(struct HashMap));
    if (!map) {
        return NULL;
    }

    // Initialize the data members.
    map->functions = &HashMapFunctions;
    map->table = NULL;
    map->hasher = NULL;
    map->count = 0;

    // Try to create a new table Array.
    map->table = Array_new();
    if (!map->table) {
        HashMap_delete(map);
        return NULL;
    }

    // Try to reserve exactly the requested capacity.
    if (!HashMap_reserve_exactly(map, capacity)) {
        HashMap_delete(map);
        return NULL;
    }

    return map;
}

void HashMap_delete(struct HashMap *map) {
    if (map->table) {
        Array_delete(map->table);
    }
    free(map);
}

size_t HashMap_count(const struct HashMap *map) {
    return map->count;
}

bool HashMap_is_empty(const struct HashMap *map) {
    return !HashMap_count(map);
}

size_t HashMap_capacity(const struct HashMap *map) {
    return floor(HashMapLoadFactor * HashMap_table_capacity(map));
}

size_t HashMap_table_capacity(const struct HashMap *map) {
    return Array_capacity(map->table);
}

void *HashMap_at(const struct HashMap *map, const void *key) {

}

bool HashMap_insert(struct HashMap *map, void *key, void *value) {
    
}

bool HashMap_remove(struct HashMap *map, const void *key) {

}

void HashMap_clear(struct HashMap *map) {
    for (size_t i = 0; i < Array_count(map->table); ++i) {
        Optional_reset(Array_at_unsafe(map->table, i));
    }
}
