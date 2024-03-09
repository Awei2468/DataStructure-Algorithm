# Define the ArenaAllocator library.
add_library(ArenaAllocator arena_allocator.c)

# Make sure the compiler can find include files for the library when
# other libraries or executables link the library. This is required
# for our unit test targets.
target_include_directories(ArenaAllocator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
