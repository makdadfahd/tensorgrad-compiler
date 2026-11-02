#include <pybind11/pybind11.h>

double add_numbers(double a , double b);

PYBIND11_MODULE(tensorgrad_cpp,m) {
    m.doc() = "Tensorgrad C++ backend";

    m.def("add_numbers", &add_numbers, "A simple function to add two numbers");

}