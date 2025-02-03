cmake_minimum_required(VERSION 3.10) 

project(test-library VERSION 1.0.0 LANGUAGES CXX)

include(GNUInstallDirs)

add_library(minha_biblioteca STATIC minha_biblioteca.cpp)

target_include_directories(minha_biblioteca PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS minha_biblioteca
    EXPORT test-libraryTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES minha_biblioteca.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT test-libraryTargets
    FILE test-libraryConfig.cmake
    NAMESPACE test-library::
    DESTINATION share/test-library/cmake
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/test-libraryConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/test-libraryConfigVersion.cmake
    DESTINATION share/test-library/cmake
)
