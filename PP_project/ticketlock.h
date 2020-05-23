//
// Created by Dima on 23.05.2020.
//

#ifndef PP_PROJECT_TICKETLOCK_H
#define PP_PROJECT_TICKETLOCK_H


#include <atomic>

class ticketlock {
    std::atomic_size_t servtic = {0};
    std::atomic_size_t nexttic = {0};

public:
    void lock();
    void unlock();
};


#endif //PP_PROJECT_TICKETLOCK_H
