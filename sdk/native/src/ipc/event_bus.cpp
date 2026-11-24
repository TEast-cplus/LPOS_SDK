/**
 * @file event_bus.cpp
 * @brief Event bus client stub
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
#include "htwos/ipc/event_bus.h"

namespace Hantewin {
namespace Htwos {
namespace Ipc {

EventBus::EventBus()
    : m_active(false)
{
}

EventBus::~EventBus()
{
}

Status EventBus::subscribe(const std::string& topic,
                           EventHandler_T handler)
{
    if (true == topic.empty()) {
        return Status::FromCode(HTWOS_ERR_INVALID_ARG);
    }
    if (!handler) {
        return Status::FromCode(HTWOS_ERR_INVALID_ARG);
    }

    m_active = true;
    return Status::Stub("event bus subscribe is stubbed");
}

Status EventBus::unsubscribe(const std::string& topic)
{
    if (true == topic.empty()) {
        return Status::FromCode(HTWOS_ERR_INVALID_ARG);
    }

    return Status::Stub("event bus unsubscribe is stubbed");
}

Status EventBus::publish(const EventMessage_T& message)
{
    if (true == message.topic.empty()) {
        return Status::FromCode(HTWOS_ERR_INVALID_ARG);
    }

    (void)m_active;
    return Status::Stub("event bus publish is stubbed");
}

} // namespace Ipc
} // namespace Htwos
} // namespace Hantewin
