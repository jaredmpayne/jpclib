# jpclib

This library is a small collection of common data structures that I've written
during my time in university in order to streamline the process of building
low-level C applications for classes. All structures were written with the
goal of begin incredibly memory-safe and efficient.

## Library features

### Basic `Object` introspection

Most major data structures in the library are considered `Object`s. That is,
they contain internal pointers to common structure functions such as copy,
delete, compare, equate, and hash. Therefore, each `Object` knows how to
perform these actions on itself when necessary.

```c
struct Array *array = Array_new();
Array_push(Number_with_i64(42));
Array_push(Number_with_i64(64));

// The owned Objects know how to copy themselves and do so here.
struct Array *copy = Array_copy(array);
```

### Memory management through `Object` ownership

With basic `Object` introspection, memory management within the library can be
performed using a concept where any `Object` that is pushed to a
collection-type data structure is considered "owned" by that `Object`. With
this being the case, the programmer only needs to delete the root `Object` for
all child `Object`s to also be deleted.

```c
struct Array *array = Array_new();
Array_push(Optional_new(String_new()));
Array_push(Optional_new(String_new()));

// The structure:
//
// Array-------+
// |           |
// Optional    Optional
// |           |
// String      String
//
// Is properly freed in its entirety.
Array_delete(array);
```

## Possible future implementations

### Traits

Modern languages such as Rust and Swift provide a feature commonly known as
"traits" that ensure that an object is capable of performing a certain
operation before a function executes. As an example, it would be desirable to
be able to check that two `Object`s are actually comparable before attempting
to compare them.

In addition, some traits are capable of inheriting other traits. For example,
in order for an `Object` to be hashable, it must be equatable as well.

Such behavior is typically is enforced at compile-time and would not be
possible during a standard C build process. Therefore, this library would
attempt to implement this behavior at the run-time level such that the program
would abort when an `Object` is asked to do something it cannot. However, it
would be nice to expand on `Object` introspection in order to recreate this
behavior.

### Improved memory allocations

The original purpose of this library was to create "drag-and-drop" code I had
written myself that would require no additional compilation steps so that it
would be valid to include in my university projects. However, as the project
has grown and I plan on graduating, I may look to depending upon an improved
memory allocation library such as `jemalloc` or `tcmalloc` to improve the
performance as this is a major bottleneck for the library.
