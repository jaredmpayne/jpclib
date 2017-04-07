#ifndef JPCLIB_HASHING_SIP_HASHER_H
#define JPCLIB_HASHING_SIP_HASHER_H

#include <stddef.h>
#include <stdint.h>

/// An implementation of SipHash-2-4.
struct SipHasher;

/// Creates a new SipHasher with keys set to 0.
///
/// @return
///     Returns a new SipHasher with keys set to 0.
struct SipHasher *SipHasher_new();

/// Creates a new SipHasher with the given keys.
///
/// @param k0, k1
///     The SipHasher's keys.
///
/// @return
///     Returns a new SipHasher with the keys set to the given values.
struct SipHasher *SipHasher_with_keys(uint64_t k0, uint64_t k1);

/// Deletes a SipHasher.
///
/// @param hasher
///     The SipHasher.
void SipHasher_delete(struct SipHasher *hasher);

/// Resets a SipHasher to its initial state.
///
/// @param hasher
///     The SipHasher.
void SipHasher_reset(struct SipHasher *hasher);

/// Writes data to the SipHasher.
///
/// @param hasher
///     The SipHasher.
/// @param data
///     The data to write to the SipHasher.
/// @param size
///     The size of the data to write to the SipHasher, in bytes.
void SipHasher_write(struct SipHasher *hasher, const void *data, size_t size);

/// Returns the hash value of the data written to the SipHasher.
///
/// @param hasher
///     The SipHasher.
///
/// @return
///     Returns the hash value of the data written to the SipHasher.
uint64_t SipHasher_finish(struct SipHasher *hasher);

/// Writes an unsigned 8-bit integer to the SipHasher.
///
/// @param hasher
///     The SipHasher.
/// @param n
///     The unsigned 8-bit integer.
void SipHasher_write_u8(struct SipHasher *hasher, uint8_t n);

/// Writes an unsigned 16-bit integer to the SipHasher.
///
/// @param hasher
///     The SipHasher.
/// @param n
///     The unsigned 16-bit integer.
void SipHasher_write_u16(struct SipHasher *hasher, uint16_t n);

/// Writes an unsigned 32-bit integer to the SipHasher.
///
/// @param hasher
///     The SipHasher.
/// @param n
///     The unsigned 32-bit integer.
void SipHasher_write_u32(struct SipHasher *hasher, uint32_t n);

/// Writes an unsigned 64-bit integer to the SipHasher.
///
/// @param hasher
///     The SipHasher.
/// @param n
///     The unsigned 64-bit integer.
void SipHasher_write_u64(struct SipHasher *hasher, uint64_t n);

#endif
