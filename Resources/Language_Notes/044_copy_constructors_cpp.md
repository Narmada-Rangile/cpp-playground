### What is Copying? 🤔

  * **Copying** is the process of duplicating data from one memory location to another, creating two independent copies \[[00:04](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=4)\].
  * It's useful when you want to modify objects without affecting the original, but unnecessary copying can slow down your programs \[[00:20](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=20)\].

-----

### Copying Primitives and Structs 🧱

  * When you assign one primitive type to another (like `int b = a;`), you're creating a **copy**. `a` and `b` will have their own separate memory addresses \[[01:17](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=77)\].

  * The same goes for **structs**. Assigning one struct to another copies its values \[[01:35](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=95)\].

    ```cpp
    int a = 2;
    int b = a; // b is a copy of a
    b = 3;     // a is still 2, b is now 3

    struct Vector2 {
        float x, y;
    };
    Vector2 a = {2, 3};
    Vector2 b = a; // b is a copy of a
    b.x = 5;       // a.x is still 2, b.x is now 5
    ```

-----

### Copying Pointers 👉

  * When you copy a **pointer**, you're only copying the memory address it holds, not the data it points to \[[02:24](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=144)\].

  * This means both pointers will point to the **same memory location** \[[02:35](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=155)\].

  * If you modify the data through one pointer, the change will be visible through the other pointer as well \[[02:52](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=172)\].

    ```cpp
    Vector2* a = new Vector2();
    Vector2* b = a; // b now points to the same memory as a
    ```

-----

### Shallow Copy vs. Deep Copy 🌊

  * **Shallow Copy**: When you copy an object that contains pointers, a shallow copy only copies the pointer's value (the memory address), not the data it points to \[[10:19](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=619)\]. This can lead to multiple objects pointing to the same underlying memory, which can cause all sorts of problems, like one object's changes affecting another, or a crash from trying to delete the same memory twice \[[10:42](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=642), [11:52](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=712)\].

  * **Deep Copy**: A deep copy, on the other hand, allocates new memory for the copied object's data and then copies the contents of the original object's data into this new memory \[[12:33](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=753)\]. This ensures that each object has its own independent copy of the data \[[12:23](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=743)\].

-----

### The Copy Constructor 🛠️

  * A **copy constructor** is a special constructor that's called when you initialize an object with another object of the same type \[[13:15](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=795)\].

  * C++ provides a default copy constructor that performs a shallow copy \[[14:04](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=844)\]. To do a deep copy, you need to write your own.

    ```cpp
    class String {
    private:
        char* m_buffer;
        unsigned int m_size;
    public:
        // ... (other members) ...

        // Copy Constructor (Deep Copy)
        String(const String& other)
            : m_size(other.m_size)
        {
            m_buffer = new char[m_size + 1];
            memcpy(m_buffer, other.m_buffer, m_size + 1);
        }
    };
    ```

  * You can also **disable copying** for a class by deleting the copy constructor:

    ```cpp
    String(const String& other) = delete;
    ```

-----

### Avoiding Unnecessary Copies 🏃‍♀️

  * Passing large objects to functions **by value** creates unnecessary copies and can hurt performance \[[16:34](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=994)\].

  * The solution is to pass objects **by `const` reference** when you don't need to modify them. This avoids the copy and is generally the recommended approach \[[17:16](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=1036), [18:33](http://www.youtube.com/watch?v=BvR1Pgzzr38&t=1113)\].

    ```cpp
    void PrintString(const String& string) { // Pass by const reference
        std::cout << string << std::endl;
    }
    ```
