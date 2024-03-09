# Arena Allocator Integration Interview

Welcome to the Arena Allocator *integration* interview.

You will be implementing a basic memory allocator for fixed-sized objects.
This allocator, once initialized with a block of memory, will combine a basic
'bump' allocation strategy with a singly-linked free-list for object re-use.

Please write this code as you would anything that you plan on running for a long time:
Focus on maintainability and readability!

Proceed to [Part 1](../../issues/1), Bump Allocator.

## How to Build

1. Begin by cloning the repository and change to that directory.
2. `mkdir build`
3. `cd build`
4. `cmake .. -DCMAKE_BUILD_TYPE=Debug -Dgtest_disable_pthreads=ON`
5. `make all`

## How to Run Tests

1. After completing the build process, ensure you are in the `build` directory.
2. `make clean all`
3. `./tests/arena_allocator_tests`

Note that you may have to run step 2 between successive attempts to test your changes.
