# 2026-11-24, HTW_DEV, common warning flags for HTWOS SDK targets

function(htwos_sdk_apply_warnings target_name)
    if (MSVC)
        target_compile_options(${target_name} PRIVATE /W4)
    else()
        target_compile_options(${target_name} PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Wconversion
            -Wshadow
        )
    endif()
endfunction()