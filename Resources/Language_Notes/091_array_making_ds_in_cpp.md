### Introduction to Data Structures \[[00:15](http://www.youtube.com/watch?v=TzB5ZeKQIHM&t=15)\]

The video kicks off a series on building custom data structures from scratch. While C++ provides these in the Standard Template Library (STL), creating your own is a great way to understand how they work under the hood. This video focuses on a basic, stack-allocated array.

-----

### Understanding Arrays \[[01:03](http://www.youtube.com/watch?v=TzB5ZeKQIHM&t=63)\]

The video explains the two main types of arrays in C++:

  * **Stack-allocated (Static) Arrays**: These have a fixed size that's known when you compile your code. They're created on the stack and are automatically cleaned up when they go out of scope.
    ```cpp
    int array[5]; // A stack-allocated array of 5 integers
    ```
  * **Heap-allocated (Dynamic) Arrays**: You can create these with a size that's determined while the program is running. They're allocated on the heap and you have to manually free the memory once you're done with them.
    ```cpp
    int* heapArray = new int[size]; // A heap-allocated array
    // ... use the array ...
    delete[] heapArray; // Don't forget to free the memory!
    ```

The video also highlights that using the stack can be faster because it avoids the overhead of heap allocation.

-----

### The C++ Standard Library's `std::array` \[[05:59](http://www.youtube.com/watch?v=TzB5ZeKQIHM&t=359)\]

C++11 introduced `std::array`, which gives you a convenient way to work with fixed-size, stack-allocated arrays. It's a template class, so you specify both the data type and the size when you create one.

```cpp
#include <array>

std::array<int, 5> collection; // An std::array of 5 integers
```

-----

### Building a Custom Array Class \[[07:31](http://www.youtube.com/watch?v=TzB5ZeKQIHM&t=451)\]

Here's a breakdown of how the video builds a custom array class:

  * **Initial Structure**: The first attempt is a simple class with a fixed-size, fixed-type array inside.
  * **Using Templates for Size**: To make the size flexible at compile time, a template parameter `size_t S` is introduced.
    ```cpp
    template<size_t S>
    class Array {
    private:
        int m_Data[S];
    };
    ```
  * **Using Templates for Type**: To allow for arrays of different data types, another template parameter `typename T` is added.
    ```cpp
    template<typename T, size_t S>
    class Array {
    private:
        T m_Data[S];
    };
    ```
  * **Implementing `size()`**: A `size()` method is added to return the array's size. It's marked `constexpr` so it can be evaluated at compile time.
    ```cpp
    template<typename T, size_t S>
    class Array {
    public:
        constexpr size_t Size() const { return S; }
    private:
        T m_Data[S];
    };
    ```
  * **Implementing the Index Operator `[]`**: To access elements using square brackets, the `operator[]` is overloaded. It returns a reference (`T&`) to allow modifying the elements. A `const` version is also provided for read-only access.
    ```cpp
    template<typename T, size_t S>
    class Array {
    public:
        // ...
        T& operator[](size_t index) { return m_Data[index]; }
        const T& operator[](size_t index) const { return m_Data[index]; }
    private:
        T m_Data[S];
    };
    ```
  * **Implementing `Data()`**: A `Data()` method is added to get a raw pointer to the underlying array. This is useful for functions like `memset`.
    ```cpp
    template<typename T, size_t S>
    class Array {
    public:
        // ...
        T* Data() { return m_Data; }
        const T* Data() const { return m_Data; }
    private:
        T m_Data[S];
    };
    ```

-----

### Future Enhancements \[[21:27](http://www.youtube.com/watch?v=TzB5ZeKQIHM&t=1287)\]

The video mentions that future videos will cover adding **iterators** to enable range-based for loops and other **utility functions** like `fill` and `swap`.
