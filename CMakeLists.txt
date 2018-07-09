cmake_minimum_required(VERSION 3.9)

project(simd-optimizations VERSION 1.0)

#use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "C++11 support has been enabled by default.")

#get vcpkg path
set(VCPKG_PATH $ENV{VCPKG_PATH})
if (NOT VCPKG_PATH)
    message(FATAL_ERROR "Set VCPKG_PATH environment variable")
endif()

add_library(loop-optimize STATIC src/loop_optimize.cpp)
target_include_directories(loop-optimize PUBLIC 3rd-party/libsimdpp/)