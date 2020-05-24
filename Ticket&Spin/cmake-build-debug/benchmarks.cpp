#pragma once

#include "testlock.cpp"

#include <vector>
#include <string>
#include <iostream>

const int MAX_NUMBER_THREAD = 60;

template <class T> void BenchmarkLock (const std::string name, const char c);

template <class T> void BenchmarkLock (const std::string name, const char c) {
    std::chrono::duration<double, std::milli> difspin[MAX_NUMBER_THREAD];

    for (auto i = 1; i < MAX_NUMBER_THREAD; i++) {
        T lock;
        difspin[i] = TestLock<T>(&lock, i, [](T* lock) {
                        lock->lock();
                        
                        int a = 1;
                        int b = 3;
                        int c = a + b;
                        a = c + b;
             
                        lock->unlock();
                        });
    }
    
    std::cout << "plt.plot([";
   
    for (auto i = 1; i < MAX_NUMBER_THREAD; i++) {
        std::cout << i; 
        if (i != MAX_NUMBER_THREAD-1) {
            std::cout << ", ";
        
            if (i % 7 == 0) {
                std::cout << std::endl << "         ";
            }
        }    
    }
         
    std::cout << "], ";
             
    std::cout << "["; 
    
    for (auto i = 1; i < MAX_NUMBER_THREAD; i++) {
        std::cout << difspin[i].count(); 
        if (i != MAX_NUMBER_THREAD-1) {
            std::cout << ", ";
        
            if (i % 7 == 0) {
                std::cout << std::endl << "         ";
            }
        }    
    }
        
    std::cout << "], '" << c << "')" << " # " << name << std::endl;
}