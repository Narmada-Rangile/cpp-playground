This video is a great resource for you since you're into C++ programming. It covers different ways to handle multiple return values from a function, which is a common challenge in C++. The presenter also shares their preferred method, which you might find useful for your own projects.

### Key Concepts

  * **The Problem with Multiple Return Types**

      * C++ functions are designed to return only one value \[[01:17](http://www.youtube.com/watch?v=3cm0VckC8q0&t=77)\].
      * While you can return multiple values of the same type using a `std::vector` or an array, it's not always the best solution \[[01:53](http://www.youtube.com/watch?v=3cm0VckC8q0&t=113)\].

  * **Methods for Handling Multiple Return Types**

      * **Passing Parameters by Reference/Pointer**

          * **Concept:** Instead of returning values, you can pass variables by reference or pointer and modify them within the function \[[03:37](http://www.youtube.com/watch?v=3cm0VckC8q0&t=217)\].
          * **Pros:**
              * Can be more performant by avoiding unnecessary copies and memory allocations \[[05:11](http://www.youtube.com/watch?v=3cm0VckC8q0&t=311)\].
              * Pointers allow for optional parameters, so you can pass `nullptr` if you don't need a specific return value \[[07:22](http://www.youtube.com/watch?v=3cm0VckC8q0&t=442)\].
          * **Cons:**
              * The syntax can be a bit clunky \[[06:21](http://www.youtube.com/watch?v=3cm0VckC8q0&t=381)\].
              * It's not always clear that a reference parameter is an output parameter \[[06:28](http://www.youtube.com/watch?v=3cm0VckC8q0&t=388)\].
          * **Code Example (Reference):**
            ```cpp
            void ParseShader(std::string& vertexSource, std::string& fragmentSource) {
                // ...
                vertexSource = vs;
                fragmentSource = fs;
            }

            // Calling the function
            std::string vs, fs;
            ParseShader(vs, fs);
            ```
            \[[03:43](http://www.youtube.com/watch?v=3cm0VckC8q0&t=223)\]
          * **Code Example (Pointer):**
            ```cpp
            void ParseShader(std::string* outVertexSource, std::string* outFragmentSource) {
                // ...
                if (outVertexSource)
                    *outVertexSource = vs;
                if (outFragmentSource)
                    *outFragmentSource = fs;
            }

            // Calling the function
            std::string vs, fs;
            ParseShader(&vs, &fs);
            ```
            \[[06:49](http://www.youtube.com/watch?v=3cm0VckC8q0&t=409)\]

      * **Returning an Array (for same types)**

          * **Concept:** You can return a pointer to a dynamically allocated array or a `std::array` \[[07:49](http://www.youtube.com/watch?v=3cm0VckC8q0&t=469)\].
          * **Pros:** Simple for returning multiple values of the same type.
          * **Cons:**
              * Returning a raw pointer can lead to memory leaks if you forget to deallocate the memory \[[08:10](http://www.youtube.com/watch?v=3cm0VckC8q0&t=490)\].
              * A raw pointer doesn't tell you the size of the array \[[08:36](http://www.youtube.com/watch?v=3cm0VckC8q0&t=516)\].
              * `std::array` has a fixed size, which can be inflexible \[[08:50](http://www.youtube.com/watch?v=3cm0VckC8q0&t=530)\].
          * **Code Example (`std::array`):**
            ```cpp
            #include <array>
            std::array<std::string, 2> ParseShader() {
                // ...
                std::array<std::string, 2> results;
                results[0] = vs;
                results[1] = fs;
                return results;
            }
            ```
            \[[08:50](http://www.youtube.com/watch?v=3cm0VckC8q0&t=530)\]

      * **Returning a `std::vector` (for same types)**

          * **Concept:** You can return a `std::vector` containing the values \[[09:51](http://www.youtube.com/watch?v=3cm0VckC8q0&t=591)\].
          * **Pros:** Dynamic size, more flexible than `std::array`.
          * **Cons:** Can be slower than `std::array` due to heap allocation \[[10:04](http://www.youtube.com/watch?v=3cm0VckC8q0&t=604)\].
          * **Code Example:**
            ```cpp
            #include <vector>
            std::vector<std::string> ParseShader() {
                // ...
                std::vector<std::string> results;
                results.push_back(vs);
                results.push_back(fs);
                return results;
            }
            ```
            \[[10:17](http://www.youtube.com/watch?v=3cm0VckC8q0&t=617)\]

      * **Returning a `std::tuple` (for different types)**

          * **Concept:** A `std::tuple` can hold a fixed number of variables of different types \[[11:04](http://www.youtube.com/watch?v=3cm0VckC8q0&t=664)\].
          * **Pros:** A universal way to return multiple values of different types \[[10:51](http://www.youtube.com/watch?v=3cm0VckC8q0&t=651)\].
          * **Cons:** Accessing elements by index (`std::get<0>`) isn't very descriptive \[[13:30](http://www.youtube.com/watch?v=3cm0VckC8q0&t=810)\].
          * **Code Example:**
            ```cpp
            #include <tuple>
            #include <utility>

            std::tuple<std::string, std::string> ParseShader() {
                // ...
                return std::make_tuple(vs, fs);
            }

            // Calling the function
            auto sources = ParseShader();
            std::string vertexSource = std::get<0>(sources);
            std::string fragmentSource = std::get<1>(sources);
            ```
            \[[11:16](http://www.youtube.com/watch?v=3cm0VckC8q0&t=676)\]

      * **Returning a `std::pair` (for two different types)**

          * **Concept:** Similar to `std::tuple`, but specifically for two elements \[[14:04](http://www.youtube.com/watch?v=3cm0VckC8q0&t=844)\].
          * **Pros:** You can access elements using `.first` and `.second`, which is a bit more readable than indices \[[14:21](http://www.youtube.com/watch?v=3cm0VckC8q0&t=861)\].
          * **Cons:** Still not very descriptive \[[14:34](http://www.youtube.com/watch?v=3cm0VckC8q0&t=874)\].
          * **Code Example:**
            ```cpp
            #include <utility>

            std::pair<std::string, std::string> ParseShader() {
                // ...
                return std::make_pair(vs, fs);
            }

            // Calling the function
            auto sources = ParseShader();
            std::string vertexSource = sources.first;
            std::string fragmentSource = sources.second;
            ```
            \[[14:04](http://www.youtube.com/watch?v=3cm0VckC8q0&t=844)\]

      * **Returning a Custom `struct` (Speaker's Preferred Method)**

          * **Concept:** Create a `struct` to hold the return values as named members \[[14:51](http://www.youtube.com/watch?v=3cm0VckC8q0&t=891)\].
          * **Pros:**
              * **Clarity and Readability:** Named members make the code much easier to understand \[[15:43](http://www.youtube.com/watch?v=3cm0VckC8q0&t=943)\].
              * **Type Safety:** Explicitly defines the types of the returned values.
              * **Flexibility:** Easy to add or remove return values by modifying the struct \[[15:22](http://www.youtube.com/watch?v=3cm0VckC8q0&t=922)\].
              * **Performance:** Can be stack-allocated for better performance \[[15:27](http://www.youtube.com/watch?v=3cm0VckC8q0&t=927)\].
          * **Cons:** Requires defining a new `struct` for each unique set of return types.
          * **Code Example:**
            ```cpp
            struct ShaderProgramSource {
                std::string VertexSource;
                std::string FragmentSource;
            };

            ShaderProgramSource ParseShader() {
                // ...
                ShaderProgramSource source;
                source.VertexSource = vs;
                source.FragmentSource = fs;
                return source;
            }

            // Calling the function
            ShaderProgramSource sources = ParseShader();
            std::string vertexSource = sources.VertexSource;
            std::string fragmentSource = sources.FragmentSource;
            ```
            \[[14:51](http://www.youtube.com/watch?v=3cm0VckC8q0&t=891)\]
