### **Purpose of a `Log` Class** 🪵

A `Log` class is a fundamental tool for debugging. It allows you to print messages to the console to understand what's happening inside your program. This is especially useful because it's a reliable way to get information, even if your program's graphics or other outputs fail.

### **Core Functionality**

The main goals of this simple `Log` class are:

1.  **Write text to the console.**
2.  **Filter messages based on a "log level."**

### **Log Levels** 🚦

Log levels help you control which messages you see. This is great for keeping your console output clean. The video introduces three basic levels:

  * `Error`: For critical problems.
  * `Warning`: For potential issues.
  * `Info`: For general information or tracing program flow.

If you set the log level to `Warning`, you'll only see `Warning` and `Error` messages. If you set it to `Error`, you'll only see `Error` messages.

### **Designing the Class**

A great way to design a class is to think about how you want to *use* it first. Here's the example from the video:

```cpp
Log log; // Create a Log object
log.SetLevel(Log::LogLevelWarning); // Set the filter level
log.Warn("Hello"); // Log a warning message
```

### **Class Structure**

Here's how the `Log` class is structured:

```cpp
class Log {
public:
    // Constants for log levels to make the code readable
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

public:
    // Sets the current log level
    void SetLevel(int level) {
        m_LogLevel = level;
    }

    // Logs an error message if the level is high enough
    void Error(const char* message) {
        if (m_LogLevel >= LogLevelError) {
            std::cout << "[ERROR]: " << message << std::endl;
        }
    }

    // Logs a warning message if the level is high enough
    void Warn(const char* message) {
        if (m_LogLevel >= LogLevelWarning) {
            std::cout << "[WARNING]: " << message << std::endl;
        }
    }

    // Logs an info message if the level is high enough
    void Info(const char* message) {
        if (m_LogLevel >= LogLevelInfo) {
            std::cout << "[INFO]: " << message << std::endl;
        }
    }

private:
    // Stores the current log level, initialized to show all messages
    int m_LogLevel = LogLevelInfo;
};
```

### **How Filtering Works**

Each logging function (`Error`, `Warn`, `Info`) checks the current `m_LogLevel` before printing anything.

For example, in the `Info` function:

```cpp
if (m_LogLevel >= LogLevelInfo) {
    std::cout << "[INFO]: " << message << std::endl;
}
```

This line ensures that "Info" messages are only printed if the log level is set to `LogLevelInfo`.

This video provides a solid foundation for building a more advanced logging system. Since you're into C++ and building cool things, you could expand this `Log` class to write to files, add timestamps, or even color-code the output in the console\! 🎨
