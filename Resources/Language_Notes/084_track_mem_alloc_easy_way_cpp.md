### Importance of Memory in Computing \[[00:10](http://www.youtube.com/watch?v=sLlGEUO_EGE&t=10)\]

Memory is fundamental to how computers operate. While modern computers have abundant memory (gigabytes), understanding memory allocation is still crucial for optimizing programs and debugging.

-----

### Why Track Memory Allocations \[[01:08](http://www.youtube.com/watch?v=sLlGEUO_EGE&t=68)\]

  * **Optimization**: Identifying where memory is allocated on the heap can help reduce its usage, leading to faster program execution, especially in performance-critical code.
  * **Understanding Program Behavior**: Tracking allocations can reveal how your program works, even if you wrote the code, helping to uncover forgotten or hidden allocations from libraries or older code.

-----

### Overriding the `new` Operator \[[04:49](http://www.youtube.com/watch?v=sLlGEUO_EGE&t=289)\]

The `new` keyword in C++ is actually a function call. By overriding the global `operator new`, you can intercept memory allocation requests.

**Code Example:**

```cpp
void* operator new(size_t size) {
    // Custom logic here, e.g., printing allocation size
    // std::cout << "Allocating " << size << " bytes" << std::endl;
    return malloc(size); // Call the standard malloc to allocate memory
}
```

This allows you to:

  * Print information about allocations \[[05:53](http://www.youtube.com/watch?v=sLlGEUO_EGE&t=353)\].
  * Set breakpoints to trace the call stack and identify the source of allocations \[[06:09](http://www.youtube.com/watch?v=sLlGEUO_EGE&t=369)\]. This is useful for both explicit `new` calls and implicit allocations made by standard library containers (like `std::string`) or smart pointers (like `std::make_unique`) \[[06:21](http://www.youtube.com/watch?v=sLlGEUO_EGE&t=381)\].

-----

### Overriding the `delete` Operator \[[08:48](http://www.youtube.com/watch?v=sLlGEUO_EGE&t=528)\]

Similar to `new`, the `delete` keyword can also be overridden to track memory deallocation.

**Code Example:**

```cpp
void operator delete(void* memory) {
    // Custom logic here, e.g., printing deallocation
    // std::cout << "Freeing memory" << std::endl;
    free(memory); // Call the standard free to deallocate memory
}

// To get size information during deallocation
void operator delete(void* memory, size_t size) {
    // std::cout << "Freeing " << size << " bytes" << std::endl;
    free(memory);
}
```

Overriding `operator delete` allows you to track when memory is freed and from where \[[09:05](http://www.youtube.com/watch?v=sLlGEUO_EGE&t=545)\].

-----

### Creating an Allocation Tracker \[[09:57](http://www.youtube.com/watch?v=sLlGEUO_EGE&t=597)\]

By combining the overridden `new` and `delete` operators, you can create a simple system to track total allocated, total freed, and current memory usage.

**Code Example (Struct for Metrics):**

```cpp
struct AllocationMetrics {
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage() {
        return TotalAllocated - TotalFreed;
    }
};

static AllocationMetrics s_AllocationMetrics; // Static instance
```

**Updating Metrics in Operators:**

```cpp
void* operator new(size_t size) {
    s_AllocationMetrics.TotalAllocated += size;
    return malloc(size);
}

void operator delete(void* memory, size_t size) {
    s_AllocationMetrics.TotalFreed += size;
    free(memory);
}
```

This allows you to print memory usage at different points in your program to see how it changes \[[11:00](http://www.youtube.com/watch?v=sLlGEUO_EGE&t=660)\].

-----

### Alternatives to Custom Tracking \[[11:42](http://www.youtube.com/watch?v=sLlGEUO_EGE&t=702)\]

While custom code is quick and dirty, tools like **Visual Studio's built-in memory profiling tools** or **Valgrind** offer more sophisticated memory tracking and analysis capabilities.
