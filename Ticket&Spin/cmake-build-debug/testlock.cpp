#pragma once

#include <chrono>
#include <ratio>
#include <thread>
#include <vector>
#include <functional>

template <class T> std::chrono::duration<double, std::milli> TestLock (T* lock, int NUM_THREADS, std::function<void(T*)> func);

template <class T> std::chrono::duration<double, std::milli> TestLock(T* lock, int NUM_THREADS, std::function<void(T*)> func) {
    auto start_t = std::chrono::high_resolution_clock::now();

    std::vector<std::thread> threads;

    for (auto i = 0; i < NUM_THREADS; i++) {
        threads.push_back(std::thread(func, lock));
    }    
 
    for (std::thread & th : threads) {
            if (th.joinable()) { th.join(); }
    }

    return std::chrono::high_resolution_clock::now()-start_t;
}
    