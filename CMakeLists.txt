cmake_minimum_required(VERSION 3.0)

project(logg VERSION 0.4.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Version configuration
configure_file("${CMAKE_SOURCE_DIR}/src/version.hpp.in"
    "${CMAKE_SOURCE_DIR}/src/version.hpp")
# Doxygen
configure_file("${CMAKE_SOURCE_DIR}/docs/Doxyfile.in"
    "${CMAKE_SOURCE_DIR}/docs/Doxyfile" @ONLY)

add_subdirectory(lib)

cmake_policy(SET CMP0076 NEW)

# Make library
add_library(logg SHARED)

# Sources
target_sources(logg
    PUBLIC
    # Headers
    src/logg.hpp
    src/logger.hpp
    src/version.hpp
    src/formats.hpp
    src/logdef.hpp
    src/io.hpp
    PRIVATE
    src/internal/colors.hpp
    # Sources
    src/logger.cpp
    src/formats.cpp
    src/io.cpp
)

# Install in an unix system (not apple)
if(UNIX AND NOT APPLE)
    include(GNUInstallDirs)
    install(TARGETS logg DESTINATION ${CMAKE_INSTALL_LIBDIR})
    # Public sources
    install(FILES src/logg.hpp DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
    install(FILES src/version.hpp DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
    install(FILES src/logdef.hpp DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
    install(FILES src/io.hpp DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
    install(FILES src/formats.hpp DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
    install(FILES src/logger.hpp DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
    
    install(FILES lib/pkgconfig/liblogg.pc DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
endif()
