### Constructors in C++

This video gives an introduction to **constructors** in C++ \[[00:04](http://www.youtube.com/watch?v=FXhALMsHwEY&t=4)\], explaining what they are, why you need them, and how to use them.

-----

### What is a Constructor?

A **constructor** is a special method that gets called automatically every time you create an object of a class \[[00:10](http://www.youtube.com/watch?v=FXhALMsHwEY&t=10)\]. Its main job is to initialize the object's member variables and do any other setup that's needed \[[06:27](http://www.youtube.com/watch?v=FXhALMsHwEY&t=387)\].

-----

### The Problem with Uninitialized Memory

When you create an object, the memory for it is allocated but not automatically cleared or initialized \[[01:04](http://www.youtube.com/watch?v=FXhALMsHwEY&t=64)\]. This means your member variables will hold "seemingly random values" \[[00:57](http://www.youtube.com/watch?v=FXhALMsHwEY&t=57)\]. If you try to use a local variable that hasn't been initialized, your code might not even compile, giving you an error like "uninitialized local variable 'e' used" \[[01:36](http://www.youtube.com/watch?v=FXhALMsHwEY&t=96)\].

-----

### The Need for Initialization

The video shows that you could create an `init` method to set your variables to zero \[[02:08](http://www.youtube.com/watch?v=FXhALMsHwEY&t=128)\], but you'd have to remember to call it every single time you create an object, which isn't ideal \[[02:35](http://www.youtube.com/watch?v=FXhALMsHwEY&t=155)\]. This is where constructors come in to automate the process.

-----

### Implementing a Constructor

A constructor is a method that has the **same name as the class** and has **no return type** \[[02:57](http://www.youtube.com/watch?v=FXhALMsHwEY&t=177)\].

#### Code Example:

```cpp
class Entity {
public:
    float X, Y;

    // This is the constructor
    Entity() {
        X = 0.0f;
        Y = 0.0f;
    }
};
```

-----

### Default Constructor

If you don't create a constructor yourself, C++ provides a **default constructor** \[[03:34](http://www.youtube.com/watch?v=FXhALMsHwEY&t=214)\]. However, this default constructor is empty and **does not initialize your variables** \[[03:41](http://www.youtube.com/watch?v=FXhALMsHwEY&t=221)\]. Unlike languages like Java, C++ does not automatically initialize primitive types to zero, so you have to do it yourself \[[03:53](http://www.youtube.com/watch?v=FXhALMsHwEY&t=233)\].

-----

### Constructors with Parameters

You can create multiple constructors as long as they have different parameters (this is called **overloading**) \[[04:22](http://www.youtube.com/watch?v=FXhALMsHwEY&t=262)\]. This lets you create objects with initial values.

#### Code Example:

```cpp
class Entity {
public:
    float X, Y;

    // Default constructor
    Entity() {
        X = 0.0f;
        Y = 0.0f;
    }

    // Constructor with parameters
    Entity(float x, float y) {
        X = x;
        Y = y;
    }
};

int main() {
    Entity e1;          // Calls the default constructor, X and Y are 0
    Entity e2(10.0f, 5.0f); // Calls the parameterized constructor
}
```

-----

### When Constructors Run

A constructor runs every time an object is created \[[00:10](http://www.youtube.com/watch?v=FXhALMsHwEY&t=10)\], including when you use the `new` keyword to allocate an object on the heap \[[05:14](http://www.youtube.com/watch?v=FXhALMsHwEY&t=314)\]. Constructors will **not** run if you are only using static methods of a class without creating an instance \[[05:02](http://www.youtube.com/watch?v=FXhALMsHwEY&t=302)\].

-----

### Disabling Constructors

You can prevent a class from being instantiated by making its constructor `private` \[[05:43](http://www.youtube.com/watch?v=FXhALMsHwEY&t=343)\] or by deleting the default constructor using `= delete;` \[[05:59](http://www.youtube.com/watch?v=FXhALMsHwEY&t=359)\]. This is useful for classes that are only meant to hold static members.

#### Code Example:

```cpp
class Log {
public:
    // This prevents anyone from creating an instance of the Log class
    Log() = delete;

    static void Write(const char* message) {
        // ...
    }
};
```

-----

### Other Constructor Types

The video briefly mentions that there are other types of constructors, like **copy constructors** and **move constructors**, which are more advanced topics that will be covered in later videos \[[06:13](http://www.youtube.com/watch?v=FXhALMsHwEY&t=373)\].
