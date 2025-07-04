### What is Inheritance?

  * Inheritance allows you to create a hierarchy of classes. A **base class** contains common functionality, and **sub-classes** can branch off from it, inheriting the base class's features \[[00:17](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=17)\].
  * This is a great way to **avoid code duplication**. You can put common functionality into a parent class, and then sub-classes can extend it or introduce new, more specialized functionality \[[00:33](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=33)\].

-----

### Defining Inheritance in C++

To make a class a sub-class of another, you use a colon (`:`) after the class name, followed by the `public` keyword and the name of the base class \[[02:47](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=167)\].

```cpp
class Player : public Entity 
{
    // Player-specific members
};
```

-----

### Effects of Inheritance

  * A sub-class (e.g., `Player`) is also of the type of its base class (e.g., `Entity`). This means a `Player` object is both a `Player` and an `Entity` \[[02:57](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=177)\].
  * The sub-class inherits all the members (variables and functions) of the base class \[[03:20](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=200)\].
  * Any non-private members of the base class are accessible by the sub-class \[[04:00](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=240)\].

-----

### Code Duplication Example and Solution

**Problem:** Without inheritance, if you have two classes like `Entity` and `Player` that both need `X` and `Y` coordinates and a `Move` function, you would have to write the same code in both classes \[[01:57](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=117)\].

```cpp
// Without Inheritance (Code Duplication)
class Entity {
public:
    float X, Y;
    void Move(float xa, float ya) {
        X += xa;
        Y += ya;
    }
};

class Player {
public:
    float X, Y; // Duplicated
    void Move(float xa, float ya) { // Duplicated
        X += xa;
        Y += ya;
    }
    const char* Name;
    void PrintName() {}
};
```

**Solution with Inheritance:** The `Player` class can inherit from the `Entity` class. This way, it gets the `X`, `Y`, and `Move` members from `Entity` and only needs to define its own unique members \[[03:41](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=221)\].

```cpp
// With Inheritance
class Entity {
public:
    float X, Y;
    void Move(float xa, float ya) {
        X += xa;
        Y += ya;
    }
};

class Player : public Entity {
public:
    const char* Name;
    void PrintName() {}
};
```

-----

### Accessing Inherited Members

An object of the sub-class can directly use the functions and variables inherited from the base class \[[04:11](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=251)\].

```cpp
Player player;
player.Move(10, 5); // Calls the inherited Move function
player.X = 20;      // Accesses the inherited X variable
player.PrintName(); // Calls its own function
```

-----

### Polymorphism (Brief Introduction)

  * **Polymorphism** is the idea of having multiple types for a single object \[[04:33](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=273)\].
  * Since a `Player` is also an `Entity`, you can use a `Player` object wherever an `Entity` object is expected \[[04:51](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=291)\]. This is possible because a sub-class is guaranteed to have all the members of its base class \[[05:34](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=334)\].

-----

### Memory Footprint of Inherited Classes

  * The size of a sub-class in memory is the size of all its inherited members from the base class, plus the size of its own members \[[06:05](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=365)\].
  * For example:
      * If `Entity` has two `float` variables, its size is 8 bytes (`sizeof(Entity)`) \[[06:16](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=376)\].
      * If `Player` inherits those two floats and adds a `const char* Name`, its size will be 12 bytes on a 32-bit system (4 bytes for each float + 4 bytes for the pointer) (`sizeof(Player)`) \[[06:30](http://www.youtube.com/watch?v=X8nYM8wdNRE&t=390)\].
