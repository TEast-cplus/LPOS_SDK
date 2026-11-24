add_library(htwos_common ${HTWOS_SDK_LIB_TYPE}
    src/status.cpp
    src/version.cpp
)

add_library(Htwos::common ALIAS htwos_common)

target_include_directories(htwos_common
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_definitions(htwos_common
    PUBLIC
        HTWOS_SDK_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
        HTWOS_SDK_VERSION_MINOR=${PROJECT_VERSION_MINOR}
        HTWOS_SDK_VERSION_PATCH=${PROJECT_VERSION_PATCH}
)

htwos_sdk_apply_warnings(htwos_common)
set_target_properties(htwos_common PROPERTIES
    OUTPUT_NAME htwos_common
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

install(TARGETS htwos_common
    EXPORT HtwosSdkTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/htwos
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)