#include "cmake-build-debug/benchmarks.cpp"

#include "cmake-build-debug/spin/spinlock.h"
#include "cmake-build-debug/spin/spinlock.cpp"

#include "cmake-build-debug/ticket/ticketlock.h"
#include "cmake-build-debug/ticket/ticketlock.cpp"


int main() {
    
    std::cout << "# Good day, dear user!";
    
    std::cout << std::endl << "# Wait for a second, please." << std::endl;
    
    std::this_thread::sleep_for (std::chrono::seconds(1));
    
    BenchmarkLock<spinlock>("spinlock", 'r');
    
    std::cout << std::endl << "# Wait for a second, please." << std::endl;
    
    std::this_thread::sleep_for (std::chrono::seconds(1));
    
    BenchmarkLock<ticketlock>("ticketlock", 'b');
    
    return 0;
}
