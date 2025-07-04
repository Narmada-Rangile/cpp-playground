### **What are Loops?** 🔄

Loops are control structures that allow you to execute a block of code multiple times \[[00:11](http://www.youtube.com/watch?v=_1AwR-un4Hk&t=11)\]. They are essential for automating repetitive tasks. For example, instead of writing the same line of code five times to print "Hello World," you can use a loop \[[01:16](http://www.youtube.com/watch?v=_1AwR-un4Hk&t=76)\]. A core concept in game development and simulations is the "game loop," which continuously updates the screen and game logic until the user quits \[[01:00](http://www.youtube.com/watch?v=_1AwR-un4Hk&t=60)\].

-----

### **The `for` Loop**

The `for` loop is ideal when you know in advance how many times you want to execute the loop.

**Syntax:**
It consists of three parts: `for (initialization; condition; increment/decrement)` \[[01:53](http://www.youtube.com/watch?v=_1AwR-un4Hk&t=113)\].

1.  **Initialization**: Executed once at the beginning to declare and initialize a loop control variable (e.g., `int i = 0;`) \[[02:06](http://www.youtube.com/watch?v=_1AwR-un4Hk&t=126)\].
2.  **Condition**: Evaluated before each iteration. The loop continues as long as this is true \[[02:34](http://www.youtube.com/watch?v=_1AwR-un4Hk&t=154)\].
3.  **Increment/Decrement**: Executed at the end of each iteration to update the control variable (e.g., `i++`) \[[02:57](http://www.youtube.com/watch?v=_1AwR-un4Hk&t=177)\].

**Code Example:**
Here's how to print "Hello World" five times. You could adapt this to draw five shapes in a row for a sketch or animation.

```cpp
#include <iostream>

int main() {
    for (int i = 0; i < 5; i++) {
        std::cout << "Hello World" << std::endl;
    }
    return 0;
}
```

*\[[03:39](http://www.youtube.com/watch?v=_1AwR-un4Hk&t=219)\]*

-----

### **The `while` Loop**

A `while` loop is used when the number of iterations is not known beforehand. The loop continues as long as a condition is true \[[07:35](http://www.youtube.com/watch?v=_1AwR-un4Hk&t=455)\]. This is perfect for a game loop that runs while a `gameIsRunning` variable is true.

**Code Example:**
This `while` loop performs the same task as the `for` loop above.

```cpp
#include <iostream>

int main() {
    int i = 0;
    while (i < 5) {
        std::cout << "Hello World" << std::endl;
        i++;
    }
    return 0;
}
```

*\[[07:50](http://www.youtube.com/watch?v=_1AwR-un4Hk&t=470)\]*

-----

### **The `do-while` Loop**

The `do-while` loop is less common, but its key feature is that the loop body is **guaranteed to execute at least once** because the condition is checked *after* the first iteration \[[10:29](http://www.youtube.com/watch?v=_1AwR-un4Hk&t=629)\].

**Code Example:**

```cpp
#include <iostream>

int main() {
    int i = 0;
    do {
        std::cout << "Hello World" << std::endl;
        i++;
    } while (i < 5);
    return 0;
}
```

*\[[10:15](http://www.youtube.com/watch?v=_1AwR-un4Hk&t=615)\]*
