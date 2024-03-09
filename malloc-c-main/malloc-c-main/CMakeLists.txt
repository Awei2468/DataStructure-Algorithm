cmake_minimum_required(VERSION 3.15)

# Define the ArenaAllocator 1.0 project and configuration file.
project(ArenaAllocator VERSION 1.0)
configure_file(arena_allocator_config.h.in arena_allocator_config.h)

# Add the library and tests subdirectories.
add_subdirectory(src)
add_subdirectory(tests)
