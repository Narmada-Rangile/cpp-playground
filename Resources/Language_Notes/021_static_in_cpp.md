### The `static` Keyword in C++

This video explains the `static` keyword in C++ \[[00:04](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=4)\], focusing on its meaning when used outside of a class or struct \[[01:00](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=60)\].

-----

### Two Meanings of `static` \[[00:09](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=9)\]

The `static` keyword has different meanings depending on where it's used:

  * **Outside a Class/Struct**: It gives the symbol (variable or function) **internal linkage** \[[00:23](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=23)\], meaning it's only visible within the translation unit (the specific `.cpp` file) where it's defined \[[00:28](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=28)\].
  * **Inside a Class/Struct**: It means the variable shares memory across all instances of the class. For methods, it means no instance of the class is passed into the method \[[00:33](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=33)\]. The video mentions this will be covered in a separate video \[[00:55](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=55)\].

-----

### Internal Linkage Explained \[[01:23](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=83)\]

When a variable or function is declared `static` outside a class, the linker won't look for its definition outside of that specific translation unit \[[01:45](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=105)\]. This prevents naming conflicts between different files.

-----

### Demonstration with Variables \[[01:51](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=111)\]

  * A `static` global variable in one file won't conflict with a global variable of the same name in another file \[[02:06](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=126)\].
  * If you remove `static` from a global variable, you'll get a linking error if another global variable with the same name exists in a different translation unit \[[02:25](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=145)\].
  * Using `extern` allows a variable in one translation unit to reference a global variable defined in another \[[02:46](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=166)\]. However, if the original variable is `static`, using `extern` will cause an "unresolved external symbol" error because the `static` variable is private to its translation unit \[[03:03](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=183)\].

#### Code Example:

**File 1: `main.cpp`**

```cpp
// By including "another.cpp" we are just pasting the code from that file here
// This is not how you would normally do this, but it's for demonstration purposes
#include "another.cpp" 

int main() {
  // This will cause a linking error if another.cpp also has a global `s_Variable`
  // that is not static.
  s_Variable = 5; 
  return 0;
}
```

**File 2: `another.cpp`**

```cpp
// By making this static, it is only visible within this translation unit.
static int s_Variable = 10; 
```

-----

### Demonstration with Functions \[[03:31](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=211)\]

Similar to variables, declaring a function as `static` prevents linking errors when another function with the same signature exists in a different translation unit \[[03:46](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=226)\].

-----

### Purpose of `static` (outside class) \[[04:08](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=248)\]

It ensures that a function or variable is only visible within the C++ file it's declared in \[[04:13](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=253)\].

-----

### `static` in Header Files \[[04:20](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=260)\]

If a `static` variable is declared in a header file and that header is included in multiple `.cpp` files, it creates a separate `static` variable in each of those translation units \[[04:24](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=264)\].

-----

### Why Use `static` \[[04:46](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=286)\]

It's recommended to use `static` for variables and functions that don't need to be globally accessible across translation units \[[04:51](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=291)\]. This helps prevent potential bugs associated with global variables and name collisions \[[05:02](http://www.youtube.com/watch?v=f3FVU-iwNuA&t=302)\].
