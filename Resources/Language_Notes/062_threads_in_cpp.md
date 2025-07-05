### Introduction to Threads 🧵 \[[00:10](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=10)\]

Modern computers have multiple cores, allowing for parallel processing. However, by default, C++ programs run on a **single thread**. This means that only one instruction is executed at a time. Threads allow you to break this limitation and run multiple tasks concurrently.

**Benefits of using threads:**

  * **Performance:** 🚀 By offloading work to other threads, you can significantly improve the performance of your programs, especially for complex tasks. \[[01:05](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=65)\]
  * **Functionality:** 💪 Threads enable you to perform multiple actions at once. For example, you can have a responsive user interface while performing background calculations. \[[01:13](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=73)\]

A classic example of a single-threaded limitation is waiting for user input with `std::cin.get()`. The entire program will pause until the user provides input. \[[01:25](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=85)\] Threads can solve this by allowing other tasks to continue running while waiting for input. \[[01:42](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=102)\]

### Basic Thread Usage in C++ \[[01:58](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=118)\]

To get started with threads, you need to include the `<thread>` header. \[[02:01](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=121)\]

**Creating a thread:**

You can create a new thread by creating an instance of `std::thread` and passing a function to its constructor. This will immediately start the thread's execution. \[[02:07](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=127)\]

```cpp
#include <thread>

void doWork() {
    // This code will run on a new thread
}

int main() {
    std::thread worker(doWork); // Starts the new thread
    // ...
    return 0;
}
```

**`thread.join()`:**

The `join()` method is used to make the current thread wait for another thread to finish its execution. \[[02:52](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=172)\] This is a blocking call, meaning the current thread will pause until the joined thread completes. \[[03:27](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=207)\]

```cpp
std::thread worker(doWork);
worker.join(); // The main thread will wait here for the worker thread to finish
```

### Demonstrating Parallel Execution \[[04:07](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=247)\]

The video provides a practical example of using threads to keep a program responsive while waiting for user input. A `static bool` variable is used to control the worker thread's loop. \[[05:34](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=334)\] The main thread waits for user input and then sets the boolean to `true`, signaling the worker thread to stop. \[[05:50](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=350)\]

```cpp
#include <iostream>
#include <thread>
#include <chrono>

static bool s_finished = false;

void doWork() {
    while (!s_finished) {
        std::cout << "Working..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::thread worker(doWork);

    std::cout << "Press ENTER to stop working." << std::endl;
    std::cin.get();

    s_finished = true;

    worker.join();

    std::cout << "Finished." << std::endl;
    std::cin.get();
    return 0;
}
```

**`std::this_thread::sleep_for()`:** This function is used to pause the current thread for a specified duration, which is useful for preventing a thread from using 100% of the CPU. \[[07:15](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=435)\]

### Getting the Thread ID \[[09:19](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=559)\]

You can get the unique ID of the current thread using `std::this_thread::get_id()`. This is helpful for debugging and identifying different threads.

```cpp
#include <iostream>
#include <thread>

void doWork() {
    std::cout << "Started thread ID (worker): " << std::this_thread::get_id() << std::endl;
    // ...
}

int main() {
    std::cout << "Started thread ID (main): " << std::this_thread::get_id() << std::endl;
    std::thread worker(doWork);
    worker.join();
    return 0;
}
```

### Conclusion \[[10:14](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=614)\]

Threads are a powerful tool for improving the performance and functionality of your C++ programs. While the basic concepts are straightforward, multithreading can become quite complex, so it's a topic worth studying in more depth. \[[09:03](http://www.youtube.com/watch?v=wXBcwHwIt_I&t=543)\]
