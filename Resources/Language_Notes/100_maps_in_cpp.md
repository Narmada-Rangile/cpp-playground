### **What is a Map?**

A map is a data structure that associates a **key** with a **value**, similar to an associative array or hash table \[[00:09](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=9)\]. This allows for easy retrieval of a value using its corresponding key, acting like an index \[[01:40](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=100)\]. This is in contrast to vectors, where finding a specific element requires searching through the entire structure, which can be inefficient for frequent lookups \[[01:11](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=71)\].

***

### **Types of Maps in C++**

* **`std::map`**: This is an **ordered map**, typically implemented as a self-balancing binary search tree (like a red-black tree) \[[02:27](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=147)\]. Elements are sorted based on their keys \[[02:55](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=175)\].
* **`std::unordered_map`**: This is an **unordered map**, implemented as a hash table \[[03:11](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=191)\]. It uses a hash function to determine where to store and retrieve values, making it generally faster than `std::map` for lookups, especially with large datasets \[[03:11](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=191)\]. The speaker generally recommends using `std::unordered_map` unless sorting is required \[[03:32](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=212)\].

***

### **Practical Example: City Records**

The video demonstrates storing `CityRecord` objects (containing name, population, latitude, longitude) \[[03:45](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=225)\]. It shows the inefficiency of using a `std::vector` for retrieving specific city data, as it requires iterating and comparing names \[[04:46](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=286)\]. The solution is to use a `std::map` (or `std::unordered_map`) where the city name (`std::string`) acts as the key and the `CityRecord` as the value, allowing for direct and fast lookups \[[06:08](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=368)\].

***

### **Key Requirements for Map Keys**

* For `std::unordered_map`, the key type must be **hashable** \[[09:32](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=572)\]. If using a custom type (like `CityRecord`), you need to provide a custom hash function by specializing `std::hash` \[[12:10](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=730)\]. The video provides a detailed example of how to implement this \[[12:42](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=762)\].
* For `std::map`, the key type must have a **less-than operator (`<`)** defined \[[09:38](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=578)\]. This is crucial for the map to sort its elements \[[25:57](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=1557)\]. The video demonstrates how to define this operator within a custom struct \[[26:08](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=1568)\].

***

### **Map Operations**

* **Insertion**: Elements can be inserted using an initializer list syntax \[[06:51](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=411)\] or by using the index operator (`[]`) \[[16:53](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=1013)\].
* **Retrieval**:
    * The index operator (`[]`) can be used for retrieval \[[07:36](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=456)\]. A crucial point is that this operator will **insert** a default-constructed element if the key does not exist, and it does not have a `const` version \[[17:01](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=1021)\].
    * `dot at()`: This method is used to retrieve elements and will **throw an exception** if the key is not found \[[18:52](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=1132)\]. It is also `const`-correct \[[20:02](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=1202)\].
    * `dot find()`: This method is used to check if a key exists in the map before attempting to access it, returning an iterator to the element or `end()` if not found \[[20:40](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=1240)\].
* **Iteration**: Maps can be iterated using a range-based for loop \[[22:09](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=1329)\]. With C++17 and above, structured bindings can be used to directly access the key and value \[[23:27](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=1407)\].
* **Erasure**: Elements can be removed using `citymap.erase(key)` \[[24:50](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=1490)\].

***

### **Performance Considerations**

* `std::unordered_map` is generally **faster for lookups** than `std::map`, especially with large datasets, due to its hash table implementation \[[28:48](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=1728)\].
* `std::map` generally performs **better when iterating** through elements compared to `std::unordered_map`, but both are significantly slower than iterating through a `std::vector` \[[28:54](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=1734)\].
* The speaker emphasizes that for small datasets, the performance difference might be negligible \[[28:37](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=1717)\].
* For scenarios requiring frequent iteration and less frequent lookups, a `std::vector` is still the most performant choice \[[29:00](http://www.youtube.com/watch?v=KiB0vRi2wlc&t=1740)\].
