//
//  arena_allocator.h
//  Allocator
//
//  Created by Martin Mroz on 6/15/22.
//  Copyright © 2022 Stripe. All rights reserved.
//

#ifndef ARENA_ALLOCATOR_H
#define ARENA_ALLOCATOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>

/// Forward-declarations.
typedef struct FreeListNode FreeListNode;

/**
 * An arena allocator is a type of memory management model where each allocated
 * object is assigned to a zone, or 'arena.'
 * - Allocation from the arena is O(1).
 *   Elements are allocated either by incrementing the top pointer, or - if there
 *   is no more space available - by dequeing an element from the free list.
 * - Deallocation of an arena-allocated element is O(1).
 *   Elements are deallocated by appending them to the free list.
 * - Deallocating all elements at the same time is O(1).
 *   This is achieved by deallocating the entire arena.
 * For simplicity, this arena requires all objects allocated to be the same size.
 */
typedef struct ArenaAllocator {
    /// Pointer to the start of the arena.
    void *arena_start;
    /// Pointer to the current top of the arena slab. Incremented on allocation.
    void *arena_top;
    /// The number of bytes of space in the arena.
    size_t arena_size_bytes;
    /// The number of bytes of space remaining in the arena.
    size_t arena_capacity_bytes;
    /// The size of an element.
    size_t element_size_bytes;
    /// Tail of the free list.
    FreeListNode *free_list_tail;
} ArenaAllocator;

/**
 * When an arena-allocated element is freed, it is appended to the tail
 * of the free list. Once there is no more memory that can be allocated from
 * the arena itself, the allocator will re-use previously freed elements by
 * dequing them from the tail of the free list.
 */
typedef struct FreeListNode {
    struct FreeListNode *prev;
} FreeListNode;

/**
 * Initializes an arena allocator with the specified memory region.
 * @param uninitialized The previously uninitialized arena allocator.
 * @param arena_start The start of the arena allocation region.
 * @param arena_size_bytes The number of bytes of space available in the arena allocation region.
 * @param element_min_size_bytes The minimum number of bytes for each element in the arena.
 * @return `true` if the arena is successfully allocated and has space for at least one element.
 */
extern bool arena_allocator_init(
    ArenaAllocator *uninitialized,
    void *arena_start,
    size_t arena_size_bytes,
    size_t element_min_size_bytes
);

/**
 * Allocates a new element of the fixed size.
 * @param allocator Arena allocator.
 * @return A newly allocated element, if available, or NULL if no space remains.
 */
extern void * arena_allocator_malloc(ArenaAllocator *allocator);

/**
 * Frees a previously allocated element.
 * @param allocator Arena allocator.
 * @param managed_element Element to free.
 */
extern void arena_allocator_free(ArenaAllocator *allocator, void *managed_element);

/**
 * @param allocator Arena allocator.
 * @returns The number of elements that can be allocated in the arena in total.
 */
extern ssize_t arena_allocator_get_size(ArenaAllocator *allocator);

/**
 * @param allocator Arena allocator.
 * @returns The number of additional elements that can be allocated in the arena.
 */
extern ssize_t arena_allocator_get_capacity(ArenaAllocator *allocator);

#ifdef __cplusplus
}
#endif

#endif /* ARENA_ALLOCATOR_H */
