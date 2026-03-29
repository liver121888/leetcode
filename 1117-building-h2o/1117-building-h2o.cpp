
// If an oxygen thread arrives at the barrier 
// when no hydrogen threads are present, it must 
// wait for two hydrogen threads.

// If a hydrogen thread arrives at the barrier when no 
// other threads are present, it must wait for an oxygen 
// thread and another hydrogen thread.

// at most two hydro can be on the ground
// we can track the state of hydro
// also track the state of oxygen

// 這板式錯的因為它直接先print並沒有create barrier一起print

// #include <semaphore.h>
// #include <mutex>

// class H2O {
// private:
//     sem_t sem_h;
//     sem_t sem_o;

//     atomic<int> cnt = 0;
//     mutex mtx;

// public:

//     H2O() {
//         // sem, pshared, init_value
//         sem_init(&sem_h, 0, 2);
//         sem_init(&sem_o, 0, 1);
//     }

//     void hydrogen(function<void()> releaseHydrogen) {

//         sem_wait(&sem_h);

//         // releaseHydrogen() outputs "H". Do not change or remove this line.
//         releaseHydrogen();

//         checkWater();
//     }

//     void oxygen(function<void()> releaseOxygen) {

//         sem_wait(&sem_o);
        
//         // releaseOxygen() outputs "O". Do not change or remove this line.
//         releaseOxygen();

//         checkWater();
//     }

//     // 「加一」和「檢查是否變成 3」要是同一段不可分割的動作
//     void checkWater() {
//         // LOCK guard is enough, we don't need to unlock in the middle
//         // lock_guard<mutex>(mtx); 原本寫成這樣
//         // 這樣其實是創造匿名物件with scope只有在這行
//         // 所以這樣寫完全沒有鎖到
//         lock_guard<mutex> guard(mtx);
//         cnt++;
//         if (cnt == 3) {
//             sem_post(&sem_h);
//             sem_post(&sem_h);
//             sem_post(&sem_o);
//             cnt = 0;
//         }

//     }

// };

// 我先把重點講清楚：你前一版能過，是因為它保證了 每輪最多 2H + 1O；
// 但「真正的 barrier」還要求 這 3 個 thread 都到齊後，
// 大家才能一起往下走。我會先講差別，再給你一版比較標準、好記的 C++ 解法。
#include <semaphore.h>
#include <mutex>
#include <functional>
using namespace std;

class H2O {
private:
    sem_t hSlots;    // 每輪最多 2 個 hydrogen
    sem_t oSlots;    // 每輪最多 1 個 oxygen
    sem_t barrier;   // 湊滿 3 個後，一次放行 3 個

    mutex mtx;
    int arrived;     // 這一輪已經到 barrier 的人數
    int printed;     // 這一輪已經輸出的人數

public:
    H2O() : arrived(0), printed(0) {
        sem_init(&hSlots, 0, 2);
        sem_init(&oSlots, 0, 1);
        sem_init(&barrier, 0, 0);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        // 先拿這一輪的 H 名額
        sem_wait(&hSlots);

        bool isLastArrive = false;
        {
            lock_guard<mutex> lock(mtx);
            arrived++;
            if (arrived == 3) {
                isLastArrive = true;
            }
        }

        // 第三個到的人，打開 barrier，放行這 3 個人
        if (isLastArrive) {
            sem_post(&barrier);
            sem_post(&barrier);
            sem_post(&barrier);
        }

        // 沒湊滿 3 個之前，都要等
        sem_wait(&barrier);

        // 真正通過 barrier 後才能輸出
        releaseHydrogen();

        bool isLastPrint = false;
        {
            lock_guard<mutex> lock(mtx);
            printed++;
            if (printed == 3) {
                printed = 0;
                arrived = 0;
                isLastPrint = true;
            }
        }

        // 最後一個印完的人，開啟下一輪 2H + 1O
        if (isLastPrint) {
            sem_post(&hSlots);
            sem_post(&hSlots);
            sem_post(&oSlots);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        // 先拿這一輪的 O 名額
        sem_wait(&oSlots);

        bool isLastArrive = false;
        {
            lock_guard<mutex> lock(mtx);
            arrived++;
            if (arrived == 3) {
                isLastArrive = true;
            }
        }

        // 第三個到的人，打開 barrier
        if (isLastArrive) {
            sem_post(&barrier);
            sem_post(&barrier);
            sem_post(&barrier);
        }

        // 沒湊滿 3 個之前，都要等
        sem_wait(&barrier);

        // 真正通過 barrier 後才能輸出
        releaseOxygen();

        bool isLastPrint = false;
        {
            lock_guard<mutex> lock(mtx);
            printed++;
            if (printed == 3) {
                printed = 0;
                arrived = 0;
                isLastPrint = true;
            }
        }

        // 最後一個印完的人，開啟下一輪
        if (isLastPrint) {
            sem_post(&hSlots);
            sem_post(&hSlots);
            sem_post(&oSlots);
        }
    }
};