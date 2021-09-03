cmake_minimum_required(VERSION 3.0)

# liblogg
project(liblogg LANGUAGES CXX)

# Make library
add_library(liblogg SHARED)

# Sources
target_sources(liblogg
    PUBLIC
    # Headers
    src/liblogg.hpp
    src/log.hpp

    PRIVATE
    # Sources
    src/log.cpp
)

# Testing
project(test LANGUAGES CXX)
include_directories(src/)
add_executable(test)
target_sources(test PRIVATE test/test.cpp)

