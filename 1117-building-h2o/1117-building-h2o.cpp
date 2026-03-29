
// If an oxygen thread arrives at the barrier 
// when no hydrogen threads are present, it must 
// wait for two hydrogen threads.

// If a hydrogen thread arrives at the barrier when no 
// other threads are present, it must wait for an oxygen 
// thread and another hydrogen thread.

// at most two hydro can be on the ground
// we can track the state of hydro
// also track the state of oxygen

#include <semaphore.h>
#include <mutex>

class H2O {
private:
    sem_t sem_h;
    sem_t sem_o;

    atomic<int> cnt = 0;
    mutex mtx;

public:

    H2O() {
        // sem, pshared, init_value
        sem_init(&sem_h, 0, 2);
        sem_init(&sem_o, 0, 1);
    }

    void hydrogen(function<void()> releaseHydrogen) {

        sem_wait(&sem_h);

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        checkWater();
    }

    void oxygen(function<void()> releaseOxygen) {

        sem_wait(&sem_o);
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        checkWater();
    }

    // 「加一」和「檢查是否變成 3」要是同一段不可分割的動作
    void checkWater() {
        // LOCK guard is enough, we don't need to unlock in the middle
        lock_guard<mutex> guard(mtx);
        cnt++;
        if (cnt == 3) {
            sem_post(&sem_h);
            sem_post(&sem_h);
            sem_post(&sem_o);
            cnt = 0;
        }

    }

};
