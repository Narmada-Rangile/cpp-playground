### **Introduction to Timing** ⏱️ \[[00:04](http://www.youtube.com/watch?v=oEx5vGNFrLk&t=4)\]

Timing your code is essential for several reasons:

  * **Performance Evaluation:** To understand how fast your code is running.
  * **Benchmarking:** To compare the performance of different implementations.
  * **Synchronization:** To ensure that operations happen at specific times.

### **Methods for Timing in C++** \[[00:28](http://www.youtube.com/watch?v=oEx5vGNFrLk&t=28)\]

There are two main ways to time your code in C++:

  * **The `chrono` Library (C++11 and later):** This is the recommended method as it's part of the standard library, platform-independent, and provides high-resolution timing. \[[00:33](http://www.youtube.com/watch?v=oEx5vGNFrLk&t=33)\]
  * **Operating System Libraries:** Before C++11, you had to use OS-specific libraries like `QueryPerformanceCounter` on Windows. These are still useful if you need more direct control over the CPU's timing capabilities. \[[00:40](http://www.youtube.com/watch?v=oEx5vGNFrLk&t=40)\]

### **Basic Usage of `chrono`** \[[02:38](http://www.youtube.com/watch?v=oEx5vGNFrLk&t=158)\]

Here's how you can use the `chrono` library to time a piece of code:

1.  **Include the necessary headers:**
    ```cpp
    #include <chrono>
    #include <thread> // For std::this_thread::sleep_for
    ```
2.  **Get the start time:**
    ```cpp
    auto start = std::chrono::high_resolution_clock::now();
    ```
3.  **Execute the code you want to time:**
    ```cpp
    std::this_thread::sleep_for(std::chrono::seconds(1));
    ```
4.  **Get the end time:**
    ```cpp
    auto end = std::chrono::high_resolution_clock::now();
    ```
5.  **Calculate and print the duration:**
    ```cpp
    std::chrono::duration<float> duration = end - start;
    std::cout << duration.count() << "s" << std::endl;
    ```

Here is a complete example: \[[02:32](http://www.youtube.com/watch?v=oEx5vGNFrLk&t=152)\]

```cpp
#include <iostream>
#include <chrono>
#include <thread>

// To use 1s, 1ms, etc. literals
using namespace std::literals::chrono_literals;

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    // Code to be timed
    std::this_thread::sleep_for(1s);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;

    std::cout << duration.count() << "s" << std::endl;

    return 0;
}
```

### **Creating a Reusable Timer** ♻️ \[[05:12](http://www.youtube.com/watch?v=oEx5vGNFrLk&t=312)\]

To avoid writing the same timing code over and over, you can create a reusable `Timer` struct that uses **RAII** (Resource Acquisition Is Initialization). The timer starts in the constructor and prints the duration in the destructor.

Here is an example of a `Timer` struct: \[[05:50](http://www.youtube.com/watch?v=oEx5vGNFrLk&t=350)\]

```cpp
#include <iostream>
#include <chrono>
#include <thread>

// To use 1s, 1ms, etc. literals
using namespace std::literals::chrono_literals;

struct Timer {
    std::chrono::time_point<std::chrono::steady_clock> m_Start;

    Timer() {
        m_Start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - m_Start;

        float ms = duration.count() * 1000.0f;
        std::cout << "Time took: " << ms << "ms" << std::endl;
    }
};

void Function() {
    Timer timer; // Timer starts here

    for (int i = 0; i < 100; ++i) {
        std::cout << "Hello\n"; // Using '\n' instead of std::endl for performance
    }
    // Timer ends when Function exits and 'timer' object is destroyed
}

int main() {
    Function();
    return 0;
}
```

To use it, you just need to create an instance of the `Timer` struct at the beginning of the scope you want to time. \[[08:05](http://www.youtube.com/watch?v=oEx5vGNFrLk&t=485)\]

### **Performance Considerations** ⚡ \[[08:45](http://www.youtube.com/watch?v=oEx5vGNFrLk&t=525)\]

  * Using `std::endl` is slower than using `'\n'` because `std::endl` also flushes the output buffer.
  * For accurate benchmarks, you should run your tests multiple times and in **release mode**. \[[09:02](http://www.youtube.com/watch?v=oEx5vGNFrLk&t=542)\]

### **Future Applications** 🚀 \[[01:44](http://www.youtube.com/watch?v=oEx5vGNFrLk&t=104)\]

Timing is a fundamental concept that you'll use to optimize your code. You can also use it to build more sophisticated benchmarking APIs and profiling tools. \[[09:19](http://www.youtube.com/watch?v=oEx5vGNFrLk&t=559)\] This is especially useful in fields like game development and other performance-critical applications. \[[10:16](http://www.youtube.com/watch?v=oEx5vGNFrLk&t=616)\]
