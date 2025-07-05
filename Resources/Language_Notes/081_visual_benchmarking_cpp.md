### **Notes on C++ Performance Visualization**

This video explains how to measure and visualize the performance of C++ code using **Chrome's tracing tool**. The main idea is to go beyond simple console output of benchmark numbers and create a visual representation of code execution, which is much easier to understand and analyze.

-----

### **Important Concepts**

  * **Visualizing Data**: The video starts by highlighting the importance of visualizing data. Seeing performance data graphically makes it easier to spot bottlenecks and understand the flow of your program compared to just reading numbers in a console. \[[00:00](http://www.youtube.com/watch?v=xlAH4dbMVnU&t=0)\]

  * **Benchmarking**: The core of the video is about benchmarking—measuring how long different parts of your code take to run. This is done using a `Timer` class. \[[02:49](http://www.youtube.com/watch?v=xlAH4dbMVnU&t=169)\]

  * **Chrome Tracing**: A powerful, built-in profiling tool in Google Chrome. You can access it by navigating to `chrome://tracing`. It can load and visualize performance data from a JSON file. \[[03:54](http://www.youtube.com/watch?v=xlAH4dbMVnU&t=234)\]

  * **Instrumentation**: This is the process of adding code to your program to monitor its performance. In the video, an `Instrumentation` class is created to handle the formatting and writing of timing data to a JSON file that Chrome Tracing can understand. \[[04:54](http://www.youtube.com/watch?v=xlAH4dbMVnU&t=294)\]

  * **Profiling Macros**: To make the profiling code cleaner and easier to manage, the video introduces several C++ macros:

      * `PROFILE_SCOPE(name)`: A macro to easily time a specific scope of code. \[[10:15](http://www.youtube.com/watch?v=xlAH4dbMVnU&t=615)\]
      * `PROFILE_FUNCTION()`: A macro that automatically times the function it's placed in, using the function's own name for the profile entry. \[[11:23](http://www.youtube.com/watch?v=xlAH4dbMVnU&t=683)\]
      * `__FUNCSIG__` (or `__PRETTY_FUNCTION__`): A compiler-specific macro that provides the full signature of a function, which is useful for distinguishing between overloaded functions in the profiler. \[[12:46](http://www.youtube.com/watch?v=xlAH4dbMVnU&t=766)\]

  * **Multi-threading**: The video also demonstrates how to extend the profiler to support multi-threaded applications. By capturing the thread ID for each profile, Chrome Tracing can display the execution of each thread on a separate timeline, which is incredibly useful for debugging and optimizing concurrent code. \[[13:43](http://www.youtube.com/watch?v=xlAH4dbMVnU&t=823)\]

-----

### **Code Examples**

Here are some of the key code snippets from the video:

#### **Dummy Functions for Profiling**

These simple functions are used as examples to demonstrate the profiling process.

```cpp
void Function1()
{
    for (int i = 0; i < 1000000; i++)
    {
        std::cout << "Hello from Function1" << std::endl;
    }
}

void Function2()
{
    for (int i = 0; i < 1000000; i++)
    {
        double x = sqrt(i);
        std::cout << "Hello from Function2" << std::endl;
    }
}
```

#### **Timer Class for Benchmarking**

A simple, scope-based timer that prints the elapsed time to the console when it's destroyed.

```cpp
#include <iostream>
#include <chrono>
#include <string>

class Timer
{
public:
    Timer(const std::string& name)
        : m_Name(name), m_StartTimepoint(std::chrono::high_resolution_clock::now())
    {
    }

    ~Timer()
    {
        auto endTimepoint = std::chrono::high_resolution_clock::now();
        long long start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_StartTimepoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::milliseconds>(endTimepoint).time_since_epoch().count();
        long long duration = end - start;
        std::cout << m_Name << " took " << duration << "ms" << std::endl;
    }
private:
    std::string m_Name;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
};
```

#### **`InstrumentationTimer` for JSON Output**

This is a modified version of the `Timer` class that, instead of printing to the console, writes the profiling data to a JSON file using the `Instrumentation` class.

```cpp
class InstrumentationTimer
{
public:
    InstrumentationTimer(const std::string& name)
        : m_Name(name), m_Stopped(false), m_StartTimepoint(std::chrono::high_resolution_clock::now())
    {
    }

    ~InstrumentationTimer()
    {
        if (!m_Stopped)
            Stop();
    }

    void Stop()
    {
        auto endTimepoint = std::chrono::high_resolution_clock::now();
        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

        uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());

        Instrumentation::Get().WriteProfile({ m_Name, start, end, threadID });
        m_Stopped = true;
    }
private:
    std::string m_Name;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
    bool m_Stopped;
};
```

I hope these notes are helpful for you\! Let me know if you have any other questions.
