### What is an Array?

  * An array is a **collection of elements**, usually of the same type, stored one after another in memory \[[00:27](http://www.youtube.com/watch?v=ENDaJi08jCU&t=27)\].
  * They're great for handling large amounts of data without needing to create a bunch of individual variables \[[00:45](http://www.youtube.com/watch?v=ENDaJi08jCU&t=45)\].
  * An array lets you refer to multiple variables with a single name \[[01:38](http://www.youtube.com/watch?v=ENDaJi08jCU&t=98)\].

-----

### Defining and Accessing Arrays

  * To define an array, you specify the data type, a name, and the number of elements in square brackets \[[01:52](http://www.youtube.com/watch?v=ENDaJi08jCU&t=112)\].
    ```cpp
    int example[5]; // Declares an array named 'example' that can hold 5 integers
    ```
  * You access elements using an **index** in square brackets, starting from **0** \[[02:15](http://www.youtube.com/watch?v=ENDaJi08jCU&t=135)\].
    ```cpp
    example[0] = 2; // Sets the first element of the array to 2
    ```
  * Accessing an index outside the array's bounds (like a negative index or an index that's too high) can cause a "memory access violation" \[[03:41](http://www.youtube.com/watch?v=ENDaJi08jCU&t=221)\]. This can crash your program in debug mode or silently corrupt memory in release mode \[[03:56](http://www.youtube.com/watch?v=ENDaJi08jCU&t=236)\].

-----

### Arrays and For Loops

  * For loops are perfect for looping through arrays to set or access multiple elements at once \[[04:36](http://www.youtube.com/watch?v=ENDaJi08jCU&t=276)\].
    ```cpp
    for (int i = 0; i < 5; i++) {
        example[i] = 2; // Sets every element in the 'example' array to 2
    }
    ```

-----

### Memory Layout of Arrays

  * Arrays store their data **contiguously** in memory, meaning the elements are placed right next to each other \[[06:02](http://www.youtube.com/watch?v=ENDaJi08jCU&t=362)\].
  * When you access an element at a specific index, it calculates an offset from the array's starting memory address \[[06:43](http://www.youtube.com/watch?v=ENDaJi08jCU&t=403)\]. For example, `example[2]` adds `2 * sizeof(int)` bytes to the starting address of `example`.

-----

### Arrays as Pointers

  * An array name itself is basically a **pointer** to the first element of the array \[[07:17](http://www.youtube.com/watch?v=ENDaJi08jCU&t=437)\].
    ```cpp
    int* pointer = example; // 'pointer' now points to the beginning of the 'example' array
    ```
  * You can use **pointer arithmetic** to access array elements, which is what array indexing does behind the scenes \[[07:46](http://www.youtube.com/watch?v=ENDaJi08jCU&t=466)\].
    ```cpp
    *(pointer + 2) = 6; // Equivalent to example[2] = 6;
    ```
  * When you do pointer arithmetic, the number you add to the pointer is multiplied by the size of the data type it points to \[[08:29](http://www.youtube.com/watch?v=ENDaJi08jCU&t=509)\].

-----

### Dynamic Array Allocation (Heap vs. Stack)

  * **Stack Allocation:** Arrays you declare directly (like `int example[5];`) are allocated on the **stack**. Their lifetime is tied to the scope they're declared in, and they're automatically destroyed when that scope ends \[[10:01](http://www.youtube.com/watch?v=ENDaJi08jCU&t=601)\].
  * **Heap Allocation:** You can dynamically allocate arrays on the **heap** using the `new` keyword \[[09:44](http://www.youtube.com/watch?v=ENDaJi08jCU&t=584)\].
    ```cpp
    int* another = new int[5]; // Allocates an array of 5 integers on the heap
    ```
  * Heap-allocated arrays stick around until you explicitly `delete` them or the program ends \[[10:11](http://www.youtube.com/watch?v=ENDaJi08jCU&t=611)\].
  * For heap-allocated arrays, you have to use `delete[]` to free the memory \[[10:16](http://www.youtube.com/watch?v=ENDaJi08jCU&t=616)\].
    ```cpp
    delete[] another; // Deallocates the heap-allocated array
    ```
  * **Lifetime Differences:** You need heap allocation if an array needs to outlive the function it was created in, like when you're returning an array from a function \[[11:00](http://www.youtube.com/watch?v=ENDaJi08jCU&t=660)\].
  * **Memory Indirection:** Heap-allocated arrays add an extra layer of indirection (a pointer pointing to another block of memory), which can slow things down because of cache misses \[[11:22](http://www.youtube.com/watch?v=ENDaJi08jCU&t=682)\]. It's generally better to use stack-allocated arrays when you can to avoid this \[[12:56](http://www.youtube.com/watch?v=ENDaJi08jCU&t=776)\].

-----

### Determining Array Size

  * For **stack-allocated arrays**, you can find the number of elements using `sizeof(array_name) / sizeof(data_type)` \[[14:18](http://www.youtube.com/watch?v=ENDaJi08jCU&t=858)\].
    ```cpp
    int a[5];
    int count = sizeof(a) / sizeof(int); // 'count' will be 5
    ```
  * For **heap-allocated arrays**, you can't directly find their size at runtime with `sizeof` because `sizeof` on a pointer will only give you the size of the pointer itself, not the array it points to \[[15:04](http://www.youtube.com/watch?v=ENDaJi08jCU&t=904)\]. You have to keep track of the size yourself \[[15:37](http://www.youtube.com/watch?v=ENDaJi08jCU&t=937)\].
  * It's good practice to define array sizes as `static const` variables for stack-allocated arrays to make sure they're compile-time constants \[[15:51](http://www.youtube.com/watch?v=ENDaJi08jCU&t=951)\].

-----

### `std::array` (C++11 and later)

  * C++11 introduced `std::array`, a built-in data structure that's better than raw C-style arrays \[[13:10](http://www.youtube.com/watch?v=ENDaJi08jCU&t=790)\].
  * `std::array` has **bounds checking** and keeps track of its own size, which makes it safer and easier to use \[[13:21](http://www.youtube.com/watch?v=ENDaJi08jCU&t=801)\].
    ```cpp
    #include <array>

    std::array<int, 5> another_std_array; // Declares a std::array of 5 integers
    another_std_array.size(); // Returns 5
    ```
  * While `std::array` has a little overhead (for things like bounds checking and storing the size), it's often worth it for the safety and convenience it provides \[[17:14](http://www.youtube.com/watch?v=ENDaJi08jCU&t=1034)\].
