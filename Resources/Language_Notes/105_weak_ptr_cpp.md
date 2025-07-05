### **What is a Weak Pointer?**

* A `std::weak_ptr` is a C++ standard library class designed to be used with `std::shared_ptr` \[[01:01](http://www.youtube.com/watch?v=M0GLQEfplxs&t=61)\].
* It allows you to have a reference to an object managed by a `shared_ptr` without creating a "strong" or "owning" reference \[[05:42](http://www.youtube.com/watch?v=M0GLQEfplxs&t=342)\]. This means a `weak_ptr` does not prevent the object from being deleted when all `shared_ptr` references are gone \[[05:49](http://www.youtube.com/watch?v=M0GLQEfplxs&t=349)\].

***

### **Shared Pointers and Strong References**

* A `shared_ptr` is a wrapper around a raw pointer that automates lifetime management of heap-allocated objects \[[01:12](http://www.youtube.com/watch?v=M0GLQEfplxs&t=72)\].
* The "magic" of `shared_ptr` is its ability to be shared across multiple parts of a program. The underlying object is only deleted when all `shared_ptr` instances referencing it are out of scope \[[01:56](http://www.youtube.com/watch?v=M0GLQEfplxs&t=116)\].
* `shared_ptr`s are considered **"strong references"** because they keep the object alive as long as they exist \[[03:17](http://www.youtube.com/watch?v=M0GLQEfplxs&t=197)\]. They are also called "owning references" as they share ownership of the object \[[05:17](http://www.youtube.com/watch?v=M0GLQEfplxs&t=317)\].

***

### **Problems with Raw Pointers**

* Using raw pointers to observe objects managed by `shared_ptr`s can lead to issues \[[06:03](http://www.youtube.com/watch?v=M0GLQEfplxs&t=363)\]. If the object is deleted, the raw pointer becomes a dangling pointer, and attempting to access it will cause a crash \[[06:59](http://www.youtube.com/watch?v=M0GLQEfplxs&t=419)\].
* There's no built-in way to check if a raw pointer, obtained from a `shared_ptr`, is still valid after the object it points to has been deleted \[[07:04](http://www.youtube.com/watch?v=M0GLQEfplxs&t=424)\].

***

### **How Weak Pointers Solve the Problem**

* `weak_ptr`s provide a **"weak reference"** to an object, meaning they don't contribute to the object's reference count \[[08:46](http://www.youtube.com/watch?v=M0GLQEfplxs&t=526)\].
* To safely use the object referenced by a `weak_ptr`, you must first convert it to a `shared_ptr` using the `lock()` method \[[09:25](http://www.youtube.com/watch?v=M0GLQEfplxs&t=565)\].
* If `lock()` returns a valid `shared_ptr`, it means the object is still alive, and this temporary `shared_ptr` will keep it alive for the duration of its scope \[[10:40](http://www.youtube.com/watch?v=M0GLQEfplxs&t=640)\]. If `lock()` returns a null `shared_ptr`, the object has been deleted \[[09:32](http://www.youtube.com/watch?v=M0GLQEfplxs&t=572)\].
* You can also use the `expired()` function to check if the object has been deleted without necessarily needing to use it \[[11:08](http://www.youtube.com/watch?v=M0GLQEfplxs&t=668)\].
* The `use_count()` function can tell you how many strong `shared_ptr` references currently exist for the object \[[11:24](http://www.youtube.com/watch?v=M0GLQEfplxs&t=684)\].

***

### **Use Cases for Weak Pointers**

* **Breaking Cyclical Dependencies:** `weak_ptr`s are mandatory when you have objects that hold `shared_ptr`s to each other (cyclical dependencies). Without `weak_ptr`s, these objects would never be destroyed due to their mutual strong references \[[12:49](http://www.youtube.com/watch?v=M0GLQEfplxs&t=769)\].
* **Observer Pattern:** In scenarios like an observer pattern, where observers need to access an object but shouldn't prevent its destruction, `weak_ptr`s provide a safe way to manage these non-owning references \[[13:54](http://www.youtube.com/watch?v=M0GLQEfplxs&t=834)\].
* **Debugging and UI Display:** They are useful for debugging or displaying information in a UI where you want to track an object if it's valid, but not keep it alive \[[16:41](http://www.youtube.com/watch?v=M0GLQEfplxs&t=1001)\].

The video emphasizes that while `weak_ptr`s add some overhead, it's often negligible and necessary in situations where raw pointers are unsafe or `shared_ptr`s create unwanted ownership cycles \[[12:01](http://www.youtube.com/watch?v=M0GLQEfplxs&t=721)\].
