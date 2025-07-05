### The Problem: Unnecessary Copying

  * Before C++11, when you passed a "heavy" object (like a string or a vector that manages memory on the heap) to a function, it would often create a **deep copy**. This means allocating new memory and copying all the data from the original object to the new one \[[02:08](http://www.youtube.com/watch?v=ehMg6zvXuMY&t=128)\].
  * This is inefficient, especially when the original object is a temporary (an "r-value") that's about to be destroyed anyway. You're doing a lot of work for nothing\! \[[07:19](http://www.youtube.com/watch?v=ehMg6zvXuMY&t=439)\]

**Code Example (The "Old" Way):**

Imagine a simple `String` class. When you create an `Entity` that holds a `String`, the string literal "Cherno" is first used to create a temporary `String` object, and then that object is *copied* into the `Entity`.

```cpp
class String {
public:
    // Regular constructor
    String(const char* string) {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    // Copy constructor (deep copy)
    String(const String& other) {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }
    // ... destructor, etc.
private:
    char* m_Data;
    uint32_t m_Size;
};

class Entity {
public:
    Entity(const String& name) : m_Name(name) {}
private:
    String m_Name;
};

// In main:
Entity entity("Cherno"); // This will print "Created!" then "Copied!"
```

-----

### The Solution: Move Semantics

  * **Move semantics** allows you to "steal" the resources from a temporary object instead of copying them. For our `String` class, this means just copying the pointer to the data and its size, which is incredibly fast \[[08:00](http://www.youtube.com/watch?v=ehMg6zvXuMY&t=480)\].
  * This is achieved by creating a **move constructor**, which takes an **r-value reference** (`&&`) to the object being moved.

**Code Example (The "New" Way with Move):**

By adding a move constructor to our `String` class, we can avoid the expensive copy.

```cpp
class String {
public:
    // ... (other constructors)

    // Move constructor
    String(String&& other) noexcept {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data; // Just copy the pointer!

        // Null out the other object so it doesn't delete our data
        other.m_Size = 0;
        other.m_Data = nullptr;
    }
    // ...
};

class Entity {
public:
    // ...
    // Overload for r-value reference to trigger the move
    Entity(String&& name) : m_Name(std::move(name)) {}
private:
    String m_Name;
};

// In main:
Entity entity("Cherno"); // Now this will print "Created!" then "Moved!"
```

  * The `std::move` function is used to cast the `name` variable into an r-value reference, explicitly telling the compiler that it's okay to move from it \[[11:31](http://www.youtube.com/watch?v=ehMg6zvXuMY&t=691)\].

-----

### Conclusion

Move semantics is a powerful optimization technique in C++. By implementing move constructors and move assignment operators for your classes, you can avoid unnecessary memory allocations and copies, making your programs faster and more efficient \[[12:29](http://www.youtube.com/watch?v=ehMg6zvXuMY&t=749)\]. This is especially important for performance-critical applications like the simulations and animations you enjoy creating\! 🚀
