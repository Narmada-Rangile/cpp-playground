### Key Concepts of Visibility in C++:

  * **Purpose of Visibility**

      * Visibility doesn't affect how the program runs or its performance \[[00:27](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=27)\].
      * It's used to organize code and make it more maintainable and understandable \[[00:34](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=34)\].
      * It helps developers know how to use a class correctly and prevents accidental access to its internal parts \[[05:05](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=305)\].

  * **Visibility Modifiers**

      * C++ has three main visibility modifiers: `private`, `protected`, and `public` \[[00:40](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=40)\].
      * Other languages like Java and C\# have more modifiers, but C++ only has these three \[[00:46](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=46)\].

  * **Default Visibility**

      * For a `class`, the default visibility is `private` \[[01:10](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=70)\].
        ```cpp
        class Entity {
            int x, y; // This is private by default
        };
        ```
      * For a `struct`, the default visibility is `public` \[[01:23](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=83)\].
        ```cpp
        struct Entity {
            int x, y; // This is public by default
        };
        ```

  * **`private` Visibility**

      * Members declared as `private` can only be accessed by the class itself \[[01:50](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=110)\].
      * This means only methods inside the `Entity` class can read or write to `x` and `y` if they are private \[[01:56](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=116)\].
      * **Exception:** A `friend` class or function can access private members \[[02:02](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=122)\].
      * **Example:**
        ```cpp
        class Entity {
        private:
            int x, y;

        public:
            Entity() {
                x = 0; // Accessible within the class
            }

            void Print() {
                // Accessible within the class
            }
        };

        class Player : public Entity {
        public:
            Player() {
                // Cannot access x or Print() directly here if they are private in Entity
                // x = 1; // Error
                // Print(); // Error
            }
        };

        int main() {
            Entity e;
            // e.x = 5; // Error: Cannot access from outside the class scope
            // e.Print(); // Error: Cannot access from outside the class scope
            return 0;
        }
        ```

  * **`protected` Visibility**

      * Members declared as `protected` can be accessed by the class itself and all of its subclasses \[[03:22](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=202)\].
      * **Example:**
        ```cpp
        class Entity {
        protected:
            int x, y;

        public:
            void Print() {
                // Accessible within the class
            }
        };

        class Player : public Entity {
        public:
            Player() {
                x = 1; // Accessible within subclass
                Print(); // Accessible within subclass
            }
        };

        int main() {
            Entity e;
            // e.x = 5; // Error: Cannot access from outside the class
            // e.Print(); // Error: Cannot access from outside the class
            return 0;
        }
        ```

  * **`public` Visibility**

      * Members declared as `public` can be accessed by anyone, from anywhere \[[03:55](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=235)\].
      * This includes the class itself, subclasses, and external functions like `main` \[[04:01](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=241)\].
      * **Example:**
        ```cpp
        class Entity {
        public:
            int x, y;

            void Print() {
                // Accessible within the class
            }
        };

        class Player : public Entity {
        public:
            Player() {
                x = 1; // Accessible within subclass
                Print(); // Accessible within subclass
            }
        };

        int main() {
            Entity e;
            e.x = 5; // Accessible from outside the class
            e.Print(); // Accessible from outside the class
            return 0;
        }
        ```

  * **Why Not Make Everything Public?**

      * Making everything public is considered bad practice because it makes the code harder to maintain and understand \[[04:25](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=265)\].
      * It helps define how a class is meant to be used, guiding other developers (and your future self) on which parts of the class should be interacted with directly \[[05:05](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=305)\].
      * It prevents accidental misuse or breaking of internal logic \[[05:59](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=359)\]. For example, a `SetPosition` method might not only change `x` and `y` but also trigger a display refresh, which direct access to `x` and `y` would not \[[06:45](http://www.youtube.com/watch?v=6OVQ8nh3KP0&t=405)\].
