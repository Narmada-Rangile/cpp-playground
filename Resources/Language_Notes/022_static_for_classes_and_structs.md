### The `static` Keyword in C++

This video explains how the `static` keyword works when you use it inside a class or a struct in C++ \[[00:10](http://www.youtube.com/watch?v=V-BFlMrBtqQ&t=10)\].

-----

### Static Variables in Classes 📚

A **static variable** in a class is shared across all instances of that class. This means there's only one copy of that variable, no matter how many objects of the class you create \[[00:31](http://www.youtube.com/watch?v=V-BFlMrBtqQ&t=31)\]. If you change the static variable from one object, the change will be visible to all other objects of that class \[[00:54](http://www.youtube.com/watch?v=V-BFlMrBtqQ&t=54)\].

It's better to access static variables using the class name itself (e.g., `Entity::x`) instead of through an object (e.g., `e.x`), because they don't belong to any single instance \[[04:01](http://www.youtube.com/watch?v=V-BFlMrBtqQ&t=241)\]. This is great for when you need to share data between all objects of a class or just to keep your code organized by grouping related variables within a class scope instead of making them global \[[05:11](http://www.youtube.com/watch?v=V-BFlMrBtqQ&t=311)\].

#### Code Example:

```cpp
#include <iostream>

struct Entity {
    static int x, y;

    void Print() {
        std::cout << x << ", " << y << std::endl;
    }
};

// Define and initialize the static variables outside the class
int Entity::x = 0;
int Entity::y = 0;

int main() {
    Entity e1;
    Entity::x = 2;
    Entity::y = 3;

    Entity e2;
    Entity::x = 5;
    Entity::y = 8;

    e1.Print(); // Outputs: 5, 8
    e2.Print(); // Outputs: 5, 8
}
```

In the example above, even though we create two different `Entity` objects, `e1` and `e2`, they both share the same `x` and `y` variables. When we change `Entity::x` and `Entity::y`, the changes are reflected in both instances \[[03:22](http://www.youtube.com/watch?v=V-BFlMrBtqQ&t=202)\].

-----

### Static Methods in Classes 🛠️

A **static method** can be called directly using the class name, without needing to create an object of the class first \[[01:12](http://www.youtube.com/watch?v=V-BFlMrBtqQ&t=72)\].

The most important thing to remember about static methods is that they **cannot access non-static member variables or methods** of the class \[[06:06](http://www.youtube.com/watch?v=V-BFlMrBtqQ&t=366)\]. This is because non-static methods get a hidden `this` pointer that points to the current object instance, but static methods don't have a `this` pointer because they aren't tied to any specific object \[[07:01](http://www.youtube.com/watch?v=V-BFlMrBtqQ&t=421)\].

#### Code Example:

```cpp
#include <iostream>

struct Entity {
    static int x, y;
    int non_static_var = 10;

    static void Print() {
        // This is OK because x and y are static
        std::cout << x << ", " << y << std::endl;

        // This would cause a compiler error because a static method
        // cannot access a non-static member.
        // std::cout << non_static_var << std::endl;
    }
};

int Entity::x = 0;
int Entity::y = 0;

int main() {
    // You can call the static method without creating an Entity object
    Entity::Print(); // Outputs: 0, 0

    Entity::x = 5;
    Entity::y = 8;

    Entity::Print(); // Outputs: 5, 8
}
```

The video shows how making the `Print` method static allows it to be called on the class itself and how it can only access the static variables `x` and `y` \[[05:38](http://www.youtube.com/watch?v=V-BFlMrBtqQ&t=338)\]. Trying to access a non-static member would result in an error \[[06:42](http://www.youtube.com/watch?v=V-BFlMrBtqQ&t=402)\].

The video ends by mentioning that this concept will be used to build a `Log` class in a future video \[[08:11](http://www.youtube.com/watch?v=V-BFlMrBtqQ&t=491)\].
