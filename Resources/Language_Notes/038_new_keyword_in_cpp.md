### The `new` Keyword in C++

The primary purpose of the **`new`** keyword is to **allocate memory on the heap** \[[01:27](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=87)\]. When you use `new`, it calculates the required memory size for the data type, asks the operating system for that memory, and returns a pointer to the allocated block \[[01:34](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=94)\]. This process can be time-consuming \[[02:31](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=151)\].

-----

### How `new` Works with Classes

When you use `new` with a class, it does two things:

1.  Allocates enough memory on the heap to store the object \[[05:04](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=304)\].
2.  Calls the constructor of that class \[[05:10](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=310)\].

`new` is an **operator**, which means its behavior can be overloaded \[[05:32](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=332)\]. It typically calls the C function `malloc` behind the scenes, but unlike `malloc`, `new` also calls the object's constructor, which is why it's the preferred way to create objects in C++ \[[07:09](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=429)\].

-----

### Memory Deallocation with `delete`

Memory allocated with `new` is not automatically freed \[[08:09](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=489)\]. You must manually deallocate it using the **`delete`** keyword to prevent memory leaks \[[07:47](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=467)\].

  * **Rule for arrays**: If you allocate an array with `new[]`, you must deallocate it with `delete[]` \[[09:02](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=542)\].

-----

### Placement New

`new` also supports **"placement new,"** which lets you construct an object at a specific, pre-allocated memory address instead of allocating new memory \[[09:20](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=560)\].

-----

### Code Examples

  * **Allocating a single integer:**

    ```cpp
    int* b = new int; // Allocates 4 bytes for an integer
    ```

    \[[03:42](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=222)\]

  * **Allocating an array of integers:**

    ```cpp
    int* b = new int[50]; // Allocates 200 bytes for 50 integers
    ```

    \[[03:54](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=234)\]

  * **Allocating an `Entity` object:**

    ```cpp
    Entity* e = new Entity(); // Allocates memory and calls the constructor
    ```

    \[[04:05](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=245)\]

  * **Deallocating a single object:**

    ```cpp
    delete b;
    delete e;
    ```

    \[[07:53](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=473)\]

  * **Deallocating an array:**

    ```cpp
    delete[] b;
    delete[] e;
    ```

    \[[09:02](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=542)\]

  * **Placement New Syntax:**

    ```cpp
    // Assuming 'b' is a pre-existing memory address
    new (b) Entity(); // Calls the Entity constructor at the address 'b'
    ```

    \[[09:38](http://www.youtube.com/watch?v=NUZdUSqsCs4&t=578)\]
