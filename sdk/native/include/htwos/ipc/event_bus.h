/**
 * @file event_bus.h
 * @brief Asynchronous event bus client for device lifecycle events
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
#ifndef HTWOS_EVENT_BUS_H
#define HTWOS_EVENT_BUS_H

#include "htwos/common/status.h"

#include <functional>
#include <string>

namespace Hantewin {
namespace Htwos {
namespace Ipc {

/**
 * @brief Event payload delivered by the bus
 * @date 2026-11-24
 * @author HTW_DEV
 */
typedef struct {
    std::string topic;   // event topic
    std::string payload; // opaque payload
} EventMessage_T;

typedef std::function<void(const EventMessage_T&)> EventHandler_T;

/**
 * @class EventBus
 * @brief Async notification channel for status / fault / lifecycle
 * @date 2026-11-24
 * @author HTW_DEV
 */
class EventBus {
public:
    EventBus();
    ~EventBus();

    Status subscribe(const std::string& topic,
                     EventHandler_T handler);
    Status unsubscribe(const std::string& topic);
    Status publish(const EventMessage_T& message);

private:
    bool m_active; // stub active flag
};

} // namespace Ipc
} // namespace Htwos
} // namespace Hantewin

#endif /* HTWOS_EVENT_BUS_H */
