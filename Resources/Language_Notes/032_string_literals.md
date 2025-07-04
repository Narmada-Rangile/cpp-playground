This video explains string literals in C++, covering how they are stored in memory and the different character encodings available.

-----

### What is a String Literal?

  * A **string literal** is a sequence of characters enclosed in double quotes, like `"Cherno"` \[[00:17](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=17)\].

  * In C++, `"Cherno"` is treated as a `const char` array \[[00:35](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=35)\].

  * A string literal such as `"Cherno"` (6 characters) has a size of 7 because of the null termination character (`\0`) at the end, which marks the end of the string \[[00:41](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=41)\].

  * Manually adding a null terminator in the middle of a string will cause issues, as functions like `strlen` will only count characters up to that point \[[01:23](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=83)\].

    ```cpp
    const char* name = "Ch\0erno";
    // strlen(name) would return 2
    ```

-----

### String Literals and Memory

  * String literals are stored in a **read-only** section of memory \[[03:52](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=232)\].

  * Trying to modify a string literal through a `char*` pointer leads to undefined behavior and can cause exceptions \[[03:19](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=199), [03:27](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=207)\].

    ```cpp
    char* name = "Cherno";
    name[0] = 'a'; // Undefined behavior
    ```

  * To modify a string, you should create a `char` array, which copies the string to the stack, making it modifiable \[[05:52](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=352)\].

    ```cpp
    char name[] = "Cherno";
    name[0] = 'a'; // This is allowed
    ```

-----

### Character Types and Prefixes

  * Besides `char` (1 byte, usually UTF-8), there are other character types for different encodings:
      * `wchar_t` (wide character): 2 or 4 bytes, depending on the compiler. Use the `L` prefix \[[06:55](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=415)\].

        ```cpp
        const wchar_t* name = L"Cherno";
        ```

      * `char16_t`: 2 bytes (UTF-16). Use the `u` prefix \[[07:11](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=431)\].

        ```cpp
        const char16_t* name = u"Cherno";
        ```

      * `char32_t`: 4 bytes (UTF-32). Use the `U` prefix \[[07:26](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=446)\].

        ```cpp
        const char32_t* name = U"Cherno";
        ```

      * You can also explicitly use the `u8` prefix for `char` to enforce UTF-8 \[[07:35](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=455)\].

        ```cpp
        const char* name = u8"Cherno";
        ```

-----

### Raw String Literals

  * Introduced in C++11, **raw string literals** use an `R` prefix and ignore escape characters, making it easier to write strings with backslashes or on multiple lines \[[10:17](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=617), [11:11](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=671)\].

    ```cpp
    const char* multiLineText = R"(Line 1
    Line 2
    Line 3)";
    ```

  * Without raw string literals, you would need to use `\n` and string concatenation for multi-line strings \[[10:36](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=636)\].

-----

### String Literal Operators (C++14)

  * C++14 introduced user-defined string literals, allowing you to create `std::string` objects directly by adding an `s` suffix \[[08:53](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=533), [09:30](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=570)\].

    ```cpp
    using namespace std::string_literals; // Required for the 's' suffix
    std::string name = "Cherno"s;
    ```

  * Similar suffixes exist for wide strings (`L"text"s`), `char16_t` strings (`u"text"s`), and `char32_t` strings (`U"text"s`) \[[09:46](http://www.youtube.com/watch?v=FeHZHF0f2dw&t=586)\].
