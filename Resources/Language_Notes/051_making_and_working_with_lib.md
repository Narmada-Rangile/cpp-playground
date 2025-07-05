This video explains how to set up and use multiple projects in Visual Studio, with a focus on creating and linking a static library in C++. This is a great way to organize your code, especially for larger projects. Since you're into programming and have experience with C++, you'll find this very useful for your own projects.

### Key Concepts

  * **Introduction to Multiple Projects and Libraries** \[[00:00](http://www.youtube.com/watch?v=Wt4dxDNmDA8&t=0)\]

      * Using multiple projects in Visual Studio helps in creating modular and reusable code.
      * This is essential for large projects and allows for the creation of libraries that can be shared across different parts of an application.
      * The video demonstrates this by creating a static library and linking it to an executable file.

  * **Setting up a New Solution and Projects** \[[00:37](http://www.youtube.com/watch?v=Wt4dxDNmDA8&t=37)\]

      * You start by creating an empty folder for your solution.
      * In Visual Studio, you create a new empty C++ project. This will be your main executable.
      * Then, you add another empty project to the solution, which will serve as your static library.

  * **Configuring Project Types** \[[02:13](http://www.youtube.com/watch?v=Wt4dxDNmDA8&t=133)\]

      * You need to configure the project types for both projects.
      * The main project should be set as an **Application (.exe)**.
      * The library project should be set as a **Static Library (.lib)**.

  * **Structuring Source Files** \[[02:54](http://www.youtube.com/watch?v=Wt4dxDNmDA8&t=174)\]

      * It's a good practice to create a `Source` folder within each project to keep your files organized.
      * You'll have your main application file (e.g., `application.cpp`) in the executable project and your library files (e.g., `engine.h` and `engine.cpp`) in the library project.

  * **Writing Library Code (Engine Project)** \[[03:28](http://www.youtube.com/watch?v=Wt4dxDNmDA8&t=208)\]

      * Here's an example of the code for the library:
          * **`engine.h`**:
            ```cpp
            namespace Engine
            {
                void PrintMessage();
            }
            ```
          * **`engine.cpp`**: \[[03:42](http://www.youtube.com/watch?v=Wt4dxDNmDA8&t=222)\]
            ```cpp
            #include "engine.h"
            #include <iostream>

            namespace Engine
            {
                void PrintMessage()
                {
                    std::cout << "Hello World" << std::endl;
                }
            }
            ```

  * **Including Header Files in the Executable Project** \[[04:13](http://www.youtube.com/watch?v=Wt4dxDNmDA8&t=253)\]

      * To use the library's functions, you need to include its header file in your main application.
      * Instead of using relative paths, it's better to add the library's source directory to the **Additional Include Directories** in the project properties. This makes your project more robust.
          * You can use the `$(SolutionDir)` macro to easily reference the solution's directory.

  * **Linking the Static Library** \[[08:00](http://www.youtube.com/watch?v=Wt4dxDNmDA8&t=480)\]

      * The best way to link the library is by adding a **project reference**.
      * This automatically links the generated `.lib` file and sets up a dependency, so the library is always up-to-date when you build your main application.

  * **Testing the Application** \[[09:47](http://www.youtube.com/watch?v=Wt4dxDNmDA8&t=587)\]

      * Here's how you can test the setup in your `application.cpp`:
        ```cpp
        #include "engine.h"
        #include <iostream>

        int main()
        {
            Engine::PrintMessage();
            std::cin.get();
            return 0;
        }
        ```
      * When you run this, it should print "Hello World" to the console. \[[10:15](http://www.youtube.com/watch?v=Wt4dxDNmDA8&t=615)\]

  * **Static Linking Outcome** \[[10:33](http://www.youtube.com/watch?v=Wt4dxDNmDA8&t=633)\]

      * With static linking, all the library's code is compiled into a single executable file. This makes it easy to distribute your application without needing to share separate library files. \[[10:48](http://www.youtube.com/watch?v=Wt4dxDNmDA8&t=648)\]

  * **Advantages of Modularization** \[[11:08](http://www.youtube.com/watch?v=Wt4dxDNmDA8&t=668)\]

      * This approach helps you centralize your core code, like a game engine, into a single project.
      * You can then have multiple applications or examples within the same solution that all link to this central library. This is a very powerful and organized way to work on your projects.
