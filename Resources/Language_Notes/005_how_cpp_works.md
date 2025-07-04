### C++ Workflow
The basic process involves writing your code in **source files** (.cpp), which are then processed by a **compiler** to create a binary file, such as an executable program \[[00:16](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=16)\].

***

### Pre-processor Statements
- Any line starting with a hash symbol (`#`) is a **pre-processor statement**, which the compiler handles before the main compilation process begins \[[00:55](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=55)\].
- A common example is `#include`. This statement finds the specified file (like `iostream`) and copies its contents into your source file \[[01:13](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=73)\]. These included files are often called **header files**.
- **Example**: Including `<iostream>` is necessary to use functions like `std::cout` for printing to the console \[[01:29](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=89)\].

***

### The `main` Function
- Every C++ application has a `main` function, which serves as the **entry point** for the program \[[01:34](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=94)\].
- Code execution starts at the beginning of the `main` function and proceeds line by line \[[01:45](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=105)\].
- It has a return type of `int`. Returning `0` indicates that the program executed successfully \[[02:24](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=144)\].

***

### Console Input/Output
- **`std::cout`** is used to print output to the console. It uses the `<<` operator to send data to the console \[[02:40](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=160)\].
- **Example**: `std::cout << "Hello World" << std::endl;` prints "Hello World" followed by a new line \[[03:24](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=204)\].
- **`std::cin.get()`** can be used to pause the program and wait for the user to press the Enter key \[[03:35](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=215)\].

***

### Compilation & Linking
The process of turning your code into an executable involves a few stages:
1.  **Pre-processing**: Handles the `#include` and other pre-processor directives \[[04:14](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=254)\].
2.  **Compilation**: Each `.cpp` source file is individually compiled into an **object file** (`.obj`) \[[08:34](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=514)\]. Header files are not compiled on their own; their contents are included in the `.cpp` files.
3.  **Linking**: The linker takes all the generated object files and "links" them together to create the final executable (`.exe`) file \[[08:53](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=533)\].

***

### Declarations vs. Definitions
- A **declaration** tells the compiler that a function or variable exists somewhere, but doesn't provide the implementation \[[15:16](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=916)\].
- A **definition** is the actual implementation or body of that function or variable \[[15:42](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=942)\].
- This distinction is crucial when you split your code into multiple files. You can declare a function in one file and use it, as long as the linker can find its definition in another file.

***

### Linker Errors
- A **linker error** occurs when the linker cannot find the definition for a symbol that has been declared \[[17:19](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=1039)\]. This is often reported as an "unresolved external symbol" error.
- **Example**: This can happen if you declare a function in your `main.cpp` but forget to provide its actual code (the definition) in any of the project's files \[[17:43](http://www.youtube.com/watch?v=SfGuIVzE_Os&t=1063)\].
