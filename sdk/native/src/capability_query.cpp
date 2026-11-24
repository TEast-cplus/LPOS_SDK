/**
 * @file capability_query.cpp
 * @brief Default / stub capability matrix helpers
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
#include "htwos/capability.h"

namespace Hantewin {
namespace Htwos {

namespace {

PlatformCapability_T makeStubRk3588Capability()
{
    PlatformCapability_T capability = {};

    capability.platform_id = "rk3588_robot";
    capability.soc = "rk3588";

    capability.camera.supported = true;
    capability.camera.max_streams = 2;

    capability.imu.supported = true;
    capability.imu.interfaces.push_back("i2c");
    capability.imu.interfaces.push_back("spi");

    capability.motor.supported = true;
    capability.motor.interfaces.push_back("can");

    capability.npu.supported = true;
    capability.npu.backend = "rknn";

    capability.realtime.linux_rt = false;
    capability.realtime.external_mcu = true;
    return capability;
}

} // namespace

PlatformCapability_T stubDefaultCapability()
{
    return makeStubRk3588Capability();
}

} // namespace Htwos
} // namespace Hantewin
