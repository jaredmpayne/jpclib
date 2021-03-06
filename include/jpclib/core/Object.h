#ifndef JPCLIB_CORE_OBJECT_H
#define JPCLIB_CORE_OBJECT_H

#include <stdbool.h>

struct Object;

int Object_compare(const void *object, const void *other);

void *Object_copy(const void *object);

void Object_delete(void *object);

bool Object_equals(const void *object, const void *other);

#endif
