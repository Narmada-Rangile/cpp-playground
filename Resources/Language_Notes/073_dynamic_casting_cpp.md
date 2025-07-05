### **Casting in C++**

  * Casting is a way to **convert between different types** in C++ \[[00:27](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=27)\].
  * C++ offers different casting methods, including C-style casts (e.g., `(NewType)variable`) and C++ style casts like `static_cast`, `const_cast`, and `dynamic_cast` \[[01:03](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=63)\].
  * `dynamic_cast` is a C++ specific cast that performs extra validation to ensure the cast is **valid at runtime** \[[01:16](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=76)\].

-----

### **Dynamic Cast Specifics**

  * `dynamic_cast` is evaluated at **runtime**, which incurs a performance cost \[[02:04](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=124)\].
  * It is primarily used for casts along the **inheritance hierarchy** \[[02:27](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=147)\].
  * **Example Scenario**: If you have an `Entity` base class and `Player` and `Enemy` derived classes \[[02:55](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=175)\]:
      * Casting a `Player` object to an `Entity` object can be done implicitly \[[03:12](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=192)\].
      * Casting an `Entity` object to a `Player` object is more complex because the `Entity` might actually be an `Enemy` \[[03:28](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=208)\].
  * **Validation**: `dynamic_cast` validates if the object is truly of the target type. If the cast is invalid (e.g., casting an `Enemy` object to a `Player`), it returns a **null pointer** \[[04:27](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=267)\]. This allows you to check if an object is a specific type \[[04:45](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=285)\].

-----

### **Code Example and Demonstration**

  * The video demonstrates a basic setup with `Entity`, `Player`, and `Enemy` classes \[[05:08](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=308)\].
  * **Class Definitions**:
    ```cpp
    class Entity {
    public:
        virtual void printName() {} // Makes the class polymorphic
    };

    class Player : public Entity {
    };

    class Enemy : public Entity {
    };
    ```
    \[[05:13](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=313)\]
  * **Casting Example**:
    ```cpp
    Player* player = new Player();
    Enemy* enemy = new Enemy();

    Entity* actuallyPlayer = player;
    Entity* actuallyEnemy = enemy;

    // This cast will succeed because actuallyPlayer is a Player
    Player* p1 = dynamic_cast<Player*>(actuallyPlayer);

    // This cast will fail and return nullptr because actuallyEnemy is an Enemy
    Player* p0 = dynamic_cast<Player*>(actuallyEnemy);
    ```
    \[[08:38](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=518)\]
  * The demonstration shows that `p0` becomes `nullptr` when the cast fails, while `p1` successfully casts to a `Player` \[[09:19](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=559)\].

-----

### **Polymorphic Class Types and RTTI**

  * `dynamic_cast` only works with **polymorphic class types**, which means the base class must have at least one virtual function \[[07:59](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=479)\]. This creates a virtual function table (V-table) \[[08:04](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=484)\].
  * `dynamic_cast` relies on **Runtime Type Information (RTTI)** \[[10:12](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=612)\]. RTTI stores information about types at runtime, enabling `dynamic_cast` to perform its validation \[[10:17](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=617)\].
  * **Overhead**: RTTI adds overhead because types need to store more information, and `dynamic_cast` itself takes time to perform the runtime validation \[[10:28](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=628)\].
  * **Disabling RTTI**: You can disable RTTI in your compiler settings (e.g., in Visual Studio under C/C++ \> Language \> Enable Run-Time Type Information) \[[11:04](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=664)\]. If RTTI is off, `dynamic_cast` will lead to unpredictable behavior or crashes \[[11:34](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=694)\].

-----

### **Practical Use and Considerations**

  * `dynamic_cast` can be used to check if an object is of a specific type, similar to `is` in C\# or `instanceof` in Java \[[12:31](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=751)\].
  * **Example of checking type**:
    ```cpp
    if (Player* p0 = dynamic_cast<Player*>(actuallyEnemy)) {
        // This code will only execute if actuallyEnemy is a Player
        // (which it isn't in this example, so it won't execute)
    }
    ```
    \[[12:57](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=777)\]
  * While useful for validation, `dynamic_cast` incurs a **performance cost**, so it should be used judiciously, especially in performance-critical code \[[13:22](http://www.youtube.com/watch?v=CiHfz6pTolQ&t=802)\].
