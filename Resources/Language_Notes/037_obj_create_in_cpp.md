### Object Instantiation in C++ \[[00:05](http://www.youtube.com/watch?v=Ks97R1knQDY&t=5)\]

When you create a class in C++, you need to instantiate it to use it. C++ provides two primary ways to do this, which differ in where the object's memory is allocated. It's important to note that every object in C++ occupies memory, even an empty class \[[00:45](http://www.youtube.com/watch?v=Ks97R1knQDY&t=45)\].

-----

### Memory Sections: Stack vs. Heap \[[01:11](http://www.youtube.com/watch?v=Ks97R1knQDY&t=71)\]

  * **Stack**: Objects created on the stack have an **automatic lifespan** controlled by their scope \[[01:52](http://www.youtube.com/watch?v=Ks97R1knQDY&t=112)\]. This means memory is automatically freed when the variable goes out of scope \[[02:05](http://www.youtube.com/watch?v=Ks97R1knQDY&t=125)\]. This is generally the fastest and most managed way to instantiate objects in C++ \[[04:37](http://www.youtube.com/watch?v=Ks97R1knQDY&t=277)\]. However, the stack is typically small (1-2 megabytes), so it's not suitable for very large objects or a large number of objects \[[06:54](http://www.youtube.com/watch?v=Ks97R1knQDY&t=414)\].
  * **Heap**: Objects allocated on the heap persist until you **explicitly free their memory** \[[02:18](http://www.youtube.com/watch?v=Ks97R1knQDY&t=138)\]. This requires manual memory management using `new` and `delete` \[[09:12](http://www.youtube.com/watch?v=Ks97R1knQDY&t=552)\] and is slower than stack allocation \[[09:06](http://www.youtube.com/watch?v=Ks97R1knQDY&t=546)\].

-----

### Creating Objects on the Stack \[[03:19](http://www.youtube.com/watch?v=Ks97R1knQDY&t=199)\]

  * **Syntax**: `ClassName objectName;`
  * This calls the default constructor.

**Example**:

```cpp
// Class definition (simplified from video)
class Entity {
public:
    std::string m_Name;
    Entity() : m_Name("Unknown") {}
    Entity(const std::string& name) : m_Name(name) {}
    const std::string& GetName() const { return m_Name; }
};

int main() {
    Entity entity; // Calls default constructor
    std::cout << entity.GetName() << std::endl; // Output: Unknown

    Entity entity2("Cherno"); // Calls constructor with parameter
    std::cout << entity2.GetName() << std::endl; // Output: Cherno
}
```

**Scope Example**:

```cpp
void FunctionA() {
    Entity entity("Cherno");
    // entity exists here
} // entity is destroyed when FunctionA ends
```

If you try to access `entity` outside its scope (e.g., via a pointer that was set to its address), it will lead to undefined behavior because the memory has been freed \[[06:27](http://www.youtube.com/watch?v=Ks97R1knQDY&t=387)\].

-----

### Creating Objects on the Heap \[[07:14](http://www.youtube.com/watch?v=Ks97R1knQDY&t=434)\]

  * **Syntax**: `ClassName* objectName = new ClassName();`
  * The `new` keyword allocates memory on the heap and calls the constructor, returning a pointer to the allocated object \[[07:44](http://www.youtube.com/watch?v=Ks97R1knQDY&t=464)\].
  * You **must** use the `delete` keyword to free the memory allocated on the heap to prevent memory leaks \[[09:12](http://www.youtube.com/watch?v=Ks97R1knQDY&t=552)\].
  * Use the arrow operator (`->`) with pointers to access members \[[10:06](http://www.youtube.com/watch?v=Ks97R1knQDY&t=606)\].

**Example**:

```cpp
// Class definition (same as above)

int main() {
    Entity* entity = new Entity("Cherno"); // Allocate on heap
    std::cout << entity->GetName() << std::endl; // Access member using arrow operator

    delete entity; // Manually free the allocated memory
}
```

This method of object creation is similar to how objects are typically created in Java or C\# \[[08:10](http://www.youtube.com/watch?v=Ks97R1knQDY&t=490)\].

-----

### When to Choose Which Method \[[10:52](http://www.youtube.com/watch?v=Ks97R1knQDY&t=652)\]

  * **Allocate on the Stack**:
      * If your object is not "really, really big" \[[10:52](http://www.youtube.com/watch?v=Ks97R1knQDY&t=652)\].
      * If you don't need explicit control over the object's lifetime \[[10:58](http://www.youtube.com/watch?v=Ks97R1knQDY&t=658)\].
      * It's easier, automated, and faster \[[11:04](http://www.youtube.com/watch?v=Ks97R1knQDY&t=664)\].
  * **Allocate on the Heap**:
      * If the object is very large or you need many instances that might exceed stack limits \[[06:54](http://www.youtube.com/watch?v=Ks97R1knQDY&t=414)\].
      * If you need to explicitly control the object's lifetime (e.g., it needs to persist beyond the scope it was created in) \[[04:57](http://www.youtube.com/watch?v=Ks97R1knQDY&t=297)\].
      * Be mindful of memory leaks if `delete` is forgotten \[[11:11](http://www.youtube.com/watch?v=Ks97R1knQDY&t=671)\].

-----

### Smart Pointers \[[11:25](http://www.youtube.com/watch?v=Ks97R1knQDY&t=685)\]

The video briefly mentions **smart pointers** as a way to allocate on the heap while still getting automatic deletion, addressing the manual memory management issue \[[11:46](http://www.youtube.com/watch?v=Ks97R1knQDY&t=706)\]. This topic will be covered in future videos.
