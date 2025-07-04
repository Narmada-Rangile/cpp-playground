### Destructors in C++

This video explains what **destructors** are in C++ and how they are used for cleaning up resources.

-----

### What is a Destructor? \[[00:09](http://www.youtube.com/watch?v=D8cWquReFqw&t=9)\]

A **destructor** is a special method that gets called automatically when an object is destroyed. Its main purpose is to "uninitialize" anything that was set up in the constructor or to clean up any memory that the object was using.

-----

### When are Destructors Called? \[[00:30](http://www.youtube.com/watch?v=D8cWquReFqw&t=30)\]

Destructors are called for both stack-allocated and heap-allocated objects:

  * For objects created on the **heap** (using `new`), the destructor is called when you use the `delete` keyword \[[00:36](http://www.youtube.com/watch?v=D8cWquReFqw&t=36)\].
  * For objects created on the **stack**, the destructor is called automatically when the object goes out of scope \[[00:41](http://www.youtube.com/watch?v=D8cWquReFqw&t=41)\].

-----

### How to Declare a Destructor \[[00:50](http://www.youtube.com/watch?v=D8cWquReFqw&t=50)\]

A destructor is declared with a tilde (`~`) followed by the class name. It doesn't take any arguments and doesn't have a return type.

#### Code Example:

```cpp
#include <iostream>

class Entity {
public:
    float X, Y;

    Entity() {
        X = 0.0f;
        Y = 0.0f;
        std::cout << "Created Entity!" << std::endl;
    }

    // This is the destructor
    ~Entity() {
        std::cout << "Destroyed Entity!" << std::endl;
    }
};
```

-----

### Destructor in Action \[[01:51](http://www.youtube.com/watch?v=D8cWquReFqw&t=111)\]

The video shows how a "Destroyed Entity\!" message is printed to the console when a stack-allocated object goes out of scope, demonstrating that the destructor is called automatically.

-----

### Real-World Use Cases \[[03:00](http://www.youtube.com/watch?v=D8cWquReFqw&t=180)\]

Destructors are crucial for preventing **memory leaks**, especially when you're working with memory allocated on the heap. If you allocate memory in the constructor or at any other point during the object's life, you should deallocate it in the destructor to free up those resources.

-----

### Manual Destructor Calls \[[03:33](http://www.youtube.com/watch?v=D8cWquReFqw&t=213)\]

While it's possible to call a destructor manually, it's generally not recommended. The video shows an example of this but warns that it can lead to the destructor being called multiple times if you're not careful, which can cause problems.
