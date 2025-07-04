### Important Concepts:

  * **Purpose of Virtual Functions** \[[00:11](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=11)\]:

      * Virtual functions allow you to **override** methods in subclasses.
      * If a method in a base class is marked as `virtual`, a derived class can redefine that method to perform a different action.

  * **Example Scenario (Without Virtual Functions)** \[[00:35](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=35)\]:

      * The video shows a base class `Entity` with a `getName()` method that returns "Entity" \[[00:39](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=39)\].
      * A derived class `Player` inherits from `Entity` and has its own `getName()` method that returns the player's name \[[00:55](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=55)\].
      * When using **polymorphism** (referring to a `Player` object with an `Entity` pointer), calling `getName()` on the `Entity` pointer incorrectly calls the `Entity` class's `getName()` method, even though the object is a `Player` \[[01:53](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=113)\].
      * This happens because, by default, method calls are resolved at compile time based on the pointer's type, not the actual object it points to \[[03:16](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=196)\].

  * **Introducing Virtual Functions** \[[03:39](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=219)\]:

      * To fix the issue of incorrect method calls with polymorphism, the base class method needs to be marked as `virtual`.
      * Adding the `virtual` keyword to the `getName()` function in the `Entity` class tells the compiler to create a **V-table** for this function \[[04:16](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=256)\].
      * **Dynamic Dispatch and V-Table** \[[03:44](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=224)\]: Virtual functions enable "dynamic dispatch," which is usually implemented with a V-table. A V-table maps virtual functions in the base class to the correct overridden function in the derived class at runtime.

  * **`override` Keyword (C++11 and later)** \[[04:43](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=283)\]:

      * You can use the `override` keyword in the derived class to explicitly mark a function as overriding a virtual function from the base class.
      * While not strictly necessary, it improves readability and helps prevent bugs (like typos in function names or trying to override a non-virtual function) \[[04:50](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=290)\].

  * **Runtime Costs of Virtual Functions** \[[05:22](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=322)\]:

      * **Additional Memory**: Virtual functions use extra memory to store the V-table. This includes a member pointer in the base class that points to the V-table \[[05:28](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=328)\].
      * **Performance Penalty**: Every time a virtual function is called, there's a slight performance overhead because the program has to look through the V-table to find the right function to call \[[05:38](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=338)\].
      * The speaker notes that in most modern applications, these costs are minimal and usually don't significantly impact performance \[[05:50](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=350)\].

-----

### Code Examples:

**Initial Setup (Without `virtual` Keyword):**

```cpp
// Entity Class
class Entity {
public:
    std::string getName() { // Not virtual
        return "Entity";
    }
};

// Player Class (inherits from Entity)
class Player : public Entity {
public:
    std::string m_name;

    Player(const std::string& name) : m_name(name) {}

    std::string getName() { // Overrides getName, but not virtual in base
        return m_name;
    }
};

// Function to print name
void PrintName(Entity* entity) {
    std::cout << entity->getName() << std::endl;
}

// Usage
int main() {
    Entity* e = new Entity();
    Player* p = new Player("Cherno");

    PrintName(e); // Prints "Entity"
    PrintName(p); // Prints "Entity" (Incorrect for Player)
}
```

\[[00:39](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=39)\] \[[00:55](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=55)\] \[[02:00](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=120)\] \[[02:32](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=152)\]

**With `virtual` Keyword:**

```cpp
// Entity Class
class Entity {
public:
    virtual std::string getName() { // Marked as virtual
        return "Entity";
    }
};

// Player Class (inherits from Entity)
class Player : public Entity {
public:
    std::string m_name;

    Player(const std::string& name) : m_name(name) {}

    std::string getName() override { // Marked with override (optional but recommended)
        return m_name;
    }
};

// Function to print name
void PrintName(Entity* entity) {
    std::cout << entity->getName() << std::endl;
}

// Usage
int main() {
    Entity* e = new Entity();
    Player* p = new Player("Cherno");

    PrintName(e); // Prints "Entity"
    PrintName(p); // Prints "Cherno" (Correct for Player)
}
```

\[[04:16](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=256)\] \[[04:43](http://www.youtube.com/watch?v=oIV2KchSyGQ&t=283)\]
