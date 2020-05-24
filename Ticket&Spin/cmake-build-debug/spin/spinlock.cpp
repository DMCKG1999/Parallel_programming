//
// Created by Dima on 23.05.2020.
//

#include <assert.h>
#include "spinlock.h"

spinlock::spinlock() : spin (0){ }

spinlock::~spinlock() {}

void spinlock::lock() {
    while (spin.test_and_set(std::memory_order_acquire)) ;
}

void spinlock::unlock() {
    spin.clear(std::memory_order_release);
}
