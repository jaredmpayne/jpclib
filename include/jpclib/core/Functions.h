#ifndef JPCLIB_CORE_FUNCTIONS_H
#define JPCLIB_CORE_FUNCTIONS_H

#include <stdbool.h>

typedef int (*CompareFunction)(const void *, const void *);

typedef void *(*CopyFunction)(const void *);

typedef void (*DeleteFunction)(void *);

typedef bool (*EqualsFunction)(const void *, const void *);

struct Functions {
    CompareFunction compare_function;
    CopyFunction copy_function;
    DeleteFunction delete_function;
    EqualsFunction equals_function;
};

#endif
