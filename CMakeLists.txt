cmake_minimum_required(VERSION 3.0)

# liblogg
project(logg LANGUAGES CXX VERSION 0.2.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Version configuration
configure_file("src/version.h.in" "version.h")

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
add_executable(test test.cpp)
include_directories(src)
target_link_libraries(test logg)

# Install
include(GNUInstallDirs)
install(TARGETS logg DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES src/liblogg.hpp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
