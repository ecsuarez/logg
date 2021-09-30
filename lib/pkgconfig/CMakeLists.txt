# Configure file for pkgconfig
configure_file("${CMAKE_SOURCE_DIR}/lib/pkgconfig/liblogg.pc.in"
    "${CMAKE_SOURCE_DIR}/lib/pkgconfig/liblogg.pc" @ONLY)
