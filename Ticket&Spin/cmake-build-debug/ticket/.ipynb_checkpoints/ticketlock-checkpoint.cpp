//
// Created by Dima on 23.05.2020.
//

#include <cstdio>
#include "ticketlock.h"

void ticketlock::lock() {
    const auto ticket = nexttic.fetch_add(1, std::memory_order_relaxed);

    int backoff_t = BACKOFF_BASE;

    while (true)
    {
        const auto servtic_c = servtic.load(std::memory_order_acquire);
        if (servtic_c == ticket)
            break;

        for (auto i=0; i<backoff_t; i++)
            cpu_relax();

        backoff_t *= BACKOFF_BASE;
    }
}

void ticketlock::unlock() {
    const auto servtic_c = servtic.load(std::memory_order_relaxed) + 1;
    servtic.store(servtic_c, std::memory_order_release);
}
