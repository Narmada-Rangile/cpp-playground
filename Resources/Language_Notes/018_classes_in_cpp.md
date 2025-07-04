### \#\# Why Do We Need Classes?

Imagine you're creating a simple 2D game. Without classes, you might store your player's data like this:

```cpp
int playerX, playerY;
int playerSpeed;

void MovePlayer(int xa, int ya) {
    playerX += xa * playerSpeed;
    playerY += ya * playerSpeed;
}
```

This gets messy fast. What if you want a second player? You'd have to create `playerX2`, `playerY2`, etc. It's disorganized and hard to maintain \[[01:42:00](http://www.youtube.com/watch?v=2BP8NhxjrO0&t=6120)\].

A **class** solves this by letting you create your own custom type that groups related data (variables) and functions (methods) together \[[00:55](http://www.youtube.com/watch?v=2BP8NhxjrO0&t=55)\]. Think of it as a blueprint for creating objects.

-----

### \#\# Defining and Using a Class

You define a class using the `class` keyword. Let's refactor the player example into a `Player` class.

**Key Concepts:**

  * **Object**: An "instance" of a class. `player` is an object of the `Player` class \[[03:39:00](http://www.youtube.com/watch?v=2BP8NhxjrO0&t=13140)\].
  * **Members**: The variables (`x`, `y`, `speed`) and functions (`Move`) inside a class.
  * **`public`**: A visibility keyword. By default, all members of a class are `private` (only accessible from within the class). Making them `public` allows you to access them from outside, like in your `main` function \[[04:21:00](http://www.youtube.com/watch?v=2BP8NhxjrO0&t=15660)\].
  * **Accessing Members**: You use the dot operator (`.`) to access the members of an object.

#### \#\#\# Code Example: The `Player` Class

```cpp
// Define the blueprint for a Player
class Player
{
public: // Make the members accessible from outside
    int x, y;
    int speed;

    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};

int main()
{
    // Create an instance (an object) of the Player class
    Player player;

    // Access and modify its data
    player.x = 5;
    player.y = 5;
    player.speed = 2;

    // Call its method to perform an action
    player.Move(1, -1); // Move the player

    return 0;
}
```

*\[[04:44:00](http://www.youtube.com/watch?v=2BP8NhxjrO0&t=17040)\]*

This is much cleaner\! Now, if you want another player, you can just create another `Player` object (`Player player2;`) without duplicating all the variables.
