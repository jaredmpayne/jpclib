#ifndef JPCLIB_CORE_FUNCTIONS_H
#define JPCLIB_CORE_FUNCTIONS_H

#include <stdbool.h>
#include <stdint.h>

#include "jpclib/hashing/SipHasher.h"

typedef int (*CompareFunction)(const void *, const void *);

typedef void *(*CopyFunction)(const void *);

typedef void (*DeleteFunction)(void *);

typedef bool (*EqualsFunction)(const void *, const void *);

typedef void (*HashFunction)(const void *, struct SipHasher *);

struct Functions {
    CompareFunction compare_function;
    CopyFunction copy_function;
    DeleteFunction delete_function;
    EqualsFunction equals_function;
    HashFunction hash_function;
};

#endif
