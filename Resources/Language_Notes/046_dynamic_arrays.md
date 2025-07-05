### Introduction to `std::vector`

  * **What it is**: `std::vector` is a dynamic array that can grow and shrink in size, unlike traditional C-style arrays \[[02:06](http://www.youtube.com/watch?v=PocJ5jXv8No&t=126)\]. It's a part of the C++ Standard Template Library (STL) \[[00:14](http://www.youtube.com/watch?v=PocJ5jXv8No&t=14)\].
  * **Templated Nature**: The STL is "templated," which means you can define the data type the vector will hold (e.g., `int`, `float`, custom objects) \[[00:26](http://www.youtube.com/watch?v=PocJ5jXv8No&t=26)\].
  * **Alternative Name**: The video suggests that "ArrayList" would have been a more descriptive name for this data structure, as it functions like a dynamic array \[[01:28](http://www.youtube.com/watch?v=PocJ5jXv8No&t=88)\].

-----

### How `std::vector` Resizes

  * When you add an element to a full vector, it performs the following steps \[[03:41](http://www.youtube.com/watch?v=PocJ5jXv8No&t=221)\]:
    1.  Allocates a new, larger block of memory.
    2.  Copies all the existing elements to this new memory location.
    3.  Deletes the old memory block.
  * This resizing operation can be computationally expensive, especially for large vectors, and can impact performance \[[04:04](http://www.youtube.com/watch?v=PocJ5jXv8No&t=244)\]. The video notes that future tutorials will cover how to optimize this \[[04:21](http://www.youtube.com/watch?v=PocJ5jXv8No&t=261)\].

-----

### Creating and Using `std::vector`

Here's how to work with `std::vector` in your C++ code:

  * **Include the header**:

    ```cpp
    #include <vector>
    ```

    \[[06:15](http://www.youtube.com/watch?v=PocJ5jXv8No&t=375)\]

  * **Declaration**:

    ```cpp
    std::vector<Vertex> vertices; // A vector to hold 'Vertex' objects
    std::vector<int> numbers;      // A vector to hold integers
    ```

    \[[06:21](http://www.youtube.com/watch?v=PocJ5jXv8No&t=381)\], \[[06:41](http://www.youtube.com/watch?v=PocJ5jXv8No&t=401)\]

  * **Adding Elements**: Use the `push_back()` method to add elements to the end of the vector.

    ```cpp
    vertices.push_back(vertex1);
    vertices.push_back(vertex2);
    ```

    \[[09:34](http://www.youtube.com/watch?v=PocJ5jXv8No&t=574)\]

  * **Accessing Elements**:

      * Get the number of elements with `size()`:
        ```cpp
        std::cout << "The vector has " << vertices.size() << " elements." << std::endl;
        ```
        \[[10:08](http://www.youtube.com/watch?v=PocJ5jXv8No&t=608)\]
      * Access elements using the index operator `[]`, just like a regular array:
        ```cpp
        Vertex firstVertex = vertices[0];
        ```
        \[[10:19](http://www.youtube.com/watch?v=PocJ5jXv8No&t=619)\]

  * **Iterating Over a Vector**:

      * **Traditional `for` loop**:
        ```cpp
        for (int i = 0; i < vertices.size(); i++) {
            // Do something with vertices[i]
        }
        ```
        \[[10:08](http://www.youtube.com/watch?v=PocJ5jXv8No&t=608)\]
      * **Range-based `for` loop** (simpler and recommended):
        ```cpp
        // Use a const reference to avoid copying elements
        for (const Vertex& v : vertices) {
            // Do something with v
        }
        ```
        \[[10:41](http://www.youtube.com/watch?v=PocJ5jXv8No&t=641)\], \[[11:02](http://www.youtube.com/watch?v=PocJ5jXv8No&t=662)\]

  * **Removing Elements**:

      * `clear()` removes all elements from the vector, making its size 0.
        ```cpp
        vertices.clear();
        ```
        \[[11:21](http://www.youtube.com/watch?v=PocJ5jXv8No&t=681)\]
      * `erase()` removes one or more elements. It takes an iterator as an argument.
        ```cpp
        // Remove the second element
        vertices.erase(vertices.begin() + 1);
        ```
        \[[12:27](http://www.youtube.com/watch?v=PocJ5jXv8No&t=747)\]

-----

### Storing Objects vs. Pointers

The video discusses the trade-offs of storing objects directly versus storing pointers to objects in a vector \[[07:11](http://www.youtube.com/watch?v=PocJ5jXv8No&t=431)\]:

  * **Storing Objects Directly (`std::vector<Vertex>`)**:

      * **Pros**: Generally more performant due to contiguous memory and better cache utilization \[[07:49](http://www.youtube.com/watch?v=PocJ5jXv8No&t=469)\].
      * **Cons**: Can be slow if the objects are large and the vector resizes frequently, as this involves copying all the objects \[[08:38](http://www.youtube.com/watch?v=PocJ5jXv8No&t=518)\].

  * **Storing Pointers (`std::vector<Vertex*>`)**:

      * **Pros**: Avoids the cost of copying large objects during resizing \[[08:51](http://www.youtube.com/watch?v=PocJ5jXv8No&t=531)\].
      * **Cons**: The actual object data might be scattered in memory, leading to poorer cache performance.

The general recommendation is to store objects directly unless you have a specific reason to use pointers \[[09:17](http://www.youtube.com/watch?v=PocJ5jXv8No&t=557)\].

-----

### Passing Vectors to Functions

To avoid inefficiently copying the entire vector when passing it to a function, you should pass it by reference (`&`) \[[12:32](http://www.youtube.com/watch?v=PocJ5jXv8No&t=752)\]. If the function doesn't need to modify the vector, pass it as a constant reference (`const&`) \[[12:43](http://www.youtube.com/watch?v=PocJ5jXv8No&t=763)\].

```cpp
void printVertices(const std::vector<Vertex>& vertices) {
    for (const Vertex& v : vertices) {
        // ...
    }
}
```
