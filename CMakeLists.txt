cmake_minimum_required(VERSION 3.18)
project(tensorgrad_compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Find Python and pybind11
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
execute_process(
    COMMAND ${Python3_EXECUTABLE} -m pybind11 --cmakedir
    OUTPUT_VARIABLE pybind11_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
find_package(pybind11 REQUIRED)

# Build the Python module (This replaces add_executable)
pybind11_add_module(tensorgrad_cpp 
    src/cpp/tensor.cpp
)