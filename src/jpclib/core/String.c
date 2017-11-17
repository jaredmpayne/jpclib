#include "jpclib/core/String.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "jpclib/core/Functions.h"
#include "jpclib/math/stats.h"

static const float StringGrowthFactor = 1.6;

static const struct Functions StringFunctions = {
    .copy_function = (CopyFunction)String_copy,
    .delete_function = (DeleteFunction)String_delete,
    .equals_function = (EqualsFunction)String_equals,
    .hash_function = (HashFunction)String_hash,
};

struct String {
    const struct Functions *functions;
    char *characters;
    size_t count;
    size_t capacity;
};

struct String *String_new() {
    return String_with_capacity(0);
}

struct String *String_with_capacity(size_t capacity) {
    struct String *string = malloc(sizeof(struct String));
    if (!string) {
        return NULL;
    }

    string->functions = &StringFunctions;
    string->characters = NULL;
    string->count = 0;
    string->capacity = 0;

    if (!String_reserve_exactly(string, capacity)) {
        String_delete(string);
        return NULL;
    }

    return string;
}

struct String *String_copy(const struct String *string) {
    struct String *copy = String_with_capacity(String_count(string));
    if (!copy) {
        return NULL;
    }

    for (size_t i = 0; i < String_count(string); ++i) {
        String_push(copy, String_at_unsafe(string, i));
    }

    return copy;
}

void String_delete(struct String *string) {
    free(string->characters);
    free(string);
}

bool String_equals(const struct String *string, const struct String *other) {
    if (String_count(string) != String_count(other)) {
        return false;
    }

    for (size_t i = 0; i < String_count(string); ++i) {
        if (String_at_unsafe(string, i) != String_at_unsafe(other, i)) {
            return false;
        }
    }

    return true;
}

void String_hash(const struct String *string, struct SipHasher *hasher) {
    SipHasher_write(hasher, String_characters(string), String_count(string) * sizeof(char));
}

size_t String_count(const struct String *string) {
    return string->count;
}

bool String_is_empty(const struct String *string) {
    return !String_count(string);
}

char *String_characters(const struct String *string) {
    return string->characters;
}

size_t String_capacity(const struct String *string) {
    return string->capacity;
}

char String_at(const struct String *string, size_t index) {
    if (index >= String_count(string)) {
        return NULL;
    }

    return String_at_unsafe(string, index);
}

char String_at_unsafe(const struct String *string, size_t index) {
    return string->characters[index];
}

bool String_insert(struct String *string, char character, size_t index) {
    if (index > String_count(string)) {
        return false;
    }

    if (!String_reserve(string, String_count(string) + 1)) {
        return false;
    }

    char *source = string->characters + index;
    char *destination = string->characters + index + 1;
    size_t size sizeof(char) * String_count(string);
    memmove(destination, source, size);

    *source = character;
    ++string->count;

    return true;
}

bool String_remove(struct String *string, size_t index) {
    if (index >= String_count(string)) {
        return false;
    }

    char *source = string->characters + index + 1;
    char *destination = string->characters + index;
    size_t size = sizeof(char) * (Array_count(string) - index + 1);
    memmove(destination, source, size);

    return true;
}

bool String_push(struct String *string, char character) {
    return String_insert(string, character, String_count(string));
}

bool String_pop(struct String *string) {
    return String_remove(string, String_count(string) - 1);
}

void String_clear(struct String *string) {
    string->characters = NULL;
    string->count = 0;
}

bool String_reserve(struct String *string, size_t capacity) {
    if (String_capacity(string) >= capacity) {
        return true;
    }

    size_t suggested = StringGrowthFactor * String_capacity(string);
    return String_reserve_exactly(string, max(capacity, suggested));
}

bool String_reserve_exactly(struct String *string, size_t capacity) {
    if (String_capacity(string) >= capacity) {
        return true;
    }

    size_t size = sizeof(char) * capacity + sizeof(char);
    char *characters = realloc(string->characters, size);
    if (!characters) {
        return false;
    }

    string->characters = characters;
    string->capacity = capacity;

    return true;
}
