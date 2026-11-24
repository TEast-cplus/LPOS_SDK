/**
 * @file sdk_client.cpp
 * @brief HTWOS Native SDK client implementation
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
#include "htwos/sdk_client.h"

namespace Hantewin {
namespace Htwos {

SdkClient::SdkClient()
    : m_connected(false)
    , m_options()
    , m_uds_client()
    , m_event_bus()
    , m_shm_channel()
{
}

SdkClient::~SdkClient()
{
    (void)disconnect();
}

Status SdkClient::connect(const SdkClientOptions_T& options)
{
    if (true == options.uds_path.empty()) {
        return Status::FromCode(HTWOS_ERR_INVALID_ARG);
    }

    Status status = m_uds_client.connect(options.uds_path);
    if ((false == status.ok()) &&
        (HTWOS_ERR_STUB != status.code())) {
        return status;
    }

    m_options = options;
    m_connected = true;
    return Status::Stub("sdk connect uses stubbed ipc");
}

Status SdkClient::disconnect()
{
    (void)m_uds_client.disconnect();
    m_connected = false;
    return Status::Ok();
}

bool SdkClient::isConnected() const
{
    return m_connected;
}

SdkVersion_T SdkClient::version() const
{
    return sdkVersion();
}

Status SdkClient::queryCapability(PlatformCapability_T& capability)
{
    if (false == m_connected) {
        return Status::FromCode(HTWOS_ERR_NOT_CONNECTED);
    }

    capability = stubDefaultCapability();
    return Status::Ok();
}

Ipc::UdsClient& SdkClient::udsClient()
{
    return m_uds_client;
}

Ipc::EventBus& SdkClient::eventBus()
{
    return m_event_bus;
}

Ipc::ShmChannel& SdkClient::shmChannel()
{
    return m_shm_channel;
}

} // namespace Htwos
} // namespace Hantewin
