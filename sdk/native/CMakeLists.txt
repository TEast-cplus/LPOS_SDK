add_library(htwos_native ${HTWOS_SDK_LIB_TYPE}
    src/sdk_client.cpp
    src/capability_query.cpp
    src/ipc/uds_client.cpp
    src/ipc/event_bus.cpp
    src/ipc/shm_channel.cpp
)

add_library(Htwos::native ALIAS htwos_native)

target_include_directories(htwos_native
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(htwos_native
    PUBLIC
        Htwos::common
)

htwos_sdk_apply_warnings(htwos_native)
set_target_properties(htwos_native PROPERTIES
    OUTPUT_NAME htwos_native
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

install(TARGETS htwos_native
    EXPORT HtwosSdkTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/htwos
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT HtwosSdkTargets
    NAMESPACE Htwos::
    FILE HtwosSdkTargets.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/HtwosSdk
)