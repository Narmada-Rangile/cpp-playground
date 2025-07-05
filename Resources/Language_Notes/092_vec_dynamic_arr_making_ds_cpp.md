### Introduction to Dynamic Arrays (Vectors)

The video explains how to build a dynamic array, which is a resizable array similar to `std::vector` in C++ \[[00:05](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=5)\]. Unlike a fixed-size `std::array`, a dynamic array is allocated on the **heap**, which allows its size to change while the program is running \[[03:50](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=230)\].

-----

### Core Mechanics

A dynamic array class needs three key members:

  * `m_data`: A pointer to the heap-allocated memory where the elements are stored \[[04:46](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=286)\].
  * `m_size`: Tracks the number of elements currently in the vector \[[09:49](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=589)\].
  * `m_capacity`: Tracks the total allocated memory space \[[10:05](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=605)\].

Keeping `capacity` separate from `size` is a performance optimization. It reduces how often you need to reallocate memory, which can be a slow process \[[10:28](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=628)\]. When the `size` reaches the `capacity`, a larger block of memory is allocated, and the elements are moved over. A common strategy is to increase the capacity by 50% \[[11:37](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=697)\].

-----

### Implementing the `Vector` Class

Here’s a look at the implementation details:

  * **Class Structure**: The `Vector` class is a template to work with any data type.

    ```cpp
    template<typename T>
    class Vector
    {
    private:
        T* m_data = nullptr;
        size_t m_size = 0;
        size_t m_capacity = 0;

        void ReAlloc(size_t newCapacity);
    public:
        Vector();
        ~Vector();

        void PushBack(const T& value);
        void PushBack(T&& value);
        template<typename... Args>
        T& EmplaceBack(Args&&... args);

        void PopBack();
        void Clear();

        size_t Size() const { return m_size; }

        const T& operator[](size_t index) const;
        T& operator[](size_t index);
    };
    ```

  * **`ReAlloc` Function**: This private function is the core of the dynamic behavior. It allocates a new, larger block of memory, moves the existing elements using `std::move` to be efficient \[[13:58](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=838)\], and then frees the old block \[[12:59](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=779)\].

  * **`PushBack` and `EmplaceBack`**:

      * `PushBack` adds an element to the end of the vector. It has overloads for both copying and moving objects \[[24:41](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=1481)\].
      * `EmplaceBack` is even more efficient as it constructs the object directly in place within the vector's memory, avoiding any temporary copies or moves \[[27:02](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=1622)\].

    <!-- end list -->

    ```cpp
    // Example of EmplaceBack
    template<typename T>
    template<typename... Args>
    T& Vector<T>::EmplaceBack(Args&&... args)
    {
        if (m_size >= m_capacity)
            ReAlloc(m_capacity + m_capacity / 2);

        new (m_data + m_size) T(std::forward<Args>(args)...);
        return m_data[m_size++];
    }
    ```

  * **`PopBack` and `Clear`**:

      * `PopBack` removes the last element and makes sure to call its destructor to release any resources it holds \[[30:50](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=1850)\].
      * `Clear` removes all elements by calling their destructors and resetting the size to zero \[[31:23](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=1883)\].

  * **Destructor**: The class destructor calls `Clear()` and then deallocates the raw memory block \[[39:47](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=2387)\].

-----

### A Critical Bug: Double Deletion

The video points out a major bug in a naive implementation \[[36:08](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=2168)\]. If you use a simple `delete[] m_data`, it will call the destructor for every *possible* element in the allocated capacity, not just the ones that are currently in use (the `m_size`). If you've already called destructors manually in `PopBack` or `Clear`, this leads to a "double delete" error and a crash \[[38:42](http://www.youtube.com/watch?v=ryRf4Jh_YC0&t=2322)\].

**The Solution**: The fix is to separate memory allocation from object construction.

1.  Allocate raw memory using `operator new`.
2.  Construct objects in that memory using **placement new**.
3.  Manually call destructors (`object.~T()`).
4.  Deallocate the raw memory using `operator delete`.

This gives you precise control and prevents the double-deletion bug.
