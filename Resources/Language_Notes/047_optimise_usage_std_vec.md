### Understanding the Problem: Unnecessary Copying

When you use `push_back` to add an object to a `std::vector`, a copy of that object is often created. If the vector's internal storage is full, it needs to reallocate a larger block of memory and then copy **all** of its existing elements to the new location. This process can be slow, especially with large objects or many elements \[[01:13:00](http://www.youtube.com/watch?v=HcESuwmlHEY&t=4380)\].

For instance, adding three objects to a vector might result in six or more copies due to reallocations \[[03:56:00](http://www.youtube.com/watch?v=HcESuwmlHEY&t=14160)\]. You can track these copies by adding a print statement to your object's copy constructor:

```cpp
class Vertex {
public:
    float x, y, z;

    Vertex(float x, float y, float z) : x(x), y(y), z(z) {}

    // Copy constructor to see when copies happen
    Vertex(const Vertex& other) : x(other.x), y(other.y), z(other.z) {
        std::cout << "Copied!" << std::endl;
    }
};
```

\[[02:53:00](http://www.youtube.com/watch?v=HcESuwmlHEY&t=10380)\]

-----

### Optimization 1: `reserve()`

If you know roughly how many elements you'll be adding, you can use the `reserve()` method to pre-allocate memory. This prevents the vector from having to reallocate and copy its elements multiple times \[[05:54:00](http://www.youtube.com/watch?v=HcESuwmlHEY&t=21240)\].

```cpp
std::vector<Vertex> vertices;
vertices.reserve(3); // Pre-allocates space for 3 vertices
vertices.push_back({1, 2, 3});
vertices.push_back({4, 5, 6});
vertices.push_back({7, 8, 9});
```

Using `reserve()` in the example from the video reduces the number of copies from six to three \[[07:36:00](http://www.youtube.com/watch?v=HcESuwmlHEY&t=27360)\].

-----

### Optimization 2: `emplace_back()`

To get rid of the remaining copies, you can use `emplace_back()` instead of `push_back()`. This method constructs the object **directly** in the vector's memory, avoiding the creation of a temporary object that then needs to be copied \[[07:50:00](http://www.youtube.com/watch?v=HcESuwmlHEY&t=28200)\].

```cpp
std::vector<Vertex> vertices;
vertices.reserve(3); // Still a good idea to reserve memory
vertices.emplace_back(1, 2, 3); // Constructs the Vertex in-place
vertices.emplace_back(4, 5, 6);
vertices.emplace_back(7, 8, 9);
```

By combining `reserve()` and `emplace_back()`, you can reduce the number of copies to zero, leading to much more efficient code \[[08:29:00](http://www.youtube.com/watch?v=HcESuwmlHEY&t=30540)\]. 🚀
