### **Important Concepts**

  * **Strings and Performance** 🚀

      * In C++, `std::string` can sometimes be slow, mainly because of **heap allocations**. \[[00:26](http://www.youtube.com/watch?v=S7oVXMzTo4w&t=26)\]
      * However, thanks to optimizations like SSO, using strings isn't always as bad as it seems. \[[00:56](http://www.youtube.com/watch?v=S7oVXMzTo4w&t=56)\]

  * **What is Small String Optimization (SSO)?** 🤔

      * SSO is a common optimization in the C++ standard library where **small strings are stored on the stack** instead of the heap. \[[04:06](http://www.youtube.com/watch?v=S7oVXMzTo4w&t=246)\]
      * This avoids the overhead of heap allocation, making operations on small strings much faster. \[[04:28](http://www.youtube.com/watch?v=S7oVXMzTo4w&t=268)\]

  * **SSO Threshold** 📏

      * The maximum length for a "small string" depends on the compiler and standard library implementation.
      * In the video's example (Visual Studio 2019), the threshold is **15 characters**. Strings with 16 or more characters will be allocated on the heap. \[[04:42](http://www.youtube.com/watch?v=S7oVXMzTo4w&t=282)\]

  * **Debug vs. Release Mode** 🐞

      * In **Debug mode**, you might see small memory allocations even for short strings. This is due to debugging features and is not a sign that SSO isn't working. \[[09:52](http://www.youtube.com/watch?v=S7oVXMzTo4w&t=592)\]
      * In **Release mode**, these debug-related allocations are gone, and you'll see the true effect of SSO. \[[11:40](http://www.youtube.com/watch?v=S7oVXMzTo4w&t=700)\]

-----

### **Code Example**

The video demonstrates how to observe SSO by overriding the global `operator new` to print a message whenever a memory allocation occurs.

```cpp
#include <iostream>
#include <string>
#include <new> // Required for operator new

// Override global operator new to track allocations
void* operator new(size_t size) {
    std::cout << "Allocating " << size << " bytes" << std::endl;
    return malloc(size); // Use malloc for the actual allocation
}

int main() {
    // This will NOT cause a heap allocation in Release mode (SSO in action)
    std::string name = "Cherno";
    std::cout << "String length: " << name.length() << std::endl;

    // This WILL cause a heap allocation because it's longer than 15 characters
    std::string largeString = "1234567890123456";
    std::cout << "Large string length: " << largeString.length() << std::endl;

    return 0;
}
```

When you run this code in **Release mode**, you'll only see the "Allocating" message for `largeString`, proving that the smaller string `name` was optimized and stored on the stack.

Since you're into C++ and performance, understanding SSO is a great example of how the standard library is designed to be efficient "under the hood." You could even try testing the SSO threshold on your own system with Kubuntu (which likely uses GCC or Clang) to see how it compares to Visual Studio\!
