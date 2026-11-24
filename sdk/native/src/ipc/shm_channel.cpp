/**
 * @file shm_channel.cpp
 * @brief Shared memory channel stub
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
#include "htwos/ipc/shm_channel.h"

namespace Hantewin {
namespace Htwos {
namespace Ipc {

ShmChannel::ShmChannel()
    : m_mapping()
    , m_opened(false)
{
    m_mapping.name = "";
    m_mapping.size = 0;
    m_mapping.address = nullptr;
}

ShmChannel::~ShmChannel()
{
    (void)close();
}

Status ShmChannel::open(const std::string& name, std::size_t size)
{
    if (true == name.empty()) {
        return Status::FromCode(HTWOS_ERR_INVALID_ARG);
    }
    if (0 == size) {
        return Status::FromCode(HTWOS_ERR_INVALID_ARG);
    }

    m_mapping.name = name;
    m_mapping.size = size;
    m_mapping.address = nullptr;
    m_opened = true;
    return Status::Stub("shm open is stubbed");
}

Status ShmChannel::close()
{
    m_mapping.name.clear();
    m_mapping.size = 0;
    m_mapping.address = nullptr;
    m_opened = false;
    return Status::Ok();
}

const ShmMapping_T& ShmChannel::mapping() const
{
    return m_mapping;
}

} // namespace Ipc
} // namespace Htwos
} // namespace Hantewin
