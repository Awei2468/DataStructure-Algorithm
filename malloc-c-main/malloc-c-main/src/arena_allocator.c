//
//  arena_allocator.c
//  Allocator
//
//  Created by Martin Mroz on 6/15/22.
//  Copyright © 2022 Stripe. All rights reserved.
//

#include "arena_allocator.h"

#include <assert.h>

#pragma mark - Helpers

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#pragma mark - Initialization

bool arena_allocator_init(
    ArenaAllocator *uninitialized,
    void * arena_start,
    size_t arena_size_bytes,
    size_t element_min_size_bytes
) {
    // Each element must be at least as large as a free list node.
    const size_t size_of_free_list_node = sizeof(struct FreeListNode);
    const size_t element_size_bytes = MAX(size_of_free_list_node, element_min_size_bytes);

    // Verify that there is space for at least one element in the arena.
    if (arena_size_bytes < element_size_bytes) {
        return false;
    }

    // Initialize all fields of the arena.
    uninitialized->arena_start = arena_start;
    uninitialized->arena_top = arena_start;
    uninitialized->arena_size_bytes = arena_size_bytes;
    uninitialized->arena_capacity_bytes = arena_size_bytes;
    uninitialized->element_size_bytes = element_size_bytes;
    uninitialized->free_list_tail = NULL;
    return true;
}

#pragma mark - Part 1: Bump Allocation

/**
 * @brief Determines if the bump arena is full.
 *
 * @param allocator Arena allocator.
 * @return true if the bump arena contains *no* additional space for allocations, false otherwise.
 */
static bool bump_arena_is_full(ArenaAllocator *allocator) {
    return allocator->arena_capacity_bytes == 0;
}

/**
 * @brief Calculates the total number of elements that can be allocated in the bump arena.
 * 
 * @param allocator Arena allocator.
 * @return ssize_t the number of elements that can be allocated in the bump arena
 *   or -1 in the event of an unhandled error.
 */
static ssize_t bump_arena_get_size(ArenaAllocator *allocator) {
    return allocator->arena_capacity_bytes / allocator->element_size_bytes;
}

/**
 * @brief Calculates the number of *additional* elements that can be allocated in the
 *   bump arena. Note that this number decreases as the bump arena is allocated,
 *   and will never grow.
 *
 * @param allocator Arena allocator.
 * @return ssize_t the number of *additional* elements that can be allocated in the bump arena
 *   or -1 in the event of an unhandled error.
 */
static ssize_t bump_arena_get_capacity(ArenaAllocator *allocator) {
    return allocator->arena_size_bytes / allocator->element_size_bytes;
}

/**
 * @brief Allocates a new element from the bump arena assuming space remains.
 *
 * @param allocator Arena allocator.
 * @return void* the newly allocated element, or NULL in the event of an unhandled error.
 */
static void * bump_arena_allocate(ArenaAllocator *allocator) {
    if (!allocator) return NULL;
    ArenaAllocator *newAllocator = allocator;
}

#pragma mark - Part 2: Free List

/**
 * @brief Determines whether the free list is currently empty.
 *   When the free list is empty, there are no previously freed elements that can
 *   be re-used.
 *
 * @param allocator Arena allocator.
 * @return true if the free list is currently empty.
 */
static bool free_list_is_empty(ArenaAllocator *allocator) {
    return true;
}

/**
 * @brief Computes the number of elements in the free list.
 *   This count increases as elements are freed and decreases as elements are re-used.
 *
 * @param allocator Arena allocator.
 * @return ssize_t the number of elements in the free list available for reuse
 *   or -1 in the event of an unhandled error.
 */
static ssize_t free_list_get_count(ArenaAllocator *allocator) {
    return 0;
}

/**
 * @brief Enqueues an element previously allocated from the bump arena into the free list.
 *
 * @param allocator Arena allocator.
 * @param element an element previously allocated from the bump arena.
 * @return true if the element was successfully emplaced in the free list or
 *   false in the event of an unhandled error.
 */
static bool free_list_push_element(ArenaAllocator *allocator, void *element) {
    return false;
}

/**
 * @brief Dequeues an element previously allocated from the bump arena for reuse. 
 *   This element is removed from the free list.
 *
 * @param allocator Arena allocator.
 * @return void* the element available for reuse, or NULL in the event of an unhandled error.
 */
static void * free_list_pop_element(ArenaAllocator *allocator) {
    return NULL;
}

#pragma mark - Allocation

void * arena_allocator_malloc(ArenaAllocator *allocator) {
    if (!bump_arena_is_full(allocator)) {
        return bump_arena_allocate(allocator);
    } else if (!free_list_is_empty(allocator)) {
        return free_list_pop_element(allocator);
    } else {
        return false;
    }
}

#pragma mark - Deallocation

void arena_allocator_free(ArenaAllocator *allocator, void * managed_element) {
    free_list_push_element(allocator, managed_element);
}

#pragma mark - Size and Capacity

ssize_t arena_allocator_get_size(ArenaAllocator *allocator) {
    assert(allocator != NULL);

    if (allocator == NULL) {
        return -1;
    }

    return bump_arena_get_size(allocator);
}

ssize_t arena_allocator_get_capacity(ArenaAllocator *allocator) {
    assert(allocator != NULL);

    if (allocator == NULL) {
        return -1;
    }

    const size_t bump_left = bump_arena_get_capacity(allocator);
    const size_t free_left = free_list_get_count(allocator);

    return bump_left + free_left;
}
