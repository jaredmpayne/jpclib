#ifndef JPCLIB_COLLECTIONS_HASH_MAP_H
#define JPCLIB_COLLECTIONS_HASH_MAP_H

#include <stdbool.h>
#include <stddef.h>

struct HashMap;

struct HashMap *HashMap_new();

struct HashMap *HashMap_with_capacity(size_t capacity);

void HashMap_delete(struct HashMap *map);

size_t HashMap_count(const struct HashMap *map);

bool HashMap_is_empty(const struct HashMap *map);

size_t HashMap_capacity(const struct HashMap *map);

size_t HashMap_table_capacity(const struct HashMap *map);

void *HashMap_at(const struct HashMap *map, const void *key);

bool HashMap_insert(struct HashMap *map, void *key, void *value);

bool HashMap_remove(struct HashMap *map, const void *key);

void HashMap_clear(struct HashMap *map);

bool HashMap_reserve(struct HashMap *map, size_t capacity);

bool HashMap_reserve_exactly(struct HashMap *map, size_t capacity);

#endif
