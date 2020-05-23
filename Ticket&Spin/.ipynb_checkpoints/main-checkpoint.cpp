#include "cmake-build-debug/spin/spinlock.h"
#include "cmake-build-debug/spin/spinlock.cpp"
#include "cmake-build-debug/ticket/ticketlock.h"
#include "cmake-build-debug/ticket/ticketlock.cpp"
#include "cmake-build-debug/asm.h"

#include <chrono>
#include <ratio>
#include <vector>
#include <thread>
#include <iostream>
#include <functional>
#include <assert.h>

template <class T>
std::chrono::duration<double, std::milli> TestLock (T* lock, int NUM_THREADS, std::function<void(T*)> func);

template<class T>
std::chrono::duration<double, std::milli> TestLock(T *lock, int NUM_THREADS, std::function<void(T*)> func) {
    auto start_t = std::chrono::high_resolution_clock::now();

    std::vector<std::thread> threads;

    for (auto i = 0; i < NUM_THREADS; i++) {
	threads.push_back(std::thread(func, lock));
    }    
 
    for (std::thread & th : threads) {
        if (th.joinable()) { th.join(); }
    }

    auto finish_t = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff = finish_t-start_t;

    return diff;
}


int main() {

    spinlock Spin;
    std::chrono::duration<double, std::milli> difspin[10];

    for (auto i = 1; i < 10; i++) {
        spinlock Spin;
        difspin[i] = TestLock<spinlock>(&Spin, i, [](spinlock *lock) {
                        lock->lock();
                        
                        int a = 1;
                        int b = 3;
                        int c = a + b;
                        a = c + b;
             
                        lock->unlock();
                        });
    }
    
    for (auto i = 1; i < 10; i++)
        std::cout << difspin[i].count() << std::endl;

    return 0;
}
