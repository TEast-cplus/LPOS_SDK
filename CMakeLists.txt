cmake_minimum_required(VERSION 3.16)

file(READ "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" HTWOS_SDK_VERSION_RAW)
string(STRIP "${HTWOS_SDK_VERSION_RAW}" HTWOS_SDK_VERSION)

project(htwos_sdk
    VERSION ${HTWOS_SDK_VERSION}
    DESCRIPTION "HTWOS Robot Development SDK"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(HTWOS_SDK_BUILD_EXAMPLES "Build native SDK examples" ON)
option(HTWOS_SDK_BUILD_TESTS "Build unit tests" OFF)
option(HTWOS_SDK_BUILD_SHARED "Build shared libraries" ON)

include(GNUInstallDirs)
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/options.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerWarnings.cmake")

add_subdirectory(sdk/common)
add_subdirectory(sdk/native)

if (HTWOS_SDK_BUILD_EXAMPLES)
    add_subdirectory(examples/native/hello_capability)
endif()

if (HTWOS_SDK_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests/unit)
endif()

include(CMakePackageConfigHelpers)
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/HtwosSdkConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/HtwosSdkConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/HtwosSdk"
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/HtwosSdkConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/HtwosSdkConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/HtwosSdkConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/HtwosSdk"
)

install(DIRECTORY platform capabilities
    DESTINATION "${CMAKE_INSTALL_DATADIR}/htwos"
)

install(DIRECTORY sdk/provider/include/htwos
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)