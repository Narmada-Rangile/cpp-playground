### Enums in C++

This video introduces **enums** (enumerations) in C++, explaining what they are, why they're useful, and how to use them effectively.

-----

### What are Enums? \[[00:04](http://www.youtube.com/watch?v=x55jfOd5PEE&t=4)\]

An **enum** is a way to create a set of named values. Think of it as giving descriptive names to integer values. This makes your code much more readable and organized because you can use these names instead of "magic numbers."

-----

### Enums are Integers \[[00:49](http://www.youtube.com/watch?v=x55jfOd5PEE&t=49)\]

At their core, enums are just integers. This means you can compare them with integer values. By default, the first value in an enum is `0`, and the following values increment by one.

#### Code Example:

```cpp
#include <iostream>

// By default, A=0, B=1, C=2
enum Example {
    A, B, C
};

int main() {
    Example value = B;

    if (value == 1) {
        std::cout << "The value is B!" << std::endl;
    }
}
```

-----

### Assigning Custom Values \[[02:34](http://www.youtube.com/watch?v=x55jfOd5PEE&t=154)\]

You can also assign your own integer values to enum members. If you assign a value to one member, the next members will increment from that value unless you explicitly set them.

#### Code Example:

```cpp
// Here, A=5, B=6, C=7
enum Example {
    A = 5, B, C
};
```

-----

### Specifying the Underlying Type \[[03:00](http://www.youtube.com/watch?v=x55jfOd5PEE&t=180)\]

By default, enums are 32-bit integers. However, you can specify a different underlying integer type, like `unsigned char`, to save memory if your enum values are small. This is a great optimization for projects where memory is a concern.

#### Code Example:

```cpp
// This enum will use unsigned characters (1 byte) instead of 4-byte integers
enum Example : unsigned char {
    A, B, C
};
```

-----

### Practical Example with a Log Class \[[03:40](http://www.youtube.com/watch?v=x55jfOd5PEE&t=220)\]

The video demonstrates how to refactor a `Log` class to use an enum for different log levels (Error, Warning, Info) instead of using raw integers. This makes the code much cleaner and prevents you from accidentally using an invalid log level. This is a perfect example of how you can use enums in your own open-source projects\!

#### Code Example:

```cpp
class Log {
public:
    enum Level {
        LevelError, LevelWarning, LevelInfo
    };

private:
    Level m_LogLevel = LevelInfo;

public:
    void SetLevel(Level level) {
        m_LogLevel = level;
    }
    // ... other logging functions
};
```

-----

### Naming Conflicts \[[06:11](http://www.youtube.com/watch?v=x55jfOd5PEE&t=371)\]

A potential issue is that an enum member's name can conflict with a function or variable name in the same scope. A common way to avoid this is to add a prefix to your enum member names, like `LevelError` or `LevelWarning`.

-----

### Benefits of Enums \[[07:00](http://www.youtube.com/watch?v=x55jfOd5PEE&t=420)\]

Enums make your code cleaner and easier to understand by replacing "magic numbers" with descriptive names. They are incredibly useful whenever you have a set of related values that you want to represent numerically.
