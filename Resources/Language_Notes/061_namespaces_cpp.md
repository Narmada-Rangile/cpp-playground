### **The Problem of Naming Conflicts** \[[01:13:00](http://www.youtube.com/watch?v=ts1Eek5w7ZA&t=4380)\]

In C++, you can't have two functions with the exact same name and parameters. This is called a **naming conflict** and will cause a compilation error. In C, which doesn't have namespaces, programmers often add a prefix to their function names to avoid these conflicts.

### **What are Namespaces?** \[[04:12:00](http://www.youtube.com/watch?v=ts1Eek5w7ZA&t=15120)\]

Namespaces are a feature in C++ that allow you to group your code under a specific name. This helps to avoid naming conflicts, especially when you are using multiple libraries in your project.

### **How to Declare a Namespace** \[[04:39:00](http://www.youtube.com/watch?v=ts1Eek5w7ZA&t=16740)\]

You can declare a namespace using the `namespace` keyword, like this:

```cpp
namespace Apple {
    void print(const char* message) {
        // ...
    }
}
```

### **Accessing Members of a Namespace** \[[05:56:00](http://www.youtube.com/watch?v=ts1Eek5w7ZA&t=21360)\]

To use a function or variable from a namespace, you need to use the **scope resolution operator** (`::`).

```cpp
Apple::print("Hello from Apple");
```

### **The `using namespace` Directive** \[[07:03:00](http://www.youtube.com/watch?v=ts1Eek5w7ZA&t=25380)\]

The `using namespace` directive allows you to import all the members of a namespace into the current scope. This means you don't have to use the scope resolution operator every time.

```cpp
using namespace Apple;
print("Hello from Apple");
```

### **The `using` Declaration** \[[07:56:00](http://www.youtube.com/watch?v=ts1Eek5w7ZA&t=28560)\]

If you only need to use a few members from a namespace, you can use a `using` declaration.

```cpp
using Apple::print;
print("Hello from Apple");
```

### **Namespace Aliases** \[[08:12:00](http://www.youtube.com/watch?v=ts1Eek5w7ZA&t=29520)\]

You can create a shorter alias for a namespace, which is useful for long or nested namespace names.

```cpp
namespace A = Apple;
A::print("Hello from Apple via alias");
```

### **Nested Namespaces** \[[08:28:00](http://www.youtube.com/watch?v=ts1Eek5w7ZA&t=30480)\]

You can also have namespaces inside of other namespaces.

```cpp
namespace Apple {
    namespace Functions {
        void print(const char* message) {
            // ...
        }
    }
}
```

To access the `print` function, you would use:

```cpp
Apple::Functions::print("Nested print");
```

Since C++17, you can declare nested namespaces more concisely:

```cpp
namespace Apple::Functions {
    void print(const char* message) {
        // ...
    }
}
```

### **Best Practices** \[[09:35:00](http://www.youtube.com/watch?v=ts1Eek5w7ZA&t=34500)\]

  * It's best to limit the scope of `using namespace` directives and aliases to the smallest possible area, like inside a function.
  * **Never** use `using namespace` in a header file \[[01:10:17](http://www.youtube.com/watch?v=ts1Eek5w7ZA&t=4217)\]. This can cause naming conflicts in any file that includes that header.
  * It is a good practice to wrap your own code in a namespace to avoid conflicts with other libraries \[[01:13:36](http://www.youtube.com/watch?v=ts1Eek5w7ZA&t=4416)\].
