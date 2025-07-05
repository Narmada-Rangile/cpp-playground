### Introduction to `std::variant`

The video introduces **`std::variant`**, a C++17 feature that allows a single variable to hold values of different data types. This is particularly useful when you're not sure what type of data you'll be working with, like when parsing files or handling command-line arguments. The speaker also notes its similarity to `std::optional` but clarifies that `std::variant` is for handling varying types, not just the presence or absence of a value. [00:00 - 02:10]

-----

### Basic Usage

Here's how to declare and assign values to a `std::variant`: [02:10 - 02:59]

```cpp
#include <iostream>
#include <variant>

int main() {
    std::variant<std::string, int> data;
    data = "Cherno"; // Assign a string
    data = 2;         // Reassign to an int
}
```

-----

### Accessing Data

#### **Using `std::get`**

You can retrieve the stored value using `std::get<Type>(variant_variable)`. Be careful, though—if you try to access the wrong type, it will throw a `bad_variant_access` exception. [02:59 - 03:51]

```cpp
#include <iostream>
#include <variant>

int main() {
    std::variant<std::string, int> data;
    data = "Cherno";
    std::cout << std::get<std::string>(data) << "\n"; // Prints "Cherno"
    data = 2;
    std::cout << std::get<int>(data) << "\n";         // Prints "2"

    // This would throw an exception:
    // std::cout << std::get<std::string>(data) << "\n";
}
```

#### **Checking the Current Type with `data.index()`**

The `data.index()` method returns an integer representing the index of the currently stored type in the variant's template argument list (0 for the first type, 1 for the second, and so on). [03:51 - 04:45]

```cpp
#include <iostream>
#include <variant>

int main() {
    std::variant<std::string, int> data;
    data = "Cherno";
    std::cout << data.index() << "\n"; // Prints "0" (for std::string)
    data = 2;
    std::cout << data.index() << "\n"; // Prints "1" (for int)
}
```

#### **Safely Accessing Data with `std::get_if`**

A safer way to access the data is with `std::get_if<Type>(&variant_variable)`. This function returns a pointer to the value if it's of the specified type, or `nullptr` otherwise. This allows you to check the type before accessing the value, avoiding exceptions. [04:45 - 05:59]

```cpp
#include <iostream>
#include <variant>

int main() {
    std::variant<std::string, int> data;
    data = "Cherno";

    if (auto value = std::get_if<std::string>(&data)) {
        std::string& v = *value; // Dereference the pointer
        std::cout << v << "\n"; // Prints "Cherno"
    } else {
        std::cout << "Not a string\n";
    }

    data = 2;
    if (auto value = std::get_if<std::string>(&data)) {
        std::cout << *value << "\n";
    } else {
        std::cout << "Not a string\n"; // Prints "Not a string"
    }
}
```

-----

### `std::variant` vs. Unions (Memory Footprint)

The speaker clarifies that `std::variant` is not the same as a type-safe union. A `std::variant` allocates enough memory to store the largest possible type plus some overhead for type tracking. This makes it less memory-efficient than a union, but much safer. [05:59 - 07:02]

```cpp
#include <iostream>
#include <variant>
#include <string>

int main() {
    std::variant<std::string, int> data;
    std::cout << "Size of int: " << sizeof(int) << "\n";       // Prints 4
    std::cout << "Size of string: " << sizeof(std::string) << "\n"; // Prints 28 (or similar)
    std::cout << "Size of data: " << sizeof(data) << "\n";     // Prints 32 (or similar)
}
```

-----

### Practical Use Case: Error Handling

A great use case for `std::variant` is error handling. Instead of returning an `std::optional<std::string>` (which only tells you if you succeeded or failed), you can return a `std::variant<std::string, ErrorCode>` to provide specific information about the error. [07:02 - 09:35]

```cpp
#include <iostream>
#include <variant>
#include <string>
#include <optional>

enum class ErrorCode {
    None = 0,
    NotFound = 1,
    NoAccess = 2
};

std::variant<std::string, ErrorCode> ReadFileAsString() {
    // Simulate file reading
    // For demonstration, let's say it fails with a "Not Found" error
    return ErrorCode::NotFound;
    // Or if successful: return "File content";
}

int main() {
    std::variant<std::string, ErrorCode> fileResult = ReadFileAsString();

    if (std::holds_alternative<std::string>(fileResult)) {
        std::cout << "File content: " << std::get<std::string>(fileResult) << "\n";
    } else if (std::holds_alternative<ErrorCode>(fileResult)) {
        ErrorCode error = std::get<ErrorCode>(fileResult);
        if (error == ErrorCode::NotFound) {
            std::cout << "Error: File not found!\n";
        } else if (error == ErrorCode::NoAccess) {
            std::cout << "Error: No access to file!\n";
        }
    }
}
```

I hope these notes are helpful\! Let me know if you have any other questions.
