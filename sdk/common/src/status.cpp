/**
 * @file status.cpp
 * @brief HTWOS SDK status implementation
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
#include "htwos/common/status.h"

namespace Hantewin {
namespace Htwos {

Status::Status()
    : m_code(HTWOS_OK)
    , m_message()
{
}

Status::Status(STATUS_E code)
    : m_code(code)
    , m_message(statusToString(code))
{
}

Status::Status(STATUS_E code, const std::string& message)
    : m_code(code)
    , m_message(message)
{
}

bool Status::ok() const
{
    return (HTWOS_OK == m_code);
}

STATUS_E Status::code() const
{
    return m_code;
}

const std::string& Status::message() const
{
    return m_message;
}

Status Status::Ok()
{
    return Status(HTWOS_OK, "ok");
}

Status Status::FromCode(STATUS_E code)
{
    return Status(code);
}

Status Status::Stub(const std::string& message)
{
    return Status(HTWOS_ERR_STUB, message);
}

const char* statusToString(STATUS_E code)
{
    switch (code) {
    case HTWOS_OK:
        return "ok";
    case HTWOS_ERR_INVALID_ARG:
        return "invalid_arg";
    case HTWOS_ERR_NOT_CONNECTED:
        return "not_connected";
    case HTWOS_ERR_TIMEOUT:
        return "timeout";
    case HTWOS_ERR_NOT_FOUND:
        return "not_found";
    case HTWOS_ERR_UNSUPPORTED:
        return "unsupported";
    case HTWOS_ERR_BUSY:
        return "busy";
    case HTWOS_ERR_IO:
        return "io";
    case HTWOS_ERR_INTERNAL:
        return "internal";
    case HTWOS_ERR_STUB:
        return "stub";
    default:
        return "unknown";
    }
}

} // namespace Htwos
} // namespace Hantewin
