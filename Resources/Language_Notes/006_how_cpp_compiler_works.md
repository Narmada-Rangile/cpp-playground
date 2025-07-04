### Compiler and Linker

The C++ compilation process consists of two main operations: **compiling** and **linking** \[[00:30](http://www.youtube.com/watch?v=3tIqpEmWMLI&t=30)\]. The compiler's primary role is to take your C++ text files and convert them into an intermediate format called **object files** (`.obj`) \[[00:44](http://www.youtube.com/watch?v=3tIqpEmWMLI&t=44)\]. These object files are then passed to a linker to produce the final executable.

-----

### Compilation Stages

The compilation process itself is divided into several stages:

1.  **Pre-processing**: This is the initial stage where the compiler evaluates pre-processor statements, such as `#include`, `#define`, and `#if` \[[01:03](http://www.youtube.com/watch?v=3tIqpEmWMLI&t=63)\].
      * `#include`: This directive copies the content of the specified file and pastes it into the current file \[[06:29](http://www.youtube.com/watch?v=3tIqpEmWMLI&t=389)\].
        ```cpp
        // For example, if "end_brace.h" contains just a "}",
        // including it will paste the brace into this file.
        #include "end_brace.h" 
        ```
      * `#define`: This performs a simple search and replace operation \[[08:51](http://www.youtube.com/watch?v=3tIqpEmWMLI&t=531)\].
        ```cpp
        #define INTEGER int

        // The pre-processor will change this to "int main()"
        INTEGER main() 
        {
            return 0;
        }
        ```
      * `#if`: This allows for conditional compilation. Code within an `#if` block is only included if the condition is true \[[09:36](http://www.youtube.com/watch?v=3tIqpEmWMLI&t=576)\].
        ```cpp
        #if 1 // This code will be included
            // ...
        #endif

        #if 0 // This code will be excluded
            // ...
        #endif
        ```
2.  **Tokenizing and Parsing**: After pre-processing, the code is broken down into tokens and parsed to create an **Abstract Syntax Tree (AST)**, which is a tree representation of your code's structure \[[01:13](http://www.youtube.com/watch?v=3tIqpEmWMLI&t=73)\].
3.  **Code Generation**: The compiler then uses the AST to generate the **machine code** that your CPU can execute \[[01:43](http://www.youtube.com/watch?v=3tIqpEmWMLI&t=103)\].

-----

### Object Files and Translation Units

  - Each C++ source file (`.cpp`) that is compiled produces an **object file** (`.obj`) \[[02:40](http://www.youtube.com/watch?v=3tIqpEmWMLI&t=160)\]. These files contain binary machine code and are not meant to be human-readable \[[11:28](http://www.youtube.com/watch?v=3tIqpEmWMLI&t=688)\].
  - A **translation unit** is any C++ file that is fed to the compiler to be compiled, resulting in an object file \[[02:53](http://www.youtube.com/watch?v=3tIqpEmWMLI&t=173), [04:07](http://www.youtube.com/watch?v=3tIqpEmWMLI&t=247)\].

-----

### Compiler Optimizations

Compilers can perform various optimizations to improve your code's performance.

  - **Constant Folding**: The compiler evaluates constant expressions at compile time rather than at runtime. For example, `5 * 2` will be replaced with `10` in the compiled code \[[14:57](http://www.youtube.com/watch?v=3tIqpEmWMLI&t=897)\].
  - **Dead Code Elimination**: If a piece of code has no effect on the program's output, the compiler can remove it entirely. For instance, if you call a function but don't use its return value, the compiler might remove the function call during optimization \[[16:39](http://www.youtube.com/watch?v=3tIqpEmWMLI&t=999)\].
