#include "jpclib/hashing/SipHasher.h"

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#include "jpclib/math/bytes.h"

static void SipHasher_sip_round(struct SipHasher *hasher);

struct SipHasher {
    uint64_t k0;
    uint64_t k1;
    uint64_t v0;
    uint64_t v1;
    uint64_t v2;
    uint64_t v3;
};

struct SipHasher *SipHasher_new() {
    return SipHasher_with_keys(0, 0);
}

struct SipHasher *SipHasher_with_keys(uint64_t k0, uint64_t k1) {
    struct SipHasher *hasher = malloc(sizeof(struct SipHasher));
    if (!hasher) {
        return NULL;
    }

    hasher->k0 = k0;
    hasher->k1 = k1;

    SipHasher_reset(hasher);

    return hasher;
}

void SipHasher_delete(struct SipHasher *hasher) {
    free(hasher);
}

void SipHasher_reset(struct SipHasher *hasher) {
    // Hex is "somepseudorandomlygeneratedbytes".
    hasher->v0 = hasher->k0 ^ 0x736f6d6570736575;
    hasher->v1 = hasher->k1 ^ 0x646f72616e646f6d;
    hasher->v2 = hasher->k0 ^ 0x6c7967656e657261;
    hasher->v3 = hasher->k1 ^ 0x7465646279746573;
}

// TODO: Convert each word to little-endian for added security.
// TODO: Append b % 256 to last byte for added security.
void SipHasher_write(struct SipHasher *hasher, const void *data, size_t size) {
    size_t b = ceil(size / 8);
    for (size_t i = 0; i < b; i += 8) {
        hasher->v3 ^= *(uint64_t *)(data + i);

        SipHasher_sip_round(hasher);
        SipHasher_sip_round(hasher);

        hasher->v0 ^= *(uint64_t *)(data + i);
    }
}

uint64_t SipHasher_finish(struct SipHasher *hasher) {
    hasher->v2 ^= 0xff;
    return hasher->v0 ^ hasher->v1 ^ hasher->v2 ^ hasher->v3;
}

void SipHasher_write_u8(struct SipHasher *hasher, uint8_t n) {
    SipHasher_write(hasher, &n, sizeof(uint8_t));
}

void SipHasher_write_u16(struct SipHasher *hasher, uint16_t n) {
    SipHasher_write(hasher, &n, sizeof(uint16_t));
}

void SipHasher_write_u32(struct SipHasher *hasher, uint32_t n) {
    SipHasher_write(hasher, &n, sizeof(uint32_t));
}

void SipHasher_write_u64(struct SipHasher *hasher, uint64_t n) {
    SipHasher_write(hasher, &n, sizeof(uint64_t));
}

static void SipHasher_sip_round(struct SipHasher *hasher) {
    hasher->v0 += hasher->v1;
    hasher->v1 = rotate_left(hasher->v1, 13);
    hasher->v1 ^= hasher->v0;
    hasher->v0 = rotate_left(hasher->v0, 32);

    hasher->v2 += hasher->v3;
    hasher->v3 = rotate_left(hasher->v3, 16);
    hasher->v3 ^= hasher->v2;

    hasher->v0 += hasher->v3;
    hasher->v3 = rotate_left(hasher->v3, 21);
    hasher->v3 ^= hasher->v0;

    hasher->v2 += hasher->v1;
    hasher->v1 = rotate_left(hasher->v1, 17);
    hasher->v1 ^= hasher->v2;
    hasher->v2 = rotate_left(hasher->v2, 32);
}
