The video explains the `const` keyword in C++, which is used to make things constant and unchangeable. While this can be bypassed, it's a good practice for writing clearer and more predictable code.

-----

### Declaring Constant Variables

  * When you use `const` with a variable, you can't change its value after it's been set.
  * **Example**:
    ```cpp
    const int maxAge = 90;
    ```
    \[[01:35](http://www.youtube.com/watch?v=4fJBrditnJU&t=95)\]
    This sets `maxAge` as a constant, so its value will always be 90.

-----

### `const` with Pointers

  * `const` can be used with pointers in a few different ways to control what can be changed:
      * **`const int* a`** (Constant Content) \[[03:30](http://www.youtube.com/watch?v=4fJBrditnJU&t=210)\]: The value at the memory address can't be changed, but the pointer can be pointed to something else.
        ```cpp
        const int* a = new int(5);
        // *a = 2; // This would be an error
        a = &maxAge; // This is okay
        ```
      * **`int* const a`** (Constant Pointer) \[[04:11](http://www.youtube.com/watch?v=4fJBrditnJU&t=251)\]: The pointer can't be changed, but the value it points to can be.
        ```cpp
        int* const a = new int(5);
        *a = 2; // This is okay
        // a = &maxAge; // This would be an error
        ```
      * **`const int* const a`** (Constant Content and Pointer) \[[05:24](http://www.youtube.com/watch?v=4fJBrditnJU&t=324)\]: Neither the pointer nor the value it points to can be changed.
        ```cpp
        const int* const a = new int(5);
        // *a = 2; // This would be an error
        // a = &maxAge; // This would be an error
        ```
  * **Note**: `const int* a` and `int const* a` do the same thing \[[04:22](http://www.youtube.com/watch?v=4fJBrditnJU&t=262)\]. What matters is whether `const` is before or after the `*` \[[04:43](http://www.youtube.com/watch?v=4fJBrditnJU&t=283)\].

-----

### `const` with Class Methods

  * When you add `const` to a class method, it means the method won't change any of the class's member variables \[[06:12](http://www.youtube.com/watch?v=4fJBrditnJU&t=372)\]. These are often called "read-only" methods.
  * **Example**:
    ```cpp
    class Entity {
    public:
        int x;
        int getX() const { // 'const' here
            // x = 2; // This would be an error
            return x;
        }
        void setX(int val) { // No 'const' because it changes 'x'
            x = val;
        }
    };
    ```
  * This is important when you pass objects by `const` reference, as a `const` object can only use `const` methods \[[08:55](http://www.youtube.com/watch?v=4fJBrditnJU&t=535), [10:32](http://www.youtube.com/watch?v=4fJBrditnJU&t=632)\].
  * **`mutable` Keyword** \[[11:34](http://www.youtube.com/watch?v=4fJBrditnJU&t=694)\]: If a `const` method needs to change a member variable (like for debugging), you can declare that variable as `mutable`.
  * **Example**:
    ```cpp
    class Entity {
    public:
        mutable int debugVar; // Can be changed by const methods
        int getX() const {
            debugVar = 1; // Allowed because debugVar is mutable
            return x;
        }
    };
    ```
