The video explains the `mutable` keyword in C++, which means something is "liable to change." It has two main uses:

-----

### With `const` Class Methods

  * The most common use of `mutable` is with class members inside `const` methods \[[03:32](http://www.youtube.com/watch?v=bP9z3H3cVMY&t=212)\].
  * A `const` method normally can't change any class members \[[01:36](http://www.youtube.com/watch?v=bP9z3H3cVMY&t=96)\]. However, if a member is declared `mutable`, a `const` method can change that specific member \[[03:14](http://www.youtube.com/watch?v=bP9z3H3cVMY&t=194)\].
  * **Example**:
    ```cpp
    class Entity
    {
    private:
        std::string m_Name;
        mutable int m_DebugCount = 0; // Declared as mutable
    public:
        const std::string& GetName() const // Const method
        {
            m_DebugCount++; // This is allowed because m_DebugCount is mutable
            return m_Name;
        }
    };
    ```
  * This lets a method stay `const` (meaning it doesn't change the object's main state) while still allowing small, non-essential changes, like for debugging \[[02:09](http://www.youtube.com/watch?v=bP9z3H3cVMY&t=129)\].

-----

### With Lambdas

  * When a variable is captured by value in a lambda (like `[x]` or `[=]`), you can't change it inside the lambda by default \[[04:47](http://www.youtube.com/watch?v=bP9z3H3cVMY&t=287)\].
  * Adding the `mutable` keyword after the lambda's capture list lets you change variables captured by value inside the lambda \[[05:19](http://www.youtube.com/watch?v=bP9z3H3cVMY&t=319)\].
  * **Example**:
    ```cpp
    int x = 8;
    auto f = [x]() mutable // mutable keyword allows modification of captured 'x'
    {
        x++; // This is now allowed
        // ...
    };
    f();
    // After calling f(), the 'x' outside the lambda will still be 8,
    // because the change only affects the local copy inside the lambda.
    ```
  * The presenter mentions that using `mutable` with lambdas is not very common \[[06:04](http://www.youtube.com/watch?v=bP9z3H3cVMY&t=364)\].
