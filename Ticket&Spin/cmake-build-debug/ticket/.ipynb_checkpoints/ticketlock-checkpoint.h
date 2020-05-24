//
// Created by Dima on 23.05.2020.
//

#ifndef TICKET_SPIN_TICKETLOCK_H
#define TICKET_SPIN_TICKETLOCK_H

#include <atomic>
#include "../asm.h"

class ticketlock {
    std::atomic_size_t servtic = {0};
    std::atomic_size_t nexttic = {0};

    const int BACKOFF_BASE = 2;

public:
    void lock();
    void unlock();
};


#endif //TICKET_SPIN_TICKETLOCK_H