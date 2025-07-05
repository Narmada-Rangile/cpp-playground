### **Introduction to Benchmarking** \[[00:03](http://www.youtube.com/watch?v=YG4jexlSAjc&t=3)\]

  * Benchmarking helps determine how fast code runs, especially for performance-critical sessions or when comparing new techniques against old ones.
  * There isn't one "right" way to benchmark, as methods vary, and measurement itself can add overhead \[[00:25](http://www.youtube.com/watch?v=YG4jexlSAjc&t=25)\].
  * The video focuses on the presenter's preferred method for measuring C++ code performance \[[01:01](http://www.youtube.com/watch?v=YG4jexlSAjc&t=61)\].

-----

### **Setting up Code for Testing** \[[01:50](http://www.youtube.com/watch?v=YG4jexlSAjc&t=110)\]

  * The presenter demonstrates a simple `for` loop that increments a `value` variable a million times and then prints the final value \[[01:55](http://www.youtube.com/watch?v=YG4jexlSAjc&t=115)\].
  * A breakpoint is used in Visual Studio to pause execution before the program closes \[[02:13](http://www.youtube.com/watch?v=YG4jexlSAjc&t=133)\].

-----

### **Creating a Scoped-Based Timer Class** \[[02:34](http://www.youtube.com/watch?v=YG4jexlSAjc&t=154)\]

  * A `Timer` class is created to measure performance.
  * The constructor of the `Timer` class records the `start_time_point` using `std::chrono::high_resolution_clock::now()` \[[02:50](http://www.youtube.com/watch?v=YG4jexlSAjc&t=170)\].
  * The destructor automatically calls a `Stop` function, making it a scope-based timer (RAII - Resource Acquisition Is Initialization) \[[03:37](http://www.youtube.com/watch?v=YG4jexlSAjc&t=217)\].
  * The `Stop` function calculates the `end_time_point` and then computes the duration by subtracting the `start_time_point` from the `end_time_point` \[[03:57](http://www.youtube.com/watch?v=YG4jexlSAjc&t=237)\].
  * The duration is converted to microseconds and milliseconds for precision \[[04:22](http://www.youtube.com/watch?v=YG4jexlSAjc&t=262)\].
  * The calculated duration in microseconds and milliseconds is printed to the console \[[06:34](http://www.youtube.com/watch?v=YG4jexlSAjc&t=394)\].
  * **Code Example for Timer Usage:**
    ```cpp
    // Assuming Timer class is defined as shown in the video
    {
        Timer timer; // Timer starts when object is created
        // Code to be timed
        int value = 0;
        for (int i = 0; i < 1000000; i++) {
            value += 2;
        }
        std::cout << value << std::endl;
    } // Timer stops when object goes out of scope (destructor called)
    ```
    This example shows how to wrap the code to be timed within the scope of a `Timer` object \[[07:12](http://www.youtube.com/watch?v=YG4jexlSAjc&t=432)\].

-----

### **Importance of Compiler Optimizations (Debug vs. Release Mode)** \[[07:42](http://www.youtube.com/watch?v=YG4jexlSAjc&t=462)\]

  * It's crucial to ensure that the code being measured is actually the code that gets compiled and executed.
  * **Debug Mode:** In debug mode, the compiler might not optimize the code as aggressively. The presenter shows the assembly code for the simple increment loop, demonstrating that the `add` instruction is present \[[08:01](http://www.youtube.com/watch?v=YG4jexlSAjc&t=481)\].
  * **Release Mode:** In release mode, compilers can aggressively optimize code. The presenter demonstrates that the simple increment loop is completely optimized away, and the compiler directly calculates the final value at compile time, making the benchmark results meaningless for the original operation \[[09:09](http://www.youtube.com/watch?v=YG4jexlSAjc&t=549)\].
  * Always profile code in **release mode** as this reflects how the code will perform when shipped \[[13:39](http://www.youtube.com/watch?v=YG4jexlSAjc&t=819)\].

-----

### **Benchmarking Smart Pointers (Shared vs. Unique)** \[[10:23](http://www.youtube.com/watch?v=YG4jexlSAjc&t=623)\]

  * The video provides an example of benchmarking `std::shared_ptr` (using `make_shared` and `new`) against `std::unique_ptr` (using `make_unique`).
  * An array of 1000 smart pointers to a `Vector2` class is created and initialized within a loop \[[10:42](http://www.youtube.com/watch?v=YG4jexlSAjc&t=642)\].
  * **Initial Debug Mode Results:** In debug mode, `make_shared` and `new shared` show inconsistent and sometimes similar performance, while `unique_ptr` is generally faster \[[12:43](http://www.youtube.com/watch?v=YG4jexlSAjc&t=763)\].
  * **Release Mode Results:** In release mode, the results are significantly faster overall, and `make_shared` consistently outperforms `new shared`, which aligns with expectations \[[13:19](http://www.youtube.com/watch?v=YG4jexlSAjc&t=799)\].
  * This example reinforces the importance of benchmarking in release mode for meaningful results.
