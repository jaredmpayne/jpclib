#ifndef JPCLIB_CORE_OPTIONAL_H
#define JPCLIB_CORE_OPTIONAL_H

#include <stdbool.h>

/// Used to indicate the possible absence of a value.
struct Optional;

/// Creates a new, empty Optional.
///
/// @return
///     Returns a new, empty Optional, or `NULL` if creation fails.
struct Optional *Optional_none();

/// Creates a new Optional containing the given Object.
///
/// @param object
///     The Object the Optional will contain.
///
/// @return
///     Returns a new Optional containing the given Object.
struct Optional *Optional_some(void *object);

/// Deletes an Optional and its contained Object.
///
/// @param optional
///     The Optional.
void Optional_delete(struct Optional *optional);

/// Returns the Object contained by the Optional.
///
/// @param optional
///     The Optional.
///
/// @return
///     Returns the Object contained by the Optional.
///
/// @warning
///     This function aborts if the Optional is empty. It is up to the user to
///     know if the Optional contains a value before using this function.
struct Object *Optional_object(const struct Optional *optional);

/// Tests if the Optional contains an Object.
///
/// @param optional
///     The Optional.
///
/// @return
///     Returns `true` if the Optional contains an Object, otherwise `false`.
bool Optional_is_some(const struct Optional *optional);

/// Tests if the Optional is empty.
///
/// @param optional
///     The Optional.
///
/// @return
///     Returns `true` if the Optional doesn't an Object, otherwise `false`.
bool Optional_is_none(const struct Optional *optional);

/// Sets an Optional to contain a new Object and deletes its old Object.
///
/// @param optional
///     The optional.
/// @param object
///     The new Object the Optional will contain.
void Optional_set(struct Optional *optional, void *object);

/// Resets an Optional to be empty and deletes its current Object.
///
/// @param optional
///     The Optional.
void Optional_reset(struct Optional *optional);

#endif
