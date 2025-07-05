### **Null in Managed Languages vs. C++** \[[00:00](http://www.youtube.com/watch?v=PksUUwvq-po&t=0)\]

In managed languages, using a null object results in a null reference or null pointer exception. C++ handles `null` differently, which is the focus of the video.

***

### **Value of `nullptr` in C++** \[[00:15](http://www.youtube.com/watch?v=PksUUwvq-po&t=15)\]

* In C++, **`nullptr`** is used instead of a `null` keyword \[[00:26](http://www.youtube.com/watch?v=PksUUwvq-po&t=26)\].
* When a `void` pointer is set to `nullptr`, its value in memory is `0x0000000000000000` (eight bytes of zeros on a 64-bit architecture) \[[00:37](http://www.youtube.com/watch?v=PksUUwvq-po&t=37)\], \[[01:02](http://www.youtube.com/watch?v=PksUUwvq-po&t=62)\].
* This means `nullptr` is essentially stored as **zero** in memory \[[01:19](http://www.youtube.com/watch?v=PksUUwvq-po&t=79)\].

***

### **The `NULL` Macro** \[[01:21](http://www.youtube.com/watch?v=PksUUwvq-po&t=81)\]

* The **`NULL` macro** (all caps) is another way to represent null in C++, though it's more commonly used in C \[[01:27](http://www.youtube.com/watch?v=PksUUwvq-po&t=87)\].
* `NULL` is also defined as **zero** \[[01:52](http://www.youtube.com/watch?v=PksUUwvq-po&t=112)\].
* Setting an integer to `NULL` is valid because `NULL` is just zero \[[02:17](http://www.youtube.com/watch?v=PksUUwvq-po&t=137)\].

***

### **Why Null Pointers Crash Programs** \[[02:34](http://www.youtube.com/watch?v=PksUUwvq-po&t=154)\]

* Pointers are memory addresses, and **zero is not a valid memory address** \[[02:41](http://www.youtube.com/watch?v=PksUUwvq-po&t=161)\].
* Attempting to read from an invalid memory address (like zero) results in an **"access violation"** or **"read access violation"** \[[02:49](http://www.youtube.com/watch?v=PksUUwvq-po&t=169)\]. This occurs when the operating system determines that the memory address is not valid or accessible \[[02:56](http://www.youtube.com/watch?v=PksUUwvq-po&t=176)\].

***

### **Null with Objects and Member Functions** \[[03:22](http://www.youtube.com/watch?v=PksUUwvq-po&t=202)\]

* When an object pointer is explicitly set to `nullptr` (e.g., `Entity* entity = nullptr;`), attempting to call a member function that accesses member variables will cause a **crash** (an access violation) \[[05:00](http://www.youtube.com/watch?v=PksUUwvq-po&t=300)\], \[[05:05](http://www.youtube.com/watch?v=PksUUwvq-po&t=305)\].
* However, calling a member function on a null object that **does not** access any member variables (e.g., `printType` which only prints a string literal) will **not** crash the program \[[08:03](http://www.youtube.com/watch?v=PksUUwvq-po&t=483)\], \[[08:09](http://www.youtube.com/watch?v=PksUUwvq-po&t=489)\].

***

### **How Member Functions are Compiled** \[[08:48](http://www.youtube.com/watch?v=PksUUwvq-po&t=528)\]

* In C++, member functions are compiled into regular free-floating functions that implicitly take a pointer to the class instance as their first parameter, known as the **`this` pointer** \[[10:17](http://www.youtube.com/watch?v=PksUUwvq-po&t=617)\], \[[10:23](http://www.youtube.com/watch?v=PksUUwvq-po&t=623)\].
* If a member function is `const`, the `this` pointer passed to it is also `const` \[[10:54](http://www.youtube.com/watch?v=PksUUwvq-po&t=654)\].
* **Static functions do not take an instance pointer**, which is why they cannot access non-static member variables \[[11:17](http://www.youtube.com/watch?v=PksUUwvq-po&t=677)\].
* The crash occurs when a member function, called on a null `this` pointer, attempts to dereference or access a member variable, because it tries to read from an invalid memory address (e.g., `null + offset`) \[[11:51](http://www.youtube.com/watch?v=PksUUwvq-po&t=711)\], \[[12:21](http://www.youtube.com/watch?v=PksUUwvq-po&t=741)\].

***

### **`offsetof` Macro** \[[13:35](http://www.youtube.com/watch?v=PksUUwvq-po&t=815)\]

* The **`offsetof` macro** can be used to determine the memory offset of a member variable within a class or struct \[[13:41](http://www.youtube.com/watch?v=PksUUwvq-po&t=821)\].
* It works by casting zero to a pointer of the class type and then getting the address of the member variable relative to that zero address \[[15:00](http://www.youtube.com/watch?v=PksUUwvq-po&t=900)\]. This operation does not involve reading from memory, only calculating an address, so it does not crash even when using a "null" base address \[[15:49](http://www.youtube.com/watch?v=PksUUwvq-po&t=949)\].
* The "read access violation" message often includes the offset value (e.g., "this was 8") because it's trying to read from `null + offset` \[[17:02](http://www.youtube.com/watch?v=PksUUwvq-po&t=1022)\], \[[17:21](http://www.youtube.com/watch?v=PksUUwvq-po&t=1041)\].
