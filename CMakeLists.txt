cmake_minimum_required(VERSION 3.0)

# liblogg
project(liblogg LANGUAGES CXX)

cmake_policy(SET CMP0076 NEW)

# Make library
add_library(liblogg SHARED)

# Sources
target_sources(liblogg
    PUBLIC
    # Headers
    src/liblogg.hpp
    PRIVATE
    # Sources
    src/liblogg.cpp
)

# Testing
project(test LANGUAGES CXX)
include_directories(src/)
add_executable(test)
target_sources(test PRIVATE test/test.cpp)
target_link_libraries(test liblogg)
