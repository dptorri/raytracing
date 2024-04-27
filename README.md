# raytracing

https://github.com/dptorri/raytracing

Several raytracing concepts and examples

#### Add CMakeLists

This is a `CMakeLists.txt` file for the "raytracer" project. Let's step through each component:

* `cmake_minimum_required (VERSION 2.8)`: Sets the minimum required version of CMake that this project supports to 2.8.
* `project (raytracer)`: Sets the project name to "raytracer".
* `include(CheckCXXCompilerFlag)`: Includes the `CheckCXXCompilerFlag` module provided by CMake. This module provides `check_cxx_compiler_flag`, which checks if a specific compiler flag is supported by the C++ compiler.
* `function(enable_cxx_compiler_flag_if_supported flag)`: Defines a function that enables a given C++ compiler flag if it's supported. This function first checks if the flag is already present in the `CMAKE_CXX_FLAGS`. If not, it checks if the flag is supported and if so, it adds the flag to `CMAKE_CXX_FLAGS`.
* `enable_cxx_compiler_flag_if_supported("-Wall")`, `enable_cxx_compiler_flag_if_supported("-Wextra")`, etc.: These lines use the defined function to add a variety of flags. These flags control various settings like warning levels, enabling certain language features (C++11), optimization levels, and OpenMP (a standard for parallel programming).
* `file(GLOB SOURCES *.h *.cpp)`: Uses a glob pattern to include all `.h` header and `.cpp` source files in the build.
* `add_executable(${PROJECT_NAME} ${SOURCES})`: Tells CMake to create an executable with the name of the project ("raytracer") using the source files defined before.

