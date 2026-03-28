#include <mutex>
#include <condition_variable>

// class ZeroEvenOdd {
// private:
//     int n;

//     // we need to have a current number to print number
//     // some thread will call zero call even call odd
//     // should keep waiting
//     int currNum = 0;

//     // zero -> wake odd -> wake zero -> wake even -> wake zero

//     mutex mtx;
//     condition_variable cvOdd;
//     condition_variable cvEven;


// public:
//     ZeroEvenOdd(int n) {
//         this->n = n;
//     }

//     // printNumber(x) outputs "x", where x is an integer.
//     void zero(function<void(int)> printNumber) {

//         {
//             std::lock_guard<std::mutex> lock(mtx);
//             printNumber(currNum);
//             currNum++;
//         }

//         if (currNum % 2 == 0) {
//             // wake odd
//             cvEven.notify_one();
//         } else {
//             cvOdd.notify_one();
//         }

//     }

//     void even(function<void(int)> printNumber) {

//         std::unique_lock<std::mutex> lock(mtx);

//         cvEven.wait(lock, []{ });

//         printNumber(currNum);

        
//     }

//     void odd(function<void(int)> printNumber) {

//         std::unique_lock<std::mutex> lock(mtx);

//         cvOdd.wait(lock, []{ });

//         printNumber(currNum);

//     }
// };


// Semaphore
#include <semaphore.h>
class ZeroEvenOdd {
private:
    int n;
    sem_t sem_z;
    sem_t sem_o;
    sem_t sem_e;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&sem_z, 0 ,1);
        sem_init(&sem_o, 0 ,0);
        sem_init(&sem_e, 0 ,0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            sem_wait(&sem_z);
            printNumber(0);
            if (i%2 == 0)
                sem_post(&sem_e);
            else
                sem_post(&sem_o);
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i+= 2) {
            sem_wait(&sem_e);
            printNumber(i);
            sem_post(&sem_z);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i+= 2) {
            sem_wait(&sem_o);
            printNumber(i);
            sem_post(&sem_z);
        }
    }
};

