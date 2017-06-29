#include "jpclib/random/OsRng.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#if defined(__unix__) || defined(__APPLE__)

#include <stdio.h>

struct OsRng {
    FILE *urandom;
};

struct OsRng *OsRng_new() {
    // Try to allocate a new OsRng.
    struct OsRng *rng = malloc(sizeof(struct OsRng));
    if (!rng) {
        return NULL;
    }

    // Initialize the data members.
    rng->urandom = NULL;

    // Try to open the file "/dev/urandom" for reading as a binary file.
    rng->urandom = fopen("/dev/urandom", "rb");
    if (!rng->urandom) {
        OsRng_delete(rng);
        return NULL;
    }

    return rng;
}

void OsRng_delete(struct OsRng *rng) {
    if (rng->urandom) {
        fclose(rng->urandom);
    }
    free(rng);
}

void OsRng_fill_bytes(struct OsRng *rng, void *bytes, size_t size) {
    fread(bytes, sizeof(uint8_t), size, rng->urandom);
}

#elif defined(_WIN32)

#include <Wincrypt.h>
#include <windows.h>

struct OsRng {
    HCRYPTPROV provider;
};

struct OsRng *OsRng_new() {
    // Try to allocate a new OsRng.
    struct OsRng *rng = malloc(sizeof(struct OsRng));
    if (!rng) {
        return NULL;
    }

    // Initialize the data members.
    rng->provider = NULL;

    // Try to acquire a handle to a cryptographic service provider.
    if (!CryptAcquireContext(&provider, NULL, NULL, PROV_RSA_FULL, 0)) {
        OsRng_delete(rng);
        return NULL;
    }

    return rng;
}

 void OsRng_delete(struct OsRng *rng) {
     if (rng->provider) {
         CryptReleaseContext(&rng->provider, 0);
     }
     free(rng);
 }

 void OsRng_fill_bytes(struct OsRng *rng, void *bytes, size_t size) {
     CryptGenRandom(rng->provider, size, bytes);
 }

#endif

uint8_t OsRng_next_u8(struct OsRng *rng) {
    uint8_t number;
    OsRng_fill_bytes(rng, &number, sizeof(uint8_t));
    return number;
}

uint16_t OsRng_next_u16(struct OsRng *rng) {
    uint16_t number;
    OsRng_fill_bytes(rng, &number, sizeof(uint16_t));
    return number;
}

uint32_t OsRng_next_u32(struct OsRng *rng) {
    uint32_t number;
    OsRng_fill_bytes(rng, &number, sizeof(uint32_t));
    return number;
}

uint64_t OsRng_next_u64(struct OsRng *rng) {
    uint64_t number;
    OsRng_fill_bytes(rng, &number, sizeof(uint64_t));
    return number;
}
