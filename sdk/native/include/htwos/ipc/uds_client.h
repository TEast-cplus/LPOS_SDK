/**
 * @file uds_client.h
 * @brief Unix Domain Socket client for control-plane commands
 * @author HTW_DEV
 * @date 2026-11-24
 * @version 2026-11-24_v1.0
 *
 * Copyright (c) 2026 Hantewin. All rights reserved.
 *
 * modify history:
 * | Date       | Author  | Notes              |
 * |------------|---------|--------------------|
 * | 2026-11-24 | HTW_DEV | Initial stub       |
 */
#ifndef HTWOS_UDS_CLIENT_H
#define HTWOS_UDS_CLIENT_H

#include "htwos/common/status.h"

#include <string>

namespace Hantewin {
namespace Htwos {
namespace Ipc {

/**
 * @class UdsClient
 * @brief Cross-process command / config / status query channel
 * @date 2026-11-24
 * @author HTW_DEV
 */
class UdsClient {
public:
    UdsClient();
    ~UdsClient();

    Status connect(const std::string& socket_path);
    Status disconnect();
    bool isConnected() const;

    Status sendRequest(const std::string& request,
                       std::string& response);

private:
    bool m_connected;          // connection flag
    std::string m_socket_path; // uds path
};

} // namespace Ipc
} // namespace Htwos
} // namespace Hantewin

#endif /* HTWOS_UDS_CLIENT_H */
