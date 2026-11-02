cmake_minimum_required(VERSION 3.18)
project(tensorgrad_compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Python (this now finds the .venv Python if CLion is configured correctly)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# Find pybind11 (now it will work because pybind11 is in .venv)
execute_process(
    COMMAND ${Python3_EXECUTABLE} -m pybind11 --cmakedir
    OUTPUT_VARIABLE pybind11_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
find_package(pybind11 REQUIRED)

# Build the Python module with BOTH source files
pybind11_add_module(tensorgrad_cpp 
    src/cpp/bindings.cpp
    src/cpp/tensor.cpp
)