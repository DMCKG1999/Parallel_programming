#include <atomic>
#include <assert.h>

# define cpu_relax() asm volatile ("pause" ::: "memory");

class TTAS_spinlock
{
	std::atomic_flag spin;

public:
	TTAS_spinlock()  { std::atomic_flag spin = ATOMIC_FLAG_INIT; }
	~TTAS_spinlock() { assert(spin.test_and_set(std::memory_order_acquire)); }


	void lock(){
        do {
            cpu_relax();
        } while (spin.test_and_set(std::memory_order_acquire)) ;
    }

	void unlock(){
        spin.clear(std::memory_order_release);
    }
};
