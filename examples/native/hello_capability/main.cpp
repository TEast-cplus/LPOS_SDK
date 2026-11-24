/**
 * @file main.cpp
 * @brief Minimal Native SDK example: version + capability query
 * @author HTW_DEV
 * @date 2026-11-24
 * @version 2026-11-24_v1.0
 *
 * Copyright (c) 2026 Hantewin. All rights reserved.
 *
 * modify history:
 * | Date       | Author  | Notes              |
 * |------------|---------|--------------------|
 * | 2026-11-24 | HTW_DEV | Initial example    |
 */
#include "htwos/sdk_client.h"

#include <iostream>

int main()
{
    Hantewin::Htwos::SdkClient client;
    Hantewin::Htwos::SdkClientOptions_T options;

    options.uds_path = "/tmp/htwosd.sock";

    Hantewin::Htwos::Status connect_status = client.connect(options);
    std::cout << "sdk version: "
              << Hantewin::Htwos::sdkVersionString() << "\n";
    std::cout << "connect: code="
              << static_cast<int>(connect_status.code())
              << " msg=" << connect_status.message() << "\n";

    Hantewin::Htwos::PlatformCapability_T capability;
    Hantewin::Htwos::Status query_status =
        client.queryCapability(capability);
    if (false == query_status.ok()) {
        std::cerr << "queryCapability failed: "
                  << query_status.message() << "\n";
        return 1;
    }

    std::cout << "platform_id: " << capability.platform_id << "\n";
    std::cout << "soc: " << capability.soc << "\n";
    std::cout << "camera.supported: "
              << (capability.camera.supported ? "true" : "false")
              << " max_streams=" << capability.camera.max_streams
              << "\n";
    std::cout << "npu.backend: " << capability.npu.backend << "\n";
    std::cout << "realtime.external_mcu: "
              << (capability.realtime.external_mcu ? "true" : "false")
              << "\n";

    (void)client.disconnect();
    return 0;
}
