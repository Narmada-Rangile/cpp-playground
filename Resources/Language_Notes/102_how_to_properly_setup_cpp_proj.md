### **Core-App Architecture** \[[00:04](http://www.youtube.com/watch?v=5glH8dGoeCA&t=4)\]

This architecture involves a **core library** of code used by one or more applications. The presenter highlights its versatility, citing examples like the Walnut Chat instant messaging client and the Hazel game engine \[[00:30](http://www.youtube.com/watch?v=5glH8dGoeCA&t=30)\].

***

### **Project Setup with Templates** \[[00:41](http://www.youtube.com/watch?v=5glH8dGoeCA&t=41)\]

The video introduces a C++ project template that simplifies setting up new projects. It also demonstrates how to adapt existing projects to this architecture \[[00:45](http://www.youtube.com/watch?v=5glH8dGoeCA&t=45)\].

***

### **Build Systems (CMake vs. Premake)** \[[01:37](http://www.youtube.com/watch?v=5glH8dGoeCA&t=97)\]

The presenter explains the role of build systems in compiling raw code files into a product. While CMake is mentioned, the video focuses on **Premake** \[[02:00](http://www.youtube.com/watch?v=5glH8dGoeCA&t=120)\], which uses Lua for simpler project descriptions and can generate various project files (e.g., Visual Studio, Xcode, Makefiles) for cross-platform development \[[02:45](http://www.youtube.com/watch?v=5glH8dGoeCA&t=165)\].

***

### **Using the Template** \[[05:12](http://www.youtube.com/watch?v=5glH8dGoeCA&t=312)\]

The video provides a step-by-step guide on using the template, including cloning the repository, running setup scripts, and understanding the generated solution and project files \[[05:28](http://www.youtube.com/watch?v=5glH8dGoeCA&t=328)\].

***

### **Customizing the Template** \[[07:09](http://www.youtube.com/watch?v=5glH8dGoeCA&t=429)\]

Instructions are given on how to modify the `build.lua` file to change project names, configurations, and include directories \[[07:12](http://www.youtube.com/watch?v=5glH8dGoeCA&t=432)\].

***

### **Retrofitting Existing Projects** \[[10:29](http://www.youtube.com/watch?v=5glH8dGoeCA&t=629)\]

A significant portion of the video is dedicated to demonstrating how to apply this architecture to an existing project, specifically a 2D game engine from a code review series \[[10:53](http://www.youtube.com/watch?v=5glH8dGoeCA&t=653)\]. This involves:

* Migrating common code to a "core" project \[[15:38](http://www.youtube.com/watch?v=5glH8dGoeCA&t=938)\].
* Creating separate "app" projects for different functionalities (e.g., editor and runtime) \[[16:02](http://www.youtube.com/watch?v=5glH8dGoeCA&t=962)\].
* Adjusting include directories and pre-processor definitions \[[22:06](http://www.youtube.com/watch?v=5glH8dGoeCA&t=1326)\].
* Addressing challenges when existing projects have significant code divergence between different application variants \[[29:49](http://www.youtube.com/watch?v=5glH8dGoeCA&t=1789)\].
