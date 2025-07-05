### Key Concepts:

  * **What is `this`?** The `this` keyword in C++ is a pointer that holds the memory address of the current object instance a method belongs to \[[00:07](http://www.youtube.com/watch?v=Z_hPJ_EhceI&t=7), [00:19](http://www.youtube.com/watch?v=Z_hPJ_EhceI&t=19)\].
  * **When to use `this`**: It's mainly used to refer to the current object's members inside a class method. This is especially handy when you have naming conflicts, like when a member variable and a function parameter have the same name \[[01:30](http://www.youtube.com/watch?v=Z_hPJ_EhceI&t=90)\].
  * **Where can you use `this`?**: You can only use the `this` keyword inside non-static member functions of a class \[[00:13](http://www.youtube.com/watch?v=Z_hPJ_EhceI&t=13)\].
  * **The type of `this`**:
      * In a regular (non-`const`) member function, `this` is a pointer to the object (`Entity*`) \[[01:45](http://www.youtube.com/watch?v=Z_hPJ_EhceI&t=105)\].
      * In a `const` member function, `this` is a pointer to a constant object (`const Entity*`). This means you can't use `this` to change the object's member variables \[[03:06](http://www.youtube.com/watch?v=Z_hPJ_EhceI&t=186)\].
  * **Accessing members with `this`**: Since `this` is a pointer, you use the arrow operator (`->`) to access the object's members (e.g., `this->x`) \[[02:39](http://www.youtube.com/watch?v=Z_hPJ_EhceI&t=159)\]. You could also write it as `(*this).x`, but the arrow operator is the standard and cleaner way to do it \[[02:44](http://www.youtube.com/watch?v=Z_hPJ_EhceI&t=164)\].
  * **Passing the current object**: You can use `this` to pass the current object instance to another function that needs an object of that class as an argument \[[04:13](http://www.youtube.com/watch?v=Z_hPJ_EhceI&t=253)\].
  * **A word of caution on `delete this`**: While you *can* call `delete this` inside a member function to free the object's memory, it's generally a bad idea. If you try to access any member data after doing this, you'll run into issues because the memory has already been freed \[[04:44](http://www.youtube.com/watch?v=Z_hPJ_EhceI&t=284)\].

-----

### Code Examples:

**1. Fixing Naming Conflicts in a Constructor** \[[01:25](http://www.youtube.com/watch?v=Z_hPJ_EhceI&t=85)\]

Here's how you can use `this` to distinguish between a class's member variables and the constructor's parameters when they have the same name.

```cpp
class Entity {
public:
    int X, Y;

    Entity(int x, int y) {
        // 'this->X' refers to the member variable X,
        // while 'x' refers to the parameter.
        this->X = x;
        this->Y = y;
    }
};
```

**2. Passing the Current Object to an External Function** \[[04:09](http://www.youtube.com/watch?v=Z_hPJ_EhceI&t=249)\]

If you need to pass the object you're currently in to another function, you can dereference the `this` pointer.

```cpp
// An external function that takes an Entity object
void PrintEntity(const Entity& entity);

class Entity {
public:
    int X, Y;

    Entity(int x, int y) {
        this->X = x;
        this->Y = y;
    }

    void Print() {
        // Pass the current object (*this) to the function
        PrintEntity(*this);
    }
};

// The definition of the external function
void PrintEntity(const Entity& entity) {
    // Now you can work with the entity's data
}
```
