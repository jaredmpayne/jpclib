#ifndef JPCLIB_COLLECTIONS_ARRAY_H
#define JPCLIB_COLLECTIONS_ARRAY_H

#include <stdbool.h>
#include <stdlib.h>

/// A contiguous, growable collection of elements.
struct Array;

/// Creates a new, empty Array.
///
/// @return
///     Returns a new Array, or `NULL` if creation failed.
struct Array *Array_new();

/// Creates a new, empty Array with a given capacity.
///
/// @param capacity
///     The capacity the Array should have.
///
/// @return
///     Returns a new Array with the given capacity, or `NULL` if creation
///     failed.
struct Array *Array_with_capacity(size_t capacity);

/// Copies an Array.
///
/// @param array
///     The Array to be copied.
///
/// @return
///     Returns a new Array with with identical capacity and Objects as the
///     original, or `NULL` if the copy failed.
struct Array *Array_copy(const struct Array *array);

/// Deletes an Array and its Objects.
///
/// @param array
///     The Array to be deleted.
void Array_delete(struct Array *array);

/// Tests if two Arrays are equivalent.
///
/// @param array
///     The Array.
/// @param other
///     The Array to test against.
///
/// @return
///     Returns `true` if the two Arrays have identical Objects, `false`
///     otherwise.
bool Array_equals(const struct Array *array, const struct Array *other);

void Array_hash(const struct Array *array, struct SipHasher *hasher);

/// Returns the number of Objects in the Array.
///
/// @param array
///     The Array.
///
/// @return
///     Returns the number of Objects in the Array.
size_t Array_count(const struct Array *array);

/// Tests if the Array is empty.
///
/// @param array
///     The Array.
///
/// @return
///     Returns `true` if the Array contains no Objects, `false` otherwise.
bool Array_is_empty(const struct Array *array);

/// Returns the number of Objects the Array can hold without reallocating.
///
/// @param array
///     The Array.
///
/// @return
///     Returns he number of Objects the Array can hold without reallocating.
size_t Array_capacity(const struct Array *array);

/// Returns the Object at the given index in the Array.
///
/// @param array
///     The Array.
/// @param index
///     The index of the Object to return.
///
/// @return
///     Returns he Object at the given index, or `NULL` if the index is out of
///     range.
void *Array_at(const struct Array *array, size_t index);

/// Unsafely returns the Object at the given index in the Array.
///
/// @param array
///     The Array.
/// @param index
///     The index of the Object to return.
///
/// @return
///     Returns the Object at the given index.
///
/// @warning
///     Behavior of this function is undefined for out-of-range indices. It
///     is intended to be used as an optimization when the argument index is
///     guaranteed to not be out of range. Otherwise, `Array_at()` should be
///     preferred.
void *Array_at_unsafe(const struct Array *array, size_t index);

/// Inserts an Object into the Array at a given index.
///
/// @param array
///     The Array.
/// @param object
///     The Object to be inserted.
/// @param index
///     The index to insert the Object at.
///
/// @return
///     Returns `true` if the Object was successfully inserted. If the given
///     index was out of range or if the Array needed to reallocate and
///     failed, `false` is returned.
bool Array_insert(struct Array *array, void *object, size_t index);

/// Removes and deletes an Object from the Array at a given index.
///
/// @param array
///     The Array.
/// @param index
///     The index of the Object to be removed.
///
/// @return
///     Returns `true` if the Object was successfully removed. If the given
///     index was out of range, `false` is returned.
bool Array_remove(struct Array *array, size_t index);

/// Pushes an Object to the end of the Array.
///
/// @param array
///     The Array.
/// @param object
///     The Object to be appended to the Array.
///
/// @return
///     Returns `true` if the Object was successfully inserted. If the given
///     index was out of range or if the Array needed to reallocate and
///     failed, `false` is returned.
bool Array_push(struct Array *array, void *object);

/// Pops and deletes an Object from the end of the Array.
///
/// @param array
///     The Array.
///
/// @return
///     Returns `true` if the Object was successfully removed. If the Array
///     was empty, `false` is returned.
bool Array_pop(struct Array *array);

/// Removes and deletes all Objects from the Array.
///
/// @param array
///     The Array.
void Array_clear(struct Array *array);

/// Reserves space for the Array to hold at least the given capacity.
///
/// @detail
///     More space may be allocated to avoid frequency reallocations.
///
/// @param array
///     The Array.
/// @param capacity
///     The number of Objects the Array should be able to hold.
///
/// @return
///     Returns `true` if the Array was successfully reallocated or already
///     has a large enough capacity. If a reallocation occurs and fails,
///     `false` is returned.
bool Array_reserve(struct Array *array, size_t capacity);

/// Reserves space for the Array to hold exactly the given capacity.
///
/// @param array
///     The Array.
/// @param capacity
///     The number of Objects the Array should be able to hold.
///
/// @return
///     Returns `true` if the Array was successfully reallocated or already
///     has a large enough capacity. If a reallocation occurs and fails,
///     `false` is returned.
bool Array_reserve_exactly(struct Array *array, size_t capacity);

#endif
