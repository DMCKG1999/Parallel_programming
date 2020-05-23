#include <iostream>

#include "cmake-build-debug/spin/spinlock.h"
#include "cmake-build-debug/ticket/ticketlock.h"

#include <chrono>
#include <ratio>
#include <vector>
#include <pthread.h>
#include <assert.h>

void *new_thread (void *arg)
{
    int a = 1;
    int b = 3;
    int c = a + b;
    return arg;
}

template <class T>
std::chrono::duration<double, std::milli> TestLock (T* lock, int NUM_THREADS);

template<class T>
std::chrono::duration<double, std::milli> TestLock(T *lock, int NUM_THREADS) {
    auto start_t = std::chrono::high_resolution_clock::now();

    pthread_t threads[NUM_THREADS];

    for (auto i = 0; i < NUM_THREADS; i++) {
        bool result_code = pthread_create(&threads[i], nullptr, new_thread, nullptr);
        assert(!result_code);
    }

    for (auto i = 0; i < NUM_THREADS; i++) {
        bool result_code = pthread_join(threads[i], nullptr);
        assert(!result_code);
    }

    pthread_exit(NULL);

    auto finish_t = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> diff = finish_t-start_t;

    return diff;
}


int main() {

    spinlock* Spin = new spinlock();
    std::chrono::duration<double, std::milli> difspin[10];

    for (auto i = 1; i < 10; i++) {
         difspin[i] = TestLock<spinlock>(Spin, i);
    }

    return 0;
}
