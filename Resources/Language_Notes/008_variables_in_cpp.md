### What are Variables?

Variables are used to **store data** in a program that can be changed, read, and written to \[[00:24](http://www.youtube.com/watch?v=zB9RI8_wExo&t=24)\]. They provide a way to give a name to a piece of data in memory so that you can refer to it later \[[00:35](http://www.youtube.com/watch?v=zB9RI8_wExo&t=35)\]. Variables can be stored on the stack or the heap \[[01:11](http://www.youtube.com/watch?v=zB9RI8_wExo&t=71)\].

-----

### Primitive Data Types

C++ provides several **primitive data types** for storing different kinds of data. The main difference between them is the amount of memory they use \[[02:01](http://www.youtube.com/watch?v=zB9RI8_wExo&t=121)\].

  * **`int`**: Used for storing whole numbers. It's typically 4 bytes in size \[[02:24](http://www.youtube.com/watch?v=zB9RI8_wExo&t=144)\].
    ```cpp
    int myNumber = 42; // Declares an integer and assigns it a value
    myNumber = 100;    // You can change the value later
    ```
    \[[02:30](http://www.youtube.com/watch?v=zB9RI8_wExo&t=150), [03:44](http://www.youtube.com/watch?v=zB9RI8_wExo&t=224)\]
  * **`unsigned int`**: An integer that can only store positive values, allowing for a larger maximum value \[[05:36](http://www.youtube.com/watch?v=zB9RI8_wExo&t=336)\].
    ```cpp
    unsigned int positiveNumber = 1000;
    ```
    \[[05:48](http://www.youtube.com/watch?v=zB9RI8_wExo&t=348)\]
  * **Other Integer Types**:
      * `char`: 1 byte, often used for characters \[[06:15](http://www.youtube.com/watch?v=zB9RI8_wExo&t=375)\].
      * `short`: 2 bytes \[[06:21](http://www.youtube.com/watch?v=zB9RI8_wExo&t=381)\].
      * `long`: Usually 4 bytes \[[06:24](http://www.youtube.com/watch?v=zB9RI8_wExo&t=384)\].
      * `long long`: Usually 8 bytes \[[06:27](http://www.youtube.com/watch?v=zB9RI8_wExo&t=387)\].
  * **Floating-Point Types** (for decimal values):
      * `float`: 4 bytes. Use an 'f' at the end of the number to specify that it's a float \[[08:47](http://www.youtube.com/watch?v=zB9RI8_wExo&t=527), [09:35](http://www.youtube.com/watch?v=zB9RI8_wExo&t=575)\].
        ```cpp
        float myFloat = 3.14f;
        ```
        \[[09:02](http://www.youtube.com/watch?v=zB9RI8_wExo&t=542)\]
      * `double`: 8 bytes. This is the default type for decimal numbers \[[09:19](http://www.youtube.com/watch?v=zB9RI8_wExo&t=559)\].
  * **`bool`**: Can store either `true` or `false` \[[09:53](http://www.youtube.com/watch?v=zB9RI8_wExo&t=593)\]. It takes up 1 byte of memory \[[10:33](http://www.youtube.com/watch?v=zB9RI8_wExo&t=633)\].
    ```cpp
    bool isRaining = true;
    ```
    \[[09:53](http://www.youtube.com/watch?v=zB9RI8_wExo&t=593)\]

-----

### Checking Variable Size

You can use the `sizeof` operator to find out how many bytes a data type or variable uses \[[11:35](http://www.youtube.com/watch?v=zB9RI8_wExo&t=695)\].

```cpp
#include <iostream>

int main() {
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;
    return 0;
}
```

\[[11:41](http://www.youtube.com/watch?v=zB9RI8_wExo&t=701)\]
