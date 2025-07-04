# Basic CMake setup
cmake_minimum_required(VERSION 3.20)

# Name your project (this can be anything)
project(cpp-playground CXX)

# Set the C++ standard you want to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Automatically add executables for each .cpp file in practice folders ---
file(GLOB_RECURSE PRACTICE_CPP_FILES
    "100_The_Foundation/**/*.cpp"
)

foreach(PRACTICE_FILE ${PRACTICE_CPP_FILES})
    # Get just the filename without the path or extension
    get_filename_component(TARGET_NAME ${PRACTICE_FILE} NAME_WE)

    # Add the executable
    add_executable(${TARGET_NAME} ${PRACTICE_FILE}
            100_The_Foundation/110_Basic_IO_and_Syntax/009_size-of_data-types.cpp)
endforeach()

