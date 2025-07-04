### What is Linking?

Linking is the process of taking one or more **object files**, which are the output of the compiler, and combining them to create a single **executable file** \[[00:04](http://www.youtube.com/watch?v=H4s55GgAg0I&t=4)\]. The primary job of the linker is to resolve symbols, which means it finds where each function and variable is defined and connects all the references to them across different files \[[00:26](http://www.youtube.com/watch?v=H4s55GgAg0I&t=26)\]. Even a simple "Hello, World\!" program in a single file needs a linker to set up the entry point for the program to run \[[00:52](http://www.youtube.com/watch?v=H4s55GgAg0I&t=52)\].

-----

### Compilation vs. Linking

  - **Compilation**: Translates your C++ source code (`.cpp`) into machine code, creating object files (`.obj`) \[[00:10](http://www.youtube.com/watch?v=H4s55GgAg0I&t=10)\].
  - **Linking**: Takes these object files and combines them into a single executable file \[[00:21](http://www.youtube.com/watch?v=H4s55GgAg0I&t=21)\].

You can differentiate between errors from each stage:

  - **Compiler errors** in Visual Studio often start with a 'C' (e.g., `C2143` for a syntax error) \[[02:40](http://www.youtube.com/watch?v=H4s55GgAg0I&t=160)\].
  - **Linker errors** typically start with 'LNK' (e.g., `LNK2019` for an unresolved external symbol) \[[02:57](http://www.youtube.com/watch?v=H4s55GgAg0I&t=177)\].

-----

### Common Linker Errors

#### 1\. Missing Entry Point

An executable program needs an **entry point**, which is usually the `main` function \[[03:16](http://www.youtube.com/watch?v=H4s55GgAg0I&t=196)\]. If the linker can't find this entry point, it will produce an error.

#### 2\. Unresolved External Symbol

This is a very common linker error. It happens when you declare a function or variable but never provide its definition, or the linker can't find the definition \[[05:47](http://www.youtube.com/watch?v=H4s55GgAg0I&t=347)\].

For example, if you have a function declaration in one file:

```cpp
// main.cpp
void Log(const char* message); // Declaration

int main() {
    Log("Hello, World!"); // Usage
    return 0;
}
```

But you never provide the actual code for the `Log` function in any of the files being linked, you'll get an "unresolved external symbol" error.

To fix this, you must provide the definition in one of the source files:

```cpp
// log.cpp
#include <iostream>

void Log(const char* message) { // Definition
    std::cout << message << std::endl;
}
```

#### 3\. Duplicate Symbols

This error occurs when the linker finds multiple definitions for the same function or variable \[[09:45](http://www.youtube.com/watch?v=H4s55GgAg0I&t=585)\]. This often happens when you put a function definition inside a header file and then include that header in multiple `.cpp` files \[[12:36](http://www.youtube.com/watch?v=H4s55GgAg0I&t=756)\]. Each `.cpp` file will have its own copy of the function, leading to a conflict.

**Incorrect way (defining a function in a header):**

```cpp
// log.h
#pragma once
#include <iostream>

// This will cause a duplicate symbol error if included in multiple .cpp files
void Log(const char* message) {
    std::cout << message << std::endl;
}
```

**Correct way (declaring in the header, defining in a source file):**

```cpp
// log.h
#pragma once

void Log(const char* message); // Declaration only
```

```cpp
// log.cpp
#include "log.h"
#include <iostream>

void Log(const char* message) { // Definition
    std::cout << message << std::endl;
}
```

You can also use the `static` or `inline` keywords in the header file to resolve this, but the recommended approach is to separate the declaration and definition \[[13:04](http://www.youtube.com/watch?v=H4s55GgAg0I&t=784), [13:53](http://www.youtube.com/watch?v=H4s55GgAg0I&t=833)\].
