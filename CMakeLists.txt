cmake_minimum_required(VERSION 3.0)
project(ndsu)

if (NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 11)
endif ()

add_library(ndsu INTERFACE)
target_include_directories(ndsu INTERFACE include/)

if (BUILD_TEST)
    add_subdirectory(test)
endif ()