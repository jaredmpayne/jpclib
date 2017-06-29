#ifndef JPCLIB_RANDOM_OS_RNG_H
#define JPCLIB_RANDOM_OS_RNG_H

#include <stddef.h>
#include <stdint.h>

/// A random number generator that generates randomness from the best source
/// available on the operating system. For UNIX-like systems, this is
/// `/dev/urandom`. For Windows, the Wincrypt library is used.
///
/// WARNING: This Object has not yet been tested on Windows.
struct OsRng;

/// Creates a new OsRng.
///
/// @return
///     Returns a new OsRng, or `NULL` if creation failed.
struct OsRng *OsRng_new();

/// Deletes an OsRng.
///
/// @param rng
///     The OsRng.
void OsRng_delete(struct OsRng *rng);

/// Fills a buffer with random data.
///
/// @param rng
///     The OsRng.
/// @param bytes
///     The buffer to fill with random data.
/// @param size
///     The size of the buffer in bytes.
void OsRng_fill_bytes(struct OsRng *rng, void *bytes, size_t size);

/// Returns the next random 8-bit unsigned integer.
///
/// @param rng
///     The OsRng.
///
/// @return
///     Returns the next random 8-bit unsigned integer.
uint8_t OsRng_next_u8(struct OsRng *rng);

/// Returns the next random 16-bit unsigned integer.
///
/// @param rng
///     The OsRng.
///
/// @return
///     Returns the next random 16-bit unsigned integer.
uint16_t OsRng_next_u16(struct OsRng *rng);

/// Returns the next random 32-bit unsigned integer.
///
/// @param rng
///     The OsRng.
///
/// @return
///     Returns the next random 32-bit unsigned integer.
uint32_t OsRng_next_u32(struct OsRng *rng);

/// Returns the next random 64-bit unsigned integer.
///
/// @param rng
///     The OsRng.
///
/// @return
///     Returns the next random 64-bit unsigned integer.
uint64_t OsRng_next_u64(struct OsRng *rng);

#endif
