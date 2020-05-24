#include "cmake-build-debug/benchmarks.cpp"

#include "cmake-build-debug/spin/spinlock.h"
#include "cmake-build-debug/spin/spinlock.cpp"

#include "cmake-build-debug/ticket/ticketlock.h"
#include "cmake-build-debug/ticket/ticketlock.cpp"


int main() {
    
    std::cout << "# Good day, dear User!" << std::endl;
    
    std::cout << "# Don't forget to copy some lines below:" << std::endl;
    std::cout << "import matplotlib.pyplot as plt" << std::endl;
    std::cout << "import numpy as np" << std::endl << std::endl;
    std::cout << "plt.rcParams['figure.dpi'] = 200" << std::endl;
    std::cout << "plt.xkcd()" << std::endl;
    
    std::cout << std::endl << "# Wait..." << std::endl;
    
    BenchmarkLock<spinlock_TTAS>("spinlock_TTAS", 'r');
    
    std::cout << std::endl << "# Wait..." << std::endl;
    
    BenchmarkLock<ticketlock>("ticketlock with exponential backoff", 'b');
    
    std::cout << "# And last two lines:" << std::endl << std::endl;
    
    std::cout << "plt.ylabel('time, milliseconds')" << std::endl;
    std::cout << "plt.show()" << std::endl << std::endl;
    std::cout << "# Good luck!" << std::endl;
    
    return 0;
}
