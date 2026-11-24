/**
 * @file uds_client.cpp
 * @brief Unix Domain Socket client stub
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
#include "htwos/ipc/uds_client.h"

namespace Hantewin {
namespace Htwos {
namespace Ipc {

UdsClient::UdsClient()
    : m_connected(false)
    , m_socket_path()
{
}

UdsClient::~UdsClient()
{
    (void)disconnect();
}

Status UdsClient::connect(const std::string& socket_path)
{
    if (true == socket_path.empty()) {
        return Status::FromCode(HTWOS_ERR_INVALID_ARG);
    }

    m_socket_path = socket_path;
    m_connected = true;
    return Status::Stub("uds connect is stubbed");
}

Status UdsClient::disconnect()
{
    m_connected = false;
    m_socket_path.clear();
    return Status::Ok();
}

bool UdsClient::isConnected() const
{
    return m_connected;
}

Status UdsClient::sendRequest(const std::string& request,
                              std::string& response)
{
    if (false == m_connected) {
        return Status::FromCode(HTWOS_ERR_NOT_CONNECTED);
    }
    if (true == request.empty()) {
        return Status::FromCode(HTWOS_ERR_INVALID_ARG);
    }

    response = "{}";
    return Status::Stub("uds sendRequest is stubbed");
}

} // namespace Ipc
} // namespace Htwos
} // namespace Hantewin
