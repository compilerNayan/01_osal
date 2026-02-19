cmake_minimum_required(VERSION 3.14)
project(01_osal VERSION 1.0.0 LANGUAGES CXX)

add_library(01_osal INTERFACE)

set_target_properties(01_osal PROPERTIES
    VERSION ${PROJECT_VERSION}
)

target_include_directories(01_osal INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)

install(TARGETS 01_osal
    EXPORT 01_osalTargets
)

install(EXPORT 01_osalTargets
    FILE 01_osalTargets.cmake
    NAMESPACE 01_osal::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/01_osal
)
