### The Problem with `std::string`

The video highlights that string operations, which are very common, can significantly impact performance due to **memory allocations**. \[[00:41](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=41)\] Many operations like formatting, logging, and creating substrings are slow because they often allocate memory on the heap. \[[02:36](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=156)\] Heap allocations are generally slower than stack allocations and should be avoided when possible. \[[02:54](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=174)\]

-----

### Demonstrating Memory Allocations

The video shows how to track memory allocations by overloading the `new` operator. \[[03:59](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=239)\]

  * **Simple String Creation:** Creating an `std::string` variable causes one heap allocation. \[[04:54](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=294)\] Even passing a string literal to a function that takes a `const std::string&` will cause an allocation because an `std::string` object needs to be created. \[[05:31](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=331)\]
  * **Using `substring`:** Using `name.substr(0, 3)` to get a part of a string creates a new `std::string` and leads to more memory allocations. \[[06:06](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=366)\] The example shows that using `substr` twice results in three total allocations (one for the original string and two for the substrings). \[[06:33](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=393)\]

-----

### The Solution: `std::string_view`

`std::string_view` (from C++17) is introduced as a way to avoid these unnecessary memory allocations. \[[08:06](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=486)\] A `string_view` is essentially a **pointer** to existing memory and a **size**, acting as a "window" into an existing string without owning or copying the data. \[[08:11](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=491)\] This makes it very lightweight to pass around. \[[09:13](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=553)\]

-----

### Refactoring with `std::string_view`

The code is then refactored to use `std::string_view` instead of `std::string`. \[[09:31](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=571)\]

**Before `string_view`:**

```cpp
std::string name = "Yann Cherno";
std::string firstName = name.substr(0, 3);
std::string lastName = name.substr(4, 9);
printName(firstName); // printName takes std::string const&
```

This results in multiple allocations.

**With `string_view`:**

```cpp
std::string name = "Yann Cherno";
std::string_view firstName(name.c_str(), 3);
std::string_view lastName(name.c_str() + 4, 9);
printName(firstName); // printName takes std::string_view
```

This significantly reduces allocations. \[[10:34](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=634)\] By changing the `printName` function to accept `std::string_view`, even passing a string literal directly results in **zero allocations**. \[[11:54](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=714)\]

-----

### Achieving Zero Allocations

The video demonstrates how to achieve zero allocations by using a C-style string (`const char*`) for the original name and then creating `std::string_view` objects from it. \[[11:00](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=660)\]

**Zero Allocations Example:**

```cpp
const char* name = "Yann Cherno";
std::string_view firstName(name, 3);
std::string_view lastName(name + 4, 9);
printName(firstName); // printName takes std::string_view
```

This results in zero allocations. \[[11:16](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=676)\]

-----

### Performance Comparison

A final comparison shows that using `std::string` for the original name and then `std::string_view` for operations reduces allocations from four to one. \[[13:13](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=793)\] The speaker encourages viewers to benchmark this optimization in their own projects, especially in real-time applications like games, where string operations can be a significant performance bottleneck. \[[13:36](http://www.youtube.com/watch?v=ZO68JEgoPeg&t=816)\]

Since you're into simulations and C++, this is a great optimization to keep in mind for your Manim and OpenGL projects. It could make a real difference in performance\! Happy coding\! 😊
