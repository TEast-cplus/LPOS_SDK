/**
 * @file sdk_client.h
 * @brief Primary HTWOS Native SDK client entry
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
#ifndef HTWOS_SDK_CLIENT_H
#define HTWOS_SDK_CLIENT_H

#include "htwos/capability.h"
#include "htwos/common/status.h"
#include "htwos/common/version.h"
#include "htwos/ipc/event_bus.h"
#include "htwos/ipc/shm_channel.h"
#include "htwos/ipc/uds_client.h"

#include <string>

namespace Hantewin {
namespace Htwos {

/**
 * @brief SdkClient connect options
 * @date 2026-11-24
 * @author HTW_DEV
 */
typedef struct {
    std::string uds_path; // control plane socket path
} SdkClientOptions_T;

/**
 * @class SdkClient
 * @brief Application-facing client for capability and IPC access
 * @date 2026-11-24
 * @author HTW_DEV
 */
class SdkClient {
public:
    SdkClient();
    ~SdkClient();

    Status connect(const SdkClientOptions_T& options);
    Status disconnect();
    bool isConnected() const;

    SdkVersion_T version() const;
    Status queryCapability(PlatformCapability_T& capability);

    Ipc::UdsClient& udsClient();
    Ipc::EventBus& eventBus();
    Ipc::ShmChannel& shmChannel();

private:
    bool m_connected;                 // connection state
    SdkClientOptions_T m_options;     // connect options
    Ipc::UdsClient m_uds_client;      // command channel
    Ipc::EventBus m_event_bus;        // async events
    Ipc::ShmChannel m_shm_channel;    // data plane
};

} // namespace Htwos
} // namespace Hantewin

#endif /* HTWOS_SDK_CLIENT_H */
