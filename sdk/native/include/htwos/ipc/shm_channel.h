/**
 * @file shm_channel.h
 * @brief Shared memory channel for large media / tensor buffers
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
#ifndef HTWOS_SHM_CHANNEL_H
#define HTWOS_SHM_CHANNEL_H

#include "htwos/common/status.h"

#include <cstddef>
#include <cstdint>
#include <string>

namespace Hantewin {
namespace Htwos {
namespace Ipc {

/**
 * @brief Shared memory mapping descriptor
 * @date 2026-11-24
 * @author HTW_DEV
 */
typedef struct {
    std::string name;    // shm object name
    std::size_t size;    // mapped size in bytes
    void* address;       // mapped address, nullptr when stub
} ShmMapping_T;

/**
 * @class ShmChannel
 * @brief Data-plane transport for image / pointcloud / audio / tensor
 * @date 2026-11-24
 * @author HTW_DEV
 */
class ShmChannel {
public:
    ShmChannel();
    ~ShmChannel();

    Status open(const std::string& name, std::size_t size);
    Status close();
    const ShmMapping_T& mapping() const;

private:
    ShmMapping_T m_mapping; // current mapping
    bool m_opened;          // open flag
};

} // namespace Ipc
} // namespace Htwos
} // namespace Hantewin

#endif /* HTWOS_SHM_CHANNEL_H */
