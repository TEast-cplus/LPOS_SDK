add_executable(htwos_hello_capability
    main.cpp
)

target_link_libraries(htwos_hello_capability
    PRIVATE
        Htwos::native
)

htwos_sdk_apply_warnings(htwos_hello_capability)

install(TARGETS htwos_hello_capability
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)