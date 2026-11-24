/**
 * @file status.h
 * @brief HTWOS SDK status codes and Status wrapper
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
#ifndef HTWOS_STATUS_H
#define HTWOS_STATUS_H

#include <cstdint>
#include <string>

namespace Hantewin {
namespace Htwos {

/**
 * @brief Common SDK / IPC status codes
 * @date 2026-11-24
 * @author HTW_DEV
 */
typedef enum {
    HTWOS_OK = 0,
    HTWOS_ERR_INVALID_ARG = 1,
    HTWOS_ERR_NOT_CONNECTED = 2,
    HTWOS_ERR_TIMEOUT = 3,
    HTWOS_ERR_NOT_FOUND = 4,
    HTWOS_ERR_UNSUPPORTED = 5,
    HTWOS_ERR_BUSY = 6,
    HTWOS_ERR_IO = 7,
    HTWOS_ERR_INTERNAL = 8,
    HTWOS_ERR_STUB = 100
} STATUS_E;

/**
 * @class Status
 * @brief Lightweight status carrier for SDK APIs
 * @date 2026-11-24
 * @author HTW_DEV
 */
class Status {
public:
    Status();
    explicit Status(STATUS_E code);
    Status(STATUS_E code, const std::string& message);

    bool ok() const;
    STATUS_E code() const;
    const std::string& message() const;

    static Status Ok();
    static Status FromCode(STATUS_E code);
    static Status Stub(const std::string& message);

private:
    STATUS_E m_code;        // status code
    std::string m_message;  // human readable detail
};

const char* statusToString(STATUS_E code);

} // namespace Htwos
} // namespace Hantewin

#endif /* HTWOS_STATUS_H */
