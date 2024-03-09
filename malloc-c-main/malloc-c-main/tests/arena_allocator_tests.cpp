#include "gtest/gtest.h"

#include "arena_allocator.h"

// The kind of object stored in the arena allocator.
extern "C" struct TestEntry {
    size_t value;
};

class ArenaAllocatorTests : public ::testing::Test {
    protected:

        /// Sets up a test allocator with space for two TestEntry objects.
        void SetUp() override {
            const size_t arena_size_bytes = 2 * sizeof(struct TestEntry);
            const size_t element_size_bytes = sizeof(struct TestEntry);
            void * arena = malloc(arena_size_bytes);

            // Initialize a new arena allocator with space for two elements.
            arena_allocator_init(
                &_allocator,
                arena,
                arena_size_bytes,
                element_size_bytes
            );
        }

        /// Tears down the allocator.
        void TearDown() override {
            free(_allocator.arena_start);
            _allocator.arena_start = nullptr;
        }

    protected:
        ArenaAllocator _allocator;
};

// MARK: - Part 1: Bump Allocation

TEST_F(ArenaAllocatorTests, testInitialSizeAndCapacity) {
    ASSERT_EQ(arena_allocator_get_size(&_allocator), 2);
    ASSERT_EQ(arena_allocator_get_capacity(&_allocator), 2);
}

TEST_F(ArenaAllocatorTests, testBumpAllocateOneEntry) {
    struct TestEntry *const test_entry_one = 
        static_cast<struct TestEntry *>(arena_allocator_malloc(&_allocator));

    // Verify the counts are updated properly.
    ASSERT_EQ(arena_allocator_get_size(&_allocator), 2);
    ASSERT_EQ(arena_allocator_get_capacity(&_allocator), 1);

    // Verify the entry allocated from the start of the arena.
    ASSERT_NE(test_entry_one, nullptr);
    ASSERT_EQ(test_entry_one, _allocator.arena_start);
}

TEST_F(ArenaAllocatorTests, testBumpAllocateTwoEntries) {
    struct TestEntry *const test_entry_one =
        static_cast<struct TestEntry *>(arena_allocator_malloc(&_allocator));
    struct TestEntry *const test_entry_two =
        static_cast<struct TestEntry *>(arena_allocator_malloc(&_allocator));

    // Verify the counts are updated properly.
    ASSERT_EQ(arena_allocator_get_size(&_allocator), 2);
    ASSERT_EQ(arena_allocator_get_capacity(&_allocator), 0);

    // Verify the two entries are not equal.
    ASSERT_NE(test_entry_two, nullptr);
    ASSERT_NE(test_entry_two, test_entry_one);
}

// MARK: - Part 2: Free List

TEST_F(ArenaAllocatorTests, testFreeOneEntry) {
    struct TestEntry *const test_entry_one =
        static_cast<struct TestEntry *>(arena_allocator_malloc(&_allocator));
    struct TestEntry *const test_entry_two =
        static_cast<struct TestEntry *>(arena_allocator_malloc(&_allocator));

    // Verify there is no space left.
    ASSERT_EQ(arena_allocator_get_size(&_allocator), 2);
    ASSERT_EQ(arena_allocator_get_capacity(&_allocator), 0);

    // Place the second entry into the free list.
    arena_allocator_free(&_allocator, test_entry_two);

    // Verify the entry is deallocated properly.
    ASSERT_EQ(arena_allocator_get_size(&_allocator), 2);
    ASSERT_EQ(arena_allocator_get_capacity(&_allocator), 1);
}

TEST_F(ArenaAllocatorTests, testFreeTwoEntries) {
    struct TestEntry *const test_entry_one =
        static_cast<struct TestEntry *>(arena_allocator_malloc(&_allocator));
    struct TestEntry *const test_entry_two =
        static_cast<struct TestEntry *>(arena_allocator_malloc(&_allocator));

    // Place the both entries into the free list.
    arena_allocator_free(&_allocator, test_entry_one);
    arena_allocator_free(&_allocator, test_entry_two);

    // Verify the entry is deallocated properly.
    ASSERT_EQ(arena_allocator_get_size(&_allocator), 2);
    ASSERT_EQ(arena_allocator_get_capacity(&_allocator), 2);
}

TEST_F(ArenaAllocatorTests, testReallocateTwoEntries) {
    struct TestEntry *const test_entry_one =
        static_cast<struct TestEntry *>(arena_allocator_malloc(&_allocator));
    struct TestEntry *const test_entry_two =
        static_cast<struct TestEntry *>(arena_allocator_malloc(&_allocator));

    // Place the both entries into the free list.
    arena_allocator_free(&_allocator, test_entry_one);
    arena_allocator_free(&_allocator, test_entry_two);

    // Re-allocate both entries - last in, first out.
    struct TestEntry *const test_entry_two_reallocated =
        static_cast<struct TestEntry *>(arena_allocator_malloc(&_allocator));
    struct TestEntry *const test_entry_one_reallocated =
        static_cast<struct TestEntry *>(arena_allocator_malloc(&_allocator));

    // Verify the counts are updated.
    ASSERT_EQ(arena_allocator_get_size(&_allocator), 2);
    ASSERT_EQ(arena_allocator_get_capacity(&_allocator), 0);

    // Verify the objects were reallocated as expected.
    ASSERT_EQ(test_entry_one_reallocated, test_entry_one);
    ASSERT_EQ(test_entry_two_reallocated, test_entry_two);
}
