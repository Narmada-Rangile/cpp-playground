### What are Header Files?

In C++, **header files** are used to **declare** functions, classes, and other types \[[00:45](http://www.youtube.com/watch?v=9RJTQmK0YPI&t=45)\]. They act as a central place to put these declarations so that they can be shared across multiple `.cpp` files \[[01:51](http://www.youtube.com/watch?v=9RJTQmK0YPI&t=111)\]. This is important because a function can only be **defined** (have its actual code written) once in a project \[[01:57](http://www.youtube.com/watch?v=9RJTQmK0YPI&t=117)\].

-----

### Declarations vs. Definitions

  - A **declaration** tells the compiler that something exists, but doesn't provide the implementation.
    ```cpp
    // This is a declaration of the Log function
    void Log(const char* message);
    ```
    \[[03:35](http://www.youtube.com/watch?v=9RJTQmK0YPI&t=215)\]
  - A **definition** is the actual implementation of the function.
    ```cpp
    // This is the definition of the Log function
    void Log(const char* message) {
        // Function's code goes here
    }
    ```
    \[[03:40](http://www.youtube.com/watch?v=9RJTQmK0YPI&t=220)\]

-----

### How Header Files Work

The `#include` directive literally copies and pastes the content of the header file into your `.cpp` file \[[04:46](http://www.youtube.com/watch?v=9RJTQmK0YPI&t=286)\]. This is how your `.cpp` files learn about the functions and types declared in the header.

**Example:**

1.  Create a header file, `Log.h`, with your function declarations.

    ```cpp
    // Log.h
    #pragma once // Header guard

    void InitLog();
    void Log(const char* message);
    ```

    \[[05:17](http://www.youtube.com/watch?v=9RJTQmK0YPI&t=317)\]

2.  Create a `.cpp` file, `Log.cpp`, with the function definitions.

    ```cpp
    // Log.cpp
    #include "Log.h"
    #include <iostream>

    void InitLog() {
        // ...
    }

    void Log(const char* message) {
        std::cout << message << std::endl;
    }
    ```

    \[[05:59](http://www.youtube.com/watch?v=9RJTQmK0YPI&t=359)\]

3.  Include `Log.h` in any other `.cpp` file where you want to use these functions.

    ```cpp
    // main.cpp
    #include "Log.h"

    int main() {
        InitLog();
        Log("Hello, World!");
        return 0;
    }
    ```

-----

### Header Guards

**Header guards** prevent a header file from being included multiple times in the same `.cpp` file, which can cause errors \[[07:36](http://www.youtube.com/watch?v=9RJTQmK0YPI&t=456)\].

  - **`#pragma once`**: This is the modern and recommended way to create a header guard \[[07:11](http://www.youtube.com/watch?v=9RJTQmK0YPI&t=431)\].
  - **`#ifndef` / `#define` / `#endif`**: This is the traditional method \[[09:49](http://www.youtube.com/watch?v=9RJTQmK0YPI&t=589)\].
    ```cpp
    #ifndef LOG_H
    #define LOG_H

    // ... header content ...

    #endif
    ```

-----

### Include Syntax: `""` vs. `<>`

  - **`"file.h"`**: Use quotes for your own header files. The compiler looks for these files relative to the current file's directory \[[12:19](http://www.youtube.com/watch?v=9RJTQmK0YPI&t=739)\].
  - **`<file.h>`**: Use angle brackets for standard library headers (like `<iostream>`). The compiler looks for these in its system include paths \[[12:07](http://www.youtube.com/watch?v=9RJTQmK0YPI&t=727)\].
