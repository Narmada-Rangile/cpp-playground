### Dynamic vs. Static Linking

The video starts by explaining the difference between **static** and **dynamic** linking:

  * **Static Linking**: This happens at **compile time**. The code from the static library is directly copied into your final executable file (`.exe`). This can lead to better optimizations because the compiler has a complete picture of all the code \[[00:35](http://www.youtube.com/watch?v=pLy69V2F_8M&t=35)\].
  * **Dynamic Linking**: This happens at **runtime**. The library (a `.dll` file on Windows) is a separate file that your program loads into memory when it starts. This means the library is not part of your executable \[[01:26](http://www.youtube.com/watch?v=pLy69V2F_8M&t=86)\].

-----

### How Dynamic Linking Works

There are two main ways a program can use a dynamic library:

1.  **Required Libraries**: Your program can be set up to require certain `.dll` files to run. If they're not found, you'll get an error like "DLL not found" \[[01:50](http://www.youtube.com/watch?v=pLy69V2F_8M&t=110)\]. This is the most common method and the one the video focuses on.
2.  **Arbitrary Loading**: Your program can be written to load `.dll` files on the fly, without them being a strict requirement at the start. This is more advanced and involves manually loading the library and getting function pointers from it \[[02:22](http://www.youtube.com/watch?v=pLy69V2F_8M&t=142)\].

-----

### How to Dynamically Link GLFW

Here are the steps to dynamically link the GLFW library in a project like yours:

1.  **Include the Header**: You still need to include the `glfw3.h` header file, just like with static linking \[[03:44](http://www.youtube.com/watch?v=pLy69V2F_8M&t=224)\].

    ```cpp
    #include <GLFW/glfw3.h>
    ```

2.  **Change the Linker Input**: In your project's properties, you need to tell the linker to use the dynamic library's import file. For GLFW, you would change `glfw3.lib` (the static library) to `glfw3dll.lib` (the dynamic library import file) \[[04:32](http://www.youtube.com/watch?v=pLy69V2F_8M&t=272)\].

3.  **Place the DLL**: The `glfw3.dll` file needs to be in a place where your executable can find it. The easiest way is to put it in the same folder as your `.exe` file \[[06:04](http://www.youtube.com/watch?v=pLy69V2F_8M&t=364)\].

-----

### A Little Mystery...

The video points out something interesting. The `glfw3.h` header uses a preprocessor directive called `GLFWAPI`. When you're building a DLL, this is defined as `__declspec(dllexport)`, and when you're using a DLL, it should be `__declspec(dllimport)`. However, even when dynamically linking, this is often not defined, and the program still works\! The video leaves this as a little puzzle for you to think about \[[08:09](http://www.youtube.com/watch?v=pLy69V2F_8M&t=489)\].

This is a great example of how you can dive deeper into the tools you use to understand them better. Since you're interested in open-sourcing your projects, understanding these linking concepts will be really helpful when you're distributing your work.

I hope these notes are useful for you\! Let me know if you have any other questions. 😊
