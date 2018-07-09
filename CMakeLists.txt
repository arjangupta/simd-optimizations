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

if(OSX OR LINUX)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W -Wall")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")

    #include vcpkg toolchain and add include dirs
    include(${VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake)
    include_directories(${VCPKG_PATH}/installed/x64-osx/include)

    find_package(GTest REQUIRED)
    if (NOT GTest_FOUND)
        message(ERROR "GTest not found.")
    endif()
endif()

add_library(loop_optimize STATIC src/loop_optimize.cpp)
target_include_directories(loop_optimize PUBLIC 3rd-party/libsimdpp/)

add_executable(test_loop_optimize test/test_loop_optimize.cpp)
target_include_directories(test_loop_optimize PUBLIC src)
target_link_libraries(test_loop_optimize PUBLIC GTest::GTest GTest::Main loop_optimize)