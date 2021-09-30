# Configure file for makepkg in ArchLinux
configure_file("${CMAKE_SOURCE_DIR}/lib/makepkg/PKGBUILD.in"
    "${CMAKE_SOURCE_DIR}/lib/makepkg/PKGBUILD" @ONLY)
