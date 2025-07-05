### Implicit Conversion \[[00:12](http://www.youtube.com/watch?v=Rr1NX1lH3oE&t=12)\]

**Implicit conversion** is when C++ automatically converts one data type to another without you explicitly telling it to. The compiler is allowed to perform one implicit conversion at a time \[[00:24](http://www.youtube.com/watch?v=Rr1NX1lH3oE&t=24)\].

**Example:**

```cpp
class Entity {
private:
    std::string m_Name;
    int m_Age;

public:
    Entity(const std::string& name)
        : m_Name(name), m_Age(-1) {}

    Entity(int age)
        : m_Name("Unknown"), m_Age(age) {}
};

// In main or another function
Entity a = "Cherno"; // Implicitly converts "Cherno" to std::string, then constructs Entity
Entity b = 22;       // Implicitly converts 22 to an Entity
```

The line `Entity b = 22;` is an example of implicit conversion, where the integer `22` is automatically converted into an `Entity` object because a constructor that takes an integer exists \[[02:27](http://www.youtube.com/watch?v=Rr1NX1lH3oE&t=147)\].

-----

### Implicit Conversion in Function Arguments \[[02:46](http://www.youtube.com/watch?v=Rr1NX1lH3oE&t=166)\]

If you have a function that takes an `Entity` object, you can pass a compatible data type (like an `int`), and C++ will implicitly convert it.

**Example:**

```cpp
void PrintEntity(const Entity& entity) {
    // ... printing logic
}

// In main or another function
PrintEntity(22); // Implicitly converts 22 to an Entity
```

However, C++ only allows **one** implicit conversion \[[03:52](http://www.youtube.com/watch?v=Rr1NX1lH3oE&t=232)\]. So, `PrintEntity("Cherno");` would fail because it requires two conversions: `char array` to `std::string`, and then `std::string` to `Entity` \[[03:23](http://www.youtube.com/watch?v=Rr1NX1lH3oE&t=203)\].

-----

### The `explicit` Keyword \[[04:50](http://www.youtube.com/watch?v=Rr1NX1lH3oE&t=290)\]

The **`explicit`** keyword is used with constructors to disable implicit conversions. If a constructor is marked `explicit`, it must be called directly \[[05:02](http://www.youtube.com/watch?v=Rr1NX1lH3oE&t=302)\].

**Example:**

```cpp
class Entity {
public:
    explicit Entity(int age) // Marked as explicit
        : m_Name("Unknown"), m_Age(age) {}
};

// In main or another function
// Entity b = 22; // This would now fail

// You must call the constructor explicitly:
Entity b = Entity(22);
```

Using `explicit` can prevent unintended behavior, especially in larger projects like the ones you're aiming to build. For instance, in a math library, it can prevent accidental conversions between different types, like numbers and vectors \[[06:19](http://www.youtube.com/watch?v=Rr1NX1lH3oE&t=379)\].
