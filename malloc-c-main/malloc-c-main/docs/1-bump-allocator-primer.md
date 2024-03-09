# Bump Allocator Primer

A bump allocator is one of the simplest memory allocation strategies in common use today.

The allocator itself is constructed with a contiguous chunk of memory. The allocator maintains a pointer to the start of the region (for book-keeping) and a pointer into that region from which the next chunk of memory is to be allocated.

Memory allocation is very straight-forward and extremely efficient.

As long as sufficient free space remains, an allocation is carried out by returning the interior pointer tracking the start of the free space. This pointer is then incremented by the number of bytes allocated.

Allocating 8 bytes in a 40-byte region would result in a memory layout that looks like this:

```
  $000             $008              $010            $018             $020
  +----------------+----------------+----------------+----------------+----------------+
  |                |                |                |                |                |
  |   Allocated    |      Free      |      Free      |      Free      |      Free      |
  |                |                |                |                |                |
  +----------------+----------------+----------------+----------------+----------------+
                   ^
                   |
                   |
```

Allocating another 8 bytes in the same region would result in the following memory layout:

```

   $000             $008              $010            $018             $020
  +----------------+----------------+----------------+----------------+----------------+
  |                |                |                |                |                |
  |   Allocated    |   Allocated    |      Free      |      Free      |      Free      |
  |                |                |                |                |                |
  +----------------+----------------+----------------+----------------+----------------+
                                    ^
                                    |
                                    |
```

As is common with the bump allocation strategy, our bump allocator will not support deallocation at this point.
