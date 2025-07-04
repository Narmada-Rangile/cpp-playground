### What are Functions?

Functions are blocks of code that perform a specific task \[[00:34](http://www.youtube.com/watch?v=V9zuox47zr0&t=34)\]. They are essential for writing clean and maintainable code because they help you **avoid duplicating code** \[[00:46](http://www.youtube.com/watch?v=V9zuox47zr0&t=46)\]. Instead of copying and pasting the same logic, you can write a function once and call it multiple times \[[01:06](http://www.youtube.com/watch?v=V9zuox47zr0&t=66)\].

-----

### Function Structure

A function has a few key parts:

  - **Return Type**: The type of data the function sends back. If a function doesn't return anything, its return type is `void` \[[01:30](http://www.youtube.com/watch?v=V9zuox47zr0&t=90), [02:12](http://www.youtube.com/watch?v=V9zuox47zr0&t=132)\].
  - **Function Name**: The name you give to the function \[[01:40](http://www.youtube.com/watch?v=V9zuox47zr0&t=100)\].
  - **Parameters**: The input values the function receives \[[01:45](http://www.youtube.com/watch?v=V9zuox47zr0&t=105)\].
  - **Function Body**: The code inside the curly braces `{}` that performs the task \[[01:50](http://www.youtube.com/watch?v=V9zuox47zr0&t=110)\].
  - **`return` statement**: Sends a value back from the function \[[01:50](http://www.youtube.com/watch?v=V9zuox47zr0&t=110)\].

<!-- end list -->

```cpp
//  return_type function_name(parameter1, parameter2) {
//      // code to be executed
//      return value;
//  }

int multiply(int a, int b) {
    return a * b;
}
```

-----

### Calling a Function

To use a function, you "call" it by its name and provide the necessary arguments.

```cpp
int result = multiply(5, 10); // Calls the multiply function
// result will be 50
```

\[[02:36](http://www.youtube.com/watch?v=V9zuox47zr0&t=156), [02:40](http://www.youtube.com/watch?v=V9zuox47zr0&t=160)\]

-----

### `void` Functions

If a function doesn't need to return a value, you can use the `void` return type.

```cpp
#include <iostream>

void printMessage(const char* message) {
    std::cout << message << std::endl;
}

int main() {
    printMessage("Hello from a function!");
    return 0;
}
```

\[[04:27](http://www.youtube.com/watch?v=V9zuox47zr0&t=267)\]

-----

### Key Takeaways

  - The main reason to use functions is to **avoid repeating yourself**.
  - Don't create functions for every single line of code, as this can make your code harder to read and slightly slower \[[05:53](http://www.youtube.com/watch?v=V9zuox47zr0&t=353)\].
  - The `main` function is a special case and doesn't always need a `return` statement in modern C++ \[[07:47](http://www.youtube.com/watch?v=V9zuox47zr0&t=467)\].
  - It's common practice to separate function **declarations** (in header files) from their **definitions** (in `.cpp` files) \[[09:00](http://www.youtube.com/watch?v=V9zuox47zr0&t=540)\].
