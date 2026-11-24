/**
 * @file version.cpp
 * @brief HTWOS SDK version helpers
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
#include "htwos/common/version.h"

#include <sstream>

namespace Hantewin {
namespace Htwos {

SdkVersion_T sdkVersion()
{
    SdkVersion_T version = {};

    version.major = HTWOS_SDK_VERSION_MAJOR;
    version.minor = HTWOS_SDK_VERSION_MINOR;
    version.patch = HTWOS_SDK_VERSION_PATCH;
    return version;
}

std::string sdkVersionString()
{
    std::ostringstream stream;

    stream << HTWOS_SDK_VERSION_MAJOR << "."
           << HTWOS_SDK_VERSION_MINOR << "."
           << HTWOS_SDK_VERSION_PATCH;
    return stream.str();
}

} // namespace Htwos
} // namespace Hantewin
