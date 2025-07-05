### Introduction to `std::optional`

The video introduces **`std::optional`**, a feature added in C++17. It's designed to solve the problem of functions that may or may not return a value. \[[00:42](http://www.youtube.com/watch?v=UAAiwObNhQ0&t=42)\]

-----

### The Problem with Traditional Methods

When a function might not have a value to return (e.g., reading a file that doesn't exist), developers have used a few common patterns, each with its own issues:

  * **Returning an empty string:** This is ambiguous. It's hard to tell if the file was actually empty or if the file couldn't be opened at all. \[[02:25](http://www.youtube.com/watch?v=UAAiwObNhQ0&t=145)\]
  * **Using a boolean output parameter:** This is a better approach, but it can make the code less clean and intuitive. \[[03:45](http://www.youtube.com/watch?v=UAAiwObNhQ0&t=225)\]

-----

### How to Use `std::optional`

`std::optional` provides a much cleaner and more expressive way to handle these situations.

#### **1. Include the Header**

First, you need to include the `<optional>` header file. \[[03:51](http://www.youtube.com/watch?v=UAAiwObNhQ0&t=231)\]

#### **2. Set the C++ Standard**

Make sure your compiler is set to use C++17 or a later version. \[[04:15](http://www.youtube.com/watch?v=UAAiwObNhQ0&t=255)\]

#### **3. Function Signature**

You'll need to change the return type of your function to `std::optional<Type>`, where `Type` is the type of data you want to return. \[[04:05](http://www.youtube.com/watch?v=UAAiwObNhQ0&t=245)\]

```cpp
// Before
// std::string read_file_as_string(const std::string& file_path, bool& success);

// After
std::optional<std::string> read_file_as_string(const std::string& file_path);
```

#### **4. Returning Values**

  * If you have a value to return, you can return it directly. \[[04:49](http://www.youtube.com/watch?v=UAAiwObNhQ0&t=289)\]
  * If you don't have a value, you can return an empty `std::optional` by using `{}`. \[[04:39](http://www.youtube.com/watch?v=UAAiwObNhQ0&t=279)\]

<!-- end list -->

```cpp
// Inside read_file_as_string function
if (stream_opened_successfully) {
    // Read file content into 'result'
    return result;
} else {
    return {}; // Returns an empty optional
}
```

#### **5. Checking for a Value**

You can check if an `std::optional` contains a value in a couple of ways:

  * Use the `has_value()` member function. \[[05:07](http://www.youtube.com/watch?v=UAAiwObNhQ0&t=307)\]
  * A cleaner way is to use the `std::optional` object in an `if` statement, as it has a `bool` operator. \[[05:30](http://www.youtube.com/watch?v=UAAiwObNhQ0&t=330)\]

<!-- end list -->

```cpp
std::optional<std::string> data = read_file_as_string("data.txt");

if (data.has_value()) { // Or simply 'if (data)'
    // File read successfully
    std::cout << "File read successfully" << std::endl;
} else {
    // File could not be opened
    std::cout << "File could not be opened" << std::endl;
}
```

#### **6. Accessing the Value**

Once you've confirmed that the `std::optional` has a value, you can access it in a few ways:

  * Use the dereference operator (`*data`). \[[06:04](http://www.youtube.com/watch?v=UAAiwObNhQ0&t=364)\]
  * If the contained type is a class or struct, you can use the arrow operator (`data->`). \[[05:53](http://www.youtube.com/watch?v=UAAiwObNhQ0&t=353)\]
  * Use the `value()` member function. \[[06:14](http://www.youtube.com/watch?v=UAAiwObNhQ0&t=374)\]

<!-- end list -->

```cpp
if (data) {
    std::string my_string = *data; // Dereference to get the string
    // Or data->member_function()
    // Or data.value()
}
```

#### **7. Providing a Default Value with `value_or()`**

The `value_or()` member function is a convenient way to get the value from the `std::optional` or a default value if it's empty. This is especially useful for things like optional configuration parameters. \[[07:33](http://www.youtube.com/watch?v=UAAiwObNhQ0&t=453)\]

```cpp
std::string value = data.value_or("not present");
std::cout << value << std::endl; // Will print "not present" if data is empty

// Example with an integer
// std::optional<int> count_optional = read_count_from_file();
// int count = count_optional.value_or(100); // Default to 100 if not present
```

I hope these notes are helpful\! Let me know if you have any other questions.
