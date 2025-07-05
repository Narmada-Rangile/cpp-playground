### **What are Precompiled Headers?**

* Precompiled headers allow you to group multiple header files and convert them into a compiled format \[[01:12](http://www.youtube.com/watch?v=eSI4wctZUto&t=72)\].
* This compiled format is faster for the compiler to use than repeatedly reading and compiling the original text-based header files \[[01:19](http://www.youtube.com/watch?v=eSI4wctZUto&t=79)\].
* For example, including `<vector>` in multiple C++ files means the entire `vector` header and its dependencies (potentially 100,000 lines of code) are parsed and compiled every time \[[01:51](http://www.youtube.com/watch?v=eSI4wctZUto&t=111)\]. Precompiled headers avoid this repetitive process \[[03:55](http://www.youtube.com/watch?v=eSI4wctZUto&t=235)\].

***

### **Benefits of Precompiled Headers**

* **Faster Compilation Times:** They significantly reduce build times, especially for larger projects with many source files that include common headers \[[04:50](http://www.youtube.com/watch?v=eSI4wctZUto&t=290)\]. A project that might take a minute to compile could be reduced to eight seconds \[[05:23](http://www.youtube.com/watch?v=eSI4wctZUto&t=323)\].
* **Convenience:** By including a precompiled header in every source file, you gain access to commonly used functions and libraries (like logging functions) without needing to manually include them in each individual file \[[06:56](http://www.youtube.com/watch?v=eSI4wctZUto&t=416)\].

***

### **What NOT to Put in Precompiled Headers**

* **Frequently Changing Files:** Do not include files that you are actively working on or are likely to change often \[[06:08](http://www.youtube.com/watch?v=eSI4wctZUto&t=368)\]. If a file in the precompiled header changes, the entire precompiled header needs to be rebuilt, which can slow down compilation \[[06:16](http://www.youtube.com/watch?v=eSI4wctZUto&t=376)\].
* **Specific Dependencies:** While convenient, putting all dependencies into a precompiled header can hide what a specific C++ file actually needs, making code reuse and modularity more difficult \[[09:21](http://www.youtube.com/watch?v=eSI4wctZUto&t=561)\]. It's generally better to include specific dependencies per file if they are not broadly used across the project \[[10:47](http://www.youtube.com/watch?v=eSI4wctZUto&t=647)\].

***

### **What to Put in Precompiled Headers**

* **External Dependencies/Libraries:** Ideal for code that you will not modify, such as the Standard Template Library (STL) or the Windows API (`Windows.h`) \[[07:41](http://www.youtube.com/watch?v=eSI4wctZUto&t=461)\]. These are often massive and are used frequently across a project \[[08:02](http://www.youtube.com/watch?v=eSI4wctZUto&t=482)\].
* **Commonly Used Project Files (Stable):** If you have your own header files that are stable and rarely change (e.g., a logging library), they can be included for convenience \[[06:34](http://www.youtube.com/watch?v=eSI4wctZUto&t=394)\].

***

### **Setting up Precompiled Headers (Examples)**

* **Visual Studio:**
    1.  Create a header file (e.g., `PCH.h`) that includes all the common headers you want to precompile \[[13:58](http://www.youtube.com/watch?v=eSI4wctZUto&t=838)\].
    2.  Create a C++ file (e.g., `PCH.cpp`) that includes your `PCH.h` file \[[14:21](http://www.youtube.com/watch?v=eSI4wctZUto&t=861)\].
    3.  In the properties of `PCH.cpp`, go to "C/C++" -> "Precompiled Headers" and set "Precompiled Header" to "Create" \[[14:46](http://www.youtube.com/watch?v=eSI4wctZUto&t=886)\].
    4.  In the project properties, go to "C/C++" -> "Precompiled Headers" and set "Precompiled Header" to "Use" and specify `PCH.h` as the "Precompiled Header File" \[[15:08](http://www.youtube.com/watch?v=eSI4wctZUto&t=908)\].
    5.  **Performance Comparison:** A clean build without precompiled headers took 3.3 seconds, and subsequent builds took 1.5 seconds \[[17:07](http://www.youtube.com/watch?v=eSI4wctZUto&t=1027)\]. With precompiled headers, a clean build took 2 seconds, and subsequent builds took 0.5 seconds \[[17:36](http://www.youtube.com/watch?v=eSI4wctZUto&t=1056)\].
* **GCC:**
    1.  Compile your precompiled header file (e.g., `PCH.h`) using the command: `g++ PCH.h` \[[18:42](http://www.youtube.com/watch?v=eSI4wctZUto&t=1122)\]. This generates a `.gch` file (e.g., `PCH.h.gch`) \[[18:55](http://www.youtube.com/watch?v=eSI4wctZUto&t=1135)\].
    2.  When compiling your main C++ file, GCC will automatically use the generated `.gch` file if it's present \[[19:05](http://www.youtube.com/watch?v=eSI4wctZUto&t=1145)\].
    3.  **Performance Comparison:** Compiling without precompiled headers took about 1.5 seconds \[[18:30](http://www.youtube.com/watch?v=eSI4wctZUto&t=1110)\]. With precompiled headers, compilation time was reduced to about 0.2 to 0.3 seconds \[[19:11](http://www.youtube.com/watch?v=eSI4wctZUto&t=1151)\].

The video emphasizes that almost every C++ project should use precompiled headers to improve compilation times \[[20:03](http://www.youtube.com/watch?v=eSI4wctZUto&t=1203)\].
