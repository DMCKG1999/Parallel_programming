//
// Created by Dima on 23.05.2020.
//

#include <assert.h>
#include "spinlock.h"

spinlock_TTAS::spinlock_TTAS() : spin (0) { }

spinlock_TTAS::~spinlock_TTAS() {
    assert(spin.load(std::memory_order_acquire) == 0);
}

void spinlock_TTAS::lock() {
    int expected = 0;
    do {
        std::this_thread::yield();
    }
    while (!spin.compare_exchange_weak(expected, 1)) ;
}

void spinlock_TTAS::unlock() {
    spin.store(0, std::memory_order_release);
}
