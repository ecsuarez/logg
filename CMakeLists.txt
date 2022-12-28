cmake_minimum_required(VERSION 3.0)

project(logg VERSION 0.6.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Version configuration
configure_file("${CMAKE_SOURCE_DIR}/src/version.h.in"
    "${CMAKE_SOURCE_DIR}/src/version.h")
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
    src/logg.h
    src/version.h
    src/logdef.h
    src/logger.h
    src/ops.h

    PRIVATE
    # Sources
    src/logger.c
    src/ops.c
)

# Install in an unix system (not apple)
if(UNIX AND NOT APPLE)
    include(GNUInstallDirs)
    install(TARGETS logg DESTINATION ${CMAKE_INSTALL_LIBDIR})
    # Public sources
    install(FILES src/logg.h DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
    install(FILES src/version.h DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
    install(FILES src/logdef.h DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
    #install(FILES src/logger.h DESTINATION
    #    ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
    
    install(FILES lib/pkgconfig/liblogg.pc DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
endif()
