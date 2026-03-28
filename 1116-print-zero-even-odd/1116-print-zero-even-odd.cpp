#include <mutex>
#include <condition_variable>

#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int curr = 1;      // 下一個要印的數字
    int turn = 0;      // 0: zero, 1: odd, 2: even

    mutex mtx;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() { return turn == 0; });

            printNumber(0);

            if (curr % 2 == 1) {
                turn = 1;   // 輪到 odd
            } else {
                turn = 2;   // 輪到 even
            }

            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() { return turn == 2; });

            printNumber(curr);
            curr++;
            turn = 0;   // 輪回 zero

            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [&]() { return turn == 1; });

            printNumber(curr);
            curr++;
            turn = 0;   // 輪回 zero

            cv.notify_all();
        }
    }
};


// Semaphore
// #include <semaphore.h>
// class ZeroEvenOdd {
// private:
//     int n;
//     sem_t sem_z;
//     sem_t sem_o;
//     sem_t sem_e;

// public:
//     ZeroEvenOdd(int n) {
//         this->n = n;
//         sem_init(&sem_z, 0 ,1);
//         sem_init(&sem_o, 0 ,0);
//         sem_init(&sem_e, 0 ,0);
//     }

//     // printNumber(x) outputs "x", where x is an integer.
//     void zero(function<void(int)> printNumber) {
//         for (int i = 1; i <= n; i++) {
//             sem_wait(&sem_z);
//             printNumber(0);
//             if (i%2 == 0)
//                 sem_post(&sem_e);
//             else
//                 sem_post(&sem_o);
//         }
//     }

//     void even(function<void(int)> printNumber) {
//         for (int i = 2; i <= n; i+= 2) {
//             sem_wait(&sem_e);
//             printNumber(i);
//             sem_post(&sem_z);
//         }
//     }

//     void odd(function<void(int)> printNumber) {
//         for (int i = 1; i <= n; i+= 2) {
//             sem_wait(&sem_o);
//             printNumber(i);
//             sem_post(&sem_z);
//         }
//     }
// };

