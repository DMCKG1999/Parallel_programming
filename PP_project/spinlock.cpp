//
// Created by Dima on 23.05.2020.
//

#include <assert.h>
#include "spinlock.h"


spinlock::spinlock() {
    std::atomic_flag spin = ATOMIC_FLAG_INIT;
}

spinlock::~spinlock() {
    assert(spin.test_and_set(std::memory_order_acquire));
}

void spinlock::lock() {
    do {
        cpu_relax();
    } while (spin.test_and_set(std::memory_order_acquire)) ;
}

void spinlock::unlock() {
    spin.clear(std::memory_order_release);
}
