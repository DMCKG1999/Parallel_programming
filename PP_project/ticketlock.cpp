//
// Created by Dima on 23.05.2020.
//

#include "ticketlock.h"

void ticketlock::lock() {
    const auto ticket = nexttic.fetch_add(1, std::memory_order_relaxed);
    while (servtic.load(std::memory_order_acquire) != ticket);
}

void ticketlock::unlock() {
    const auto newservtic = servtic.load(std::memory_order_relaxed) + 1;
    servtic.store(newservtic, std::memory_order_release);
}
