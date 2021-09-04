cmake_minimum_required(VERSION 3.0)

# liblogg
project(logg LANGUAGES CXX)

cmake_policy(SET CMP0076 NEW)

# Make library
add_library(logg SHARED)

# Sources
target_sources(logg
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
target_link_libraries(test logg)
