#ifndef JPCLIB_CORE_OPTIONAL_H
#define JPCLIB_CORE_OPTIONAL_H

#include <stdbool.h>

struct Optional;

struct Optional *Optional_none();

struct Optional *Optional_some(void *object);

void Optional_delete(struct Optional *optional);

struct Object *Optional_object(const struct Optional *optional);

bool Optional_is_some(const struct Optional *optional);

bool Optional_is_none(const struct Optional *optional);

void Optional_set(struct Optional *optional, void *object);

void Optional_reset(struct Optional *optional);

#endif
