//
// Created by Dima on 23.05.2020.
//

#include <cstdio>
#include "ticketlock.h"

#define BACKOFF_BASE 5

void ticketlock::lock() {
    const auto ticket = nexttic.fetch_add(1, std::memory_order_relaxed);
    while (true)
    {
        const auto servtic_c = servtic.load(std::memory_order_acquire);
        if (servtic_c == ticket)
            break;

        const size_t numBeforeMe = ticket-servtic_c;
        const size_t waitIters = BACKOFF_BASE*numBeforeMe;

        for (size_t i=0; i<waitIters; i++)
            cpu_relax();
    }
}

void ticketlock::unlock() {
    const auto servtic_c = servtic.load(std::memory_order_relaxed) + 1;
    servtic.store(servtic_c, std::memory_order_release);
}
