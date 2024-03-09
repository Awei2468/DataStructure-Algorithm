cmake_minimum_required(VERSION 3.15)

include(GoogleTest)
include(CTest)
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  if(MSVC)
    add_compile_options(/MD$<$<CONFIG:Debug>:d>)
  endif()   # MSVC
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()     # NOT googletest_POPULATED

enable_testing()

add_executable(
  arena_allocator_tests
  arena_allocator_tests.cpp
)
target_link_libraries(
  arena_allocator_tests
  gtest_main
)
target_link_libraries(
  arena_allocator_tests
  ArenaAllocator
)

gtest_discover_tests(arena_allocator_tests)
