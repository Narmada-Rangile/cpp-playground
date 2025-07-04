### Important Concepts:

  * **Pure Virtual Functions** \[[00:04](http://www.youtube.com/watch?v=UWAdd13EfM8&t=4)\]

      * A pure virtual function in C++ is like an abstract method or interface in other languages like Java or C\#.
      * It lets you define a function in a base class without an implementation, which forces subclasses to provide their own definition \[[00:21](http://www.youtube.com/watch?v=UWAdd13EfM8&t=21)\].
      * Unlike regular virtual functions, where overriding is optional \[[00:45](http://www.youtube.com/watch?v=UWAdd13EfM8&t=45)\], pure virtual functions **must** be implemented by subclasses \[[01:02](http://www.youtube.com/watch?v=UWAdd13EfM8&t=62)\].
      * To declare a pure virtual function, you set it equal to `0` in the base class declaration, like this: `virtual string GetClassName() = 0;` \[[01:34](http://www.youtube.com/watch?v=UWAdd13EfM8&t=94)\].
      * A class that has one or more pure virtual functions cannot be instantiated directly \[[01:55](http://www.youtube.com/watch?v=UWAdd13EfM8&t=115)\]. You can only instantiate a class if all its pure virtual functions (or those inherited from its hierarchy) are implemented \[[02:20](http://www.youtube.com/watch?v=UWAdd13EfM8&t=140)\].

  * **Interfaces** \[[01:08](http://www.youtube.com/watch?v=UWAdd13EfM8&t=68)\]

      * In object-oriented programming, an **interface** is a class that is made up only of unimplemented methods (pure virtual functions) \[[01:08](http://www.youtube.com/watch?v=UWAdd13EfM8&t=68)\].
      * It acts as a template, forcing subclasses to implement these methods \[[01:15](http://www.youtube.com/watch?v=UWAdd13EfM8&t=75)\].
      * C++ doesn't have a specific `interface` keyword; interfaces are just classes with pure virtual functions \[[04:07](http://www.youtube.com/watch?v=UWAdd13EfM8&t=247)\].
      * Interfaces are useful for making sure that a certain function exists in any class that implements the interface \[[05:54](http://www.youtube.com/watch?v=UWAdd13EfM8&t=354)\].

-----

### Example of Pure Virtual Function and Interface Usage \[[02:47](http://www.youtube.com/watch?v=UWAdd13EfM8&t=167)\]

  * The video shows how to create a `Printable` interface to make sure that any class passed to a `Print` function has a `GetClassName` method.

  * **`Printable` Class (Interface):**

    ```cpp
    // In a new file called printable.h
    class Printable {
    public:
        virtual std::string GetClassName() = 0; // Pure virtual function
    };
    ```

    \[[03:28](http://www.youtube.com/watch?v=UWAdd13EfM8&t=208)\]

  * **`Entity` Class Implementing `Printable`:**

    ```cpp
    // In entity.h
    #include "Printable.h"

    class Entity : public Printable { // Inherits from Printable
    public:
        // ... other members ...
        std::string GetClassName() override { // Implementation of pure virtual function
            return "Entity";
        }
    };
    ```

    \[[03:45](http://www.youtube.com/watch?v=UWAdd13EfM8&t=225)\], \[[04:18](http://www.youtube.com/watch?v=UWAdd13EfM8&t=258)\]

  * **`Player` Class (inherits from `Entity`, so it also implements `Printable`):**

    ```cpp
    // In player.h
    #include "Entity.h"

    class Player : public Entity {
    public:
        // ... other members ...
        std::string GetClassName() override { // Overrides GetClassName from Entity
            return "Player";
        }
    };
    ```

    \[[04:59](http://www.youtube.com/watch?v=UWAdd13EfM8&t=299)\]

  * **`Print` Function:**

    ```cpp
    void Print(Printable* obj) { // Takes a pointer to a Printable object
        std::cout << obj->GetClassName() << std::endl;
    }
    ```

    \[[02:52](http://www.youtube.com/watch?v=UWAdd13EfM8&t=172)\], \[[03:09](http://www.youtube.com/watch?v=UWAdd13EfM8&t=189)\]

  * **Usage in `main`:**

    ```cpp
    int main() {
        Entity* e = new Entity();
        Player* p = new Player();

        Print(e); // Prints "Entity"
        Print(p); // Prints "Player"

        // Example of another class implementing Printable
        class A : public Printable {
        public:
            std::string GetClassName() override {
                return "A";
            }
        };
        A* a = new A();
        Print(a); // Prints "A"

        delete e;
        delete p;
        delete a; // Remember to free memory
        return 0;
    }
    ```

    \[[04:42](http://www.youtube.com/watch?v=UWAdd13EfM8&t=282)\], \[[05:33](http://www.youtube.com/watch?v=UWAdd13EfM8&t=333)\]

  * **Key Takeaway:** Pure virtual functions and interfaces are mainly used to guarantee that a specific function exists and is implemented in derived classes, which allows for more generic and flexible code \[[06:10](http://www.youtube.com/watch?v=UWAdd13EfM8&t=370)\].
