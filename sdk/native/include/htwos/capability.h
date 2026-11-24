/**
 * @file capability.h
 * @brief Device capability descriptors queried by applications
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
#ifndef HTWOS_CAPABILITY_H
#define HTWOS_CAPABILITY_H

#include <cstdint>
#include <string>
#include <vector>

namespace Hantewin {
namespace Htwos {

/**
 * @brief Camera capability summary
 * @date 2026-11-24
 * @author HTW_DEV
 */
typedef struct {
    bool supported;           // whether camera is available
    std::uint32_t max_streams; // max concurrent streams
} CameraCapability_T;

/**
 * @brief IMU capability summary
 * @date 2026-11-24
 * @author HTW_DEV
 */
typedef struct {
    bool supported;                     // whether imu is available
    std::vector<std::string> interfaces; // i2c / spi / ...
} ImuCapability_T;

/**
 * @brief Motor capability summary
 * @date 2026-11-24
 * @author HTW_DEV
 */
typedef struct {
    bool supported;                      // whether motor is available
    std::vector<std::string> interfaces; // can / ...
} MotorCapability_T;

/**
 * @brief NPU capability summary
 * @date 2026-11-24
 * @author HTW_DEV
 */
typedef struct {
    bool supported;      // whether npu is available
    std::string backend; // rknn / tensorrt / ...
} NpuCapability_T;

/**
 * @brief Realtime domain capability summary
 * @date 2026-11-24
 * @author HTW_DEV
 */
typedef struct {
    bool linux_rt;      // linux RT kernel available
    bool external_mcu;  // companion MCU present
} RealtimeCapability_T;

/**
 * @brief Aggregated platform capability matrix view
 * @date 2026-11-24
 * @author HTW_DEV
 */
typedef struct {
    std::string platform_id; // logical platform id
    std::string soc;         // soc name
    CameraCapability_T camera;
    ImuCapability_T imu;
    MotorCapability_T motor;
    NpuCapability_T npu;
    RealtimeCapability_T realtime;
} PlatformCapability_T;

/**
 * @brief Stub capability matrix used before Edge OS IPC is wired
 * @date 2026-11-24
 * @author HTW_DEV
 */
PlatformCapability_T stubDefaultCapability();

} // namespace Htwos
} // namespace Hantewin

#endif /* HTWOS_CAPABILITY_H */
