/**
 * @file version.h
 * @brief HTWOS SDK version macros and query helpers
 * @author HTW_DEV
 * @date 2026-11-24
 * @version 2026-11-24_v1.0
 *
 * Copyright (c) 2026 Hantewin. All rights reserved.
 *
 * modify history:
 * | Date       | Author  | Notes              |
 * |------------|---------|--------------------|
 * | 2026-11-24 | HTW_DEV | Initial skeleton   |
 */
#ifndef HTWOS_VERSION_H
#define HTWOS_VERSION_H

#include <cstdint>
#include <string>

#ifndef HTWOS_SDK_VERSION_MAJOR
#define HTWOS_SDK_VERSION_MAJOR (1)
#endif

#ifndef HTWOS_SDK_VERSION_MINOR
#define HTWOS_SDK_VERSION_MINOR (0)
#endif

#ifndef HTWOS_SDK_VERSION_PATCH
#define HTWOS_SDK_VERSION_PATCH (0)
#endif

#define HTWOS_HAL_API_VERSION_MAJOR (1) // 2026-11-24, HTW_DEV, HAL API major
#define HTWOS_HAL_API_VERSION_MINOR (0) // 2026-11-24, HTW_DEV, HAL API minor
#define HTWOS_PROVIDER_SPI_VERSION_MAJOR (1) // 2026-11-24, HTW_DEV
#define HTWOS_PROVIDER_SPI_VERSION_MINOR (0) // 2026-11-24, HTW_DEV

namespace Hantewin {
namespace Htwos {

/**
 * @brief SDK semantic version descriptor
 * @date 2026-11-24
 * @author HTW_DEV
 */
typedef struct {
    std::uint32_t major; // major version
    std::uint32_t minor; // minor version
    std::uint32_t patch; // patch version
} SdkVersion_T;

SdkVersion_T sdkVersion();
std::string sdkVersionString();

} // namespace Htwos
} // namespace Hantewin

#endif /* HTWOS_VERSION_H */
