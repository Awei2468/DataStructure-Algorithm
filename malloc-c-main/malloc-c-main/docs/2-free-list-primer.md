# Free List Primer

As the bump allocation strategy doesn't provide a practical way of deallocating an object, a free list is maintained alongside.

When an object is no longer needed, it is passed to a deallocation function. The deallocation function emplaces the discarded object onto a stack of objects available for reuse.

When an object ($008) has been deallocated, the memory layout looks like this:

```
   $000             $008              $010            $018             $020
  +----------------+----------------+----------------+----------------+----------------+
  |                |                |                |                |                |
  |   Allocated    |      Free      |   Allocated    |   Allocated    |   Allocated    |
  |                |                |                |                |                |
  +----------------+----------------+----------------+----------------+----------------+
                                                                                       ^
                                                                                       |
                                                                                       |

   $008
  +----------------+
  |                |
  |      Free      |
  |                |
  +----------------+
```

Deallocating another two objects ($018 and $020) looks like this: 

```

   $000             $008              $010            $018             $020
  +----------------+----------------+----------------+----------------+----------------+
  |                |                |                |                |                |
  |   Allocated    |      Free      |   Allocated    |      Free      |      Free      |
  |                |                |                |                |                |
  +----------------+----------------+----------------+----------------+----------------+
                                                                                       ^
                                                                                       |
                                                                                       |
   $008                              $018                              $020
  +----------------+                +----------------+                +----------------+
  |                |                |                |                |                |
  |      Free      |--------------->|      Free      |--------------->|      Free      |
  |                |                |                |                |                |
  +----------------+                +----------------+                +----------------+
 ```
 
 Re-using an object that was previously deallocated is accomplished by removing it from the stack.
 