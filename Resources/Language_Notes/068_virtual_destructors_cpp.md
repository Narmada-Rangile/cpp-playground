## Virtual Destructors in C++

This video explains the concept of virtual destructors in C++ and their importance in polymorphism.

### What is a Virtual Destructor?

  * A **virtual destructor** is a combination of a destructor and a virtual function \[[00:14](http://www.youtube.com/watch?v=jELbKhGkEi0&t=14)\].
  * They are crucial when dealing with **polymorphism**, especially when a derived class object is referenced by a base class pointer and then deleted \[[00:23](http://www.youtube.com/watch?v=jELbKhGkEi0&t=23)\].
  * The primary purpose is to ensure that when a derived class object, treated as a base class type, is deleted, both the derived class's destructor and the base class's destructor are called \[[00:53](http://www.youtube.com/watch?v=jELbKhGkEi0&t=53)\].

-----

### Scenario without Virtual Destructors (Problem)

  * When a `Derived` object is created and assigned to a `Base` pointer (polymorphic type), and then `delete` is called on the `Base` pointer, only the `Base` class destructor is invoked \[[03:30](http://www.youtube.com/watch?v=jELbKhGkEi0&t=210)\].

  * This leads to a **memory leak** if the `Derived` class has heap-allocated members that are cleaned up in its destructor, as the `Derived` destructor is never called \[[04:06](http://www.youtube.com/watch?v=jELbKhGkEi0&t=246)\].

  * **Code Example (Problematic Scenario):**

    ```cpp
    // Base class
    class Base {
    public:
        Base() {
            // Constructor logic
        }
        ~Base() { // Not virtual
            // Destructor logic
        }
    };

    // Derived class
    class Derived : public Base {
    public:
        int* array; // Heap-allocated member
        Derived() {
            array = new int; // Allocate memory
            // Constructor logic
        }
        ~Derived() {
            delete[] array; // Deallocate memory
            // Destructor logic
        }
    };

    // In main or a function:
    Base* poly = new Derived(); // Polymorphic assignment
    delete poly; // Only Base destructor is called, leading to memory leak for 'array'
    ```

    \[[03:30](http://www.youtube.com/watch?v=jELbKhGkEi0&t=210)\], \[[05:12](http://www.youtube.com/watch?v=jELbKhGkEi0&t=312)\]

-----

### Solution: Declaring Virtual Destructors

  * To fix the memory leak and ensure proper cleanup, the base class destructor must be declared as `virtual` \[[05:53](http://www.youtube.com/watch?v=jELbKhGkEi0&t=353)\].

  * Marking the base destructor as `virtual` tells the compiler that there's a possibility for the class to be subclassed and that derived destructors might also need to be called \[[06:05](http://www.youtube.com/watch?v=jELbKhGkEi0&t=365)\].

  * When a destructor is virtual, deleting a base class pointer to a derived object will correctly call the derived class's destructor first, and then the base class's destructor \[[04:57](http://www.youtube.com/watch?v=jELbKhGkEi0&t=297)\].

  * **Code Example (Solution):**

    ```cpp
    // Base class
    class Base {
    public:
        Base() {
            // Constructor logic
        }
        virtual ~Base() { // Marked as virtual
            // Destructor logic
        }
    };

    // Derived class (no change needed here for virtual behavior)
    class Derived : public Base {
    public:
        int* array;
        Derived() {
            array = new int;
            // Constructor logic
        }
        ~Derived() {
            delete[] array;
            // Destructor logic
        }
    };

    // In main or a function:
    Base* poly = new Derived();
    delete poly; // Both Derived and Base destructors are called correctly
    ```

    \[[05:53](http://www.youtube.com/watch?v=jELbKhGkEi0&t=353)\], \[[06:17](http://www.youtube.com/watch?v=jELbKhGkEi0&t=377)\]

-----

### Key Takeaway

  * Whenever you permit a class to be subclassed (i.e., it's intended to be a base class), you **must** declare its destructor as `virtual` \[[06:47](http://www.youtube.com/watch?v=jELbKhGkEi0&t=407)\].
  * Failing to do so will prevent derived class destructors from being called when objects are deleted through a base class pointer, leading to memory leaks and undefined behavior \[[06:55](http://www.youtube.com/watch?v=jELbKhGkEi0&t=415)\].
