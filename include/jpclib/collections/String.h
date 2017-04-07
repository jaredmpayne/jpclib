#ifndef JPCLIB_COLLECTIONS_STRING_H
#define JPCLIB_COLLECTIONS_STRING_H

#include <stdbool.h>
#include <stddef.h>

/// A contiguous collection of characters.
struct String;

/// Creates a new, empty String.
///
/// @return
///     Returns a new String, or `NULL` if creation failed.
struct String *String_new();

/// Creates a new, empty String with a given capacity.
///
/// @param capacity
///     The capacity the String should have.
///
/// @return
///     Returns a new String with the given capacity, or `NULL` if creation
///     failed.
struct String *String_with_capacity(size_t capacity);

/// Copies an String.
///
/// @param string
///     The String to be copied.
///
/// @return
///     Returns a new String with with identical capacity and characters as
///     the original, or `NULL` if the copy failed.
struct String *String_copy(const struct String *string);

/// Deletes an String and its characters.
///
/// @param string
///     The String to be deleted.
void String_delete(struct String *string);

/// Tests if two Strings are equivalent.
///
/// @param string
///     The String.
/// @param other
///     The String to test against.
///
/// @return
///     Returns `true` if the two Strings have identical characters, `false`
///     otherwise.
bool String_equals(const struct String *string, const struct String *other);

/// Returns the number of characters in the String.
///
/// @param string
///     The String.
///
/// @return
///     Returns the number of characters in the String.
size_t String_count(const struct String *string);

/// Tests if the String is empty.
///
/// @param string
///     The String.
///
/// @return
///     Returns `true` if the String contains no characters, `false`
///     otherwise.
bool String_is_empty(const struct String *string);

/// Returns the number of characters the String can hold without reallocating.
///
/// @param string
///     The String.
///
/// @return
///     Returns he number of characters the String can hold without
///     reallocating.
size_t String_capacity(const struct String *string);

char *String_characters(const struct String *string);

/// Returns the character at the given index in the String.
///
/// @param string
///     The String.
/// @param index
///     The index of the character to return.
///
/// @return
///     Returns he character at the given index, or `NULL` if the index is out
///     of range.
char String_at(const struct String *string, size_t index);

/// Unsafely returns the character at the given index in the String.
///
/// @param string
///     The String.
/// @param index
///     The index of the character to return.
///
/// @return
///     Returns the character at the given index.
///
/// @warning
///     Behavior of this function is undefined for out-of-range indices. It
///     is intended to be used as an optimization when the argument index is
///     guaranteed to not be out of range. Otherwise, `String_at()` should be
///     preferred.
char String_at_unsafe(const struct String *string, size_t index);

/// Inserts an character into the String at a given index.
///
/// @param string
///     The String.
/// @param character
///     The character to be inserted.
/// @param index
///     The index to insert the character at.
///
/// @return
///     Returns `true` if the character was successfully inserted. If the
///     given index was out of range or if the String needed to reallocate and
///     failed, `false` is returned.
bool String_insert(struct String *string, char character, size_t index);

/// Removes a character from the String at a given index.
///
/// @param string
///     The String.
/// @param index
///     The index of the character to be removed.
///
/// @return
///     Returns `true` if the character was successfully removed. If the given
///     index was out of range, `false` is returned.
bool String_remove(struct String *string, size_t index);

/// Pushes a character to the end of the String.
///
/// @param string
///     The String.
/// @param character
///     The character to be appended to the String.
///
/// @return
///     Returns `true` if the character was successfully inserted. If the
///     given index was out of range or if the String needed to reallocate and
///     failed, `false` is returned.
bool String_push(struct String *string, char character);

/// Pops a character from the end of the String.
///
/// @param string
///     The String.
///
/// @return
///     Returns `true` if the character was successfully removed. If the
///     String was empty, `false` is returned.
bool String_pop(struct String *string);

/// Removes all characters from the String.
///
/// @param string
///     The String.
void String_clear(struct String *string);

/// Reserves space for the String to hold at least the given capacity.
///
/// @detail
///     More space may be allocated to avoid frequency reallocations.
///
/// @param string
///     The String.
/// @param capacity
///     The number of characters the String should be able to hold.
///
/// @return
///     Returns `true` if the String was successfully reallocated or already
///     has a large enough capacity. If a reallocation occurs and fails,
///     `false` is returned.
bool String_reserve(struct String *string, size_t capacity);

/// Reserves space for the String to hold exactly the given capacity.
///
/// @param string
///     The String.
/// @param capacity
///     The number of characters the String should be able to hold.
///
/// @return
///     Returns `true` if the String was successfully reallocated or already
///     has a large enough capacity. If a reallocation occurs and fails,
///     `false` is returned.
bool String_reserve_exactly(struct String *string, size_t capacity);

#endif
