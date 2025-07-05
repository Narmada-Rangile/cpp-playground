### What is an Operator?

An **operator** is a symbol used to perform an action, often as a more intuitive alternative to a function \[[00:09](http://www.youtube.com/watch?v=mS9755gF66w&t=9)\]. Besides the usual math operators, C++ has many others, like `*` (dereference), `->` (arrow), `<<` (bit shift left), and `new` \[[00:22](http://www.youtube.com/watch?v=mS9755gF66w&t=22)\].

-----

### Operator Overloading

**Operator overloading** lets you define or change the behavior of an operator for your own classes \[[01:21](http://www.youtube.com/watch?v=mS9755gF66w&t=81)\]. It's a feature that's not available in languages like Java. Essentially, operators are just functions, so instead of a function named "add," you can use the `+` operator \[[02:03](http://www.youtube.com/watch?v=mS9755gF66w&t=123)\].

**Best Practices:**

  * Use it sparingly and only when it makes sense \[[02:34](http://www.youtube.com/watch?v=mS9755gF66w&t=154)\].
  * The overloaded operator's behavior should be obvious without needing to look at its definition \[[02:40](http://www.youtube.com/watch?v=mS9755gF66w&t=160)\].

-----

### Code Examples

Here are some examples from the video, using a `Vector2` struct.

  * **Vector2 Struct Definition** \[[03:04](http://www.youtube.com/watch?v=mS9755gF66w&t=184)\]:

    ```cpp
    struct Vector2 {
        float x, y;

        Vector2(float x, float y)
            : x(x), y(y) {}
    };
    ```

  * **Overloading `+` and `*` Operators** \[[05:05](http://www.youtube.com/watch?v=mS9755gF66w&t=305)\]:

    ```cpp
    // Inside Vector2 struct
    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator*(const Vector2& other) const {
        return Vector2(x * other.x, y * other.y);
    }

    // Usage
    Vector2 position(4.5f, 5.5f);
    Vector2 speed(0.5f, 0.15f);
    Vector2 powerUp(2.0f, 2.0f);

    Vector2 result = position + speed * powerUp; // Much cleaner!
    ```

  * **Overloading `<<` for `std::cout`** \[[07:42](http://www.youtube.com/watch?v=mS9755gF66w&t=462)\]:
    This lets you print `Vector2` objects directly.

    ```cpp
    // Outside Vector2 struct
    std::ostream& operator<<(std::ostream& stream, const Vector2& other) {
        stream << other.x << ", " << other.y;
        return stream;
    }

    // Usage
    std::cout << result << std::endl;
    ```

  * **Overloading `==` and `!=` Operators** \[[10:20](http://www.youtube.com/watch?v=mS9755gF66w&t=620)\]:
    This allows for direct comparison of `Vector2` objects.

    ```cpp
    // Inside Vector2 struct
    bool operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2& other) const {
        return !(*this == other); // Calls the overloaded ==
    }
    ```

The key takeaway is to use operator overloading to improve code readability, but to do so thoughtfully \[[09:36](http://www.youtube.com/watch?v=mS9755gF66w&t=576)\]. It's often a good idea to provide both an overloaded operator and a named function (like `Add` and `operator+`) to give other developers a choice \[[11:37](http://www.youtube.com/watch?v=mS9755gF66w&t=697)\].
