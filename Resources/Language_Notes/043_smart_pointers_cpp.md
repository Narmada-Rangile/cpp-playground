### What Are Smart Pointers? 🤔

  * Smart pointers are special objects that act as **wrappers around raw pointers**. They automate the process of allocating memory on the heap with `new` and freeing it with `delete` \[[00:35](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=35), [00:58](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=58)\].
  * The goal is to **avoid manual memory management**, which is a common source of bugs like memory leaks \[[00:53](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=53)\].

-----

### `std::unique_ptr` ☝️

  * A `std::unique_ptr` is a **"scoped pointer"**. When it goes out of scope, it's automatically destroyed, and the memory it points to is freed \[[01:17](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=77)\].
  * As the name suggests, it's **unique**—you can't copy it. This prevents situations where two pointers think they own the same memory, which would lead to a double-free error \[[01:35](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=95)\].
  * It's the most lightweight smart pointer, often with **zero overhead** compared to a raw pointer \[[03:58](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=238), [04:02](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=242)\].
  * To use smart pointers, you'll need to include the `<memory>` header \[[02:07](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=127)\].

<!-- end list -->

```cpp
#include <iostream>
#include <memory>

class Entity {
public:
    Entity() { std::cout << "Entity Created" << std::endl; }
    ~Entity() { std::cout << "Entity Destroyed" << std::endl; }
};

int main() {
    { // Start of a new scope
        // Use std::make_unique for exception safety
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
    } // 'entity' goes out of scope here, and the Entity is destroyed
    return 0;
}
```

-----

### `std::shared_ptr` 🤝

  * A `std::shared_ptr` allows for **shared ownership** of a pointer. It keeps track of how many `shared_ptr`s are pointing to the same object using a **reference count** \[[04:58](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=298), [05:17](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=317)\].
  * The memory is only freed when the **reference count drops to zero** \[[05:48](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=348)\].
  * It's best to create `shared_ptr`s with `std::make_shared`. This is more efficient because it allocates the object and its control block (for the reference count) in a single step \[[06:31](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=391), [06:58](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=418)\].

<!-- end list -->

```cpp
#include <iostream>
#include <memory>

// ... (Entity class from before)

int main() {
    std::shared_ptr<Entity> sharedEntity;
    {
        std::shared_ptr<Entity> entity0 = std::make_shared<Entity>(); // Ref count is 1
        sharedEntity = entity0; // Ref count is now 2
    } // 'entity0' is out of scope, ref count is 1. The Entity is NOT destroyed.
    return 0;
} // 'sharedEntity' is out of scope, ref count is 0. The Entity is destroyed here.
```

-----

### `std::weak_ptr` 🔗

  * A `std::weak_ptr` is a non-owning reference to an object managed by a `std::shared_ptr` \[[08:23](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=503), [08:47](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=527)\].
  * It **doesn't increase the reference count**, so it won't prevent the object from being deleted \[[08:42](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=522)\].
  * This is useful for breaking circular dependencies between `shared_ptr`s.
  * You can check if the object is still alive using the `expired()` or `lock()` methods \[[09:24](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=564)\].

-----

### When to Use Which? 🤔

  * The general advice is to **use smart pointers whenever you're dealing with heap-allocated memory** to avoid leaks \[[09:34](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=574)\].
  * **Start with `std::unique_ptr`**. It's the most efficient and should be your default choice \[[10:33](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=633)\].
  * **Use `std::shared_ptr` only when you truly need to share ownership** of an object between multiple parts of your code \[[10:38](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=638)\].
  * While smart pointers are incredibly useful, there are still times when you might need to use raw pointers, but they should be used judiciously \[[10:12](http://www.youtube.com/watch?v=UOB7-B2MfwA&t=612)\].
