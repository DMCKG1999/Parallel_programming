//
// Created by Dima on 23.05.2020.
//

#ifndef PP_PROJECT_SPINLOCK_H
#define PP_PROJECT_SPINLOCK_H


#include <atomic>

# define cpu_relax() asm volatile ("pause" ::: "memory");

class spinlock {

    std::atomic_flag spin;

public:
    spinlock();
    ~spinlock();


    void lock();
    void unlock();
};


#endif //PP_PROJECT_SPINLOCK_H
