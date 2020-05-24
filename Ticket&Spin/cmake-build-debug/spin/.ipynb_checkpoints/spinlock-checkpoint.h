//
// Created by Dima on 23.05.2020.
//

#ifndef TICKET_SPIN_SPINLOCK_H
#define TICKET_SPIN_SPINLOCK_H

#include <atomic>
#include "../asm.h"

class spinlock_TTAS {

    std::atomic<int> spin;

public:
    spinlock_TTAS();
    ~spinlock_TTAS();


    void lock();
    void unlock();

};


#endif //TICKET_SPIN_SPINLOCK_H
