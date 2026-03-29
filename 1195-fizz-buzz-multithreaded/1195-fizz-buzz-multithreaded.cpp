
// 1 2 X 4 Y
// X 7 8 X Y
// 11 X 13 14 XY

// 16 17 X 19 Y
// ....

// every time we inc we use cv varialbe to wake all thread
// and each thread will see who can print

#include <iostream>
#include <condition_variable>
#include <mutex>

// class FizzBuzz {
// private:
//     int n;
//     int curr = 1;
//     condition_variable cv;
//     mutex mtx;

// public:

//     FizzBuzz(int n) {
//         this->n = n;
//     }

//     // printFizz() outputs "fizz".
//     void fizz(function<void()> printFizz) {
//         while (true) {
//             unique_lock<mutex> lock(mtx);
//             cv.wait(lock, [this](){
//                 if (curr > n)
//                     return true;
//                 return curr % 3 == 0 && curr % 5 != 0;
//             });
//             if (curr > n)
//                 break;
//             printFizz();
//             curr++;
//             cv.notify_all();
//         }
//         cv.notify_all();
//     }

//     // printBuzz() outputs "buzz".
//     void buzz(function<void()> printBuzz) {
//         while (true) {
//             unique_lock<mutex> lock(mtx);
//             cv.wait(lock, [this](){
//                 if (curr > n)
//                     return true;
//                 return curr % 3 != 0 && curr % 5 == 0;
//             });
//             if (curr > n)
//                 break;
//             printBuzz();
//             curr++;
//             cv.notify_all();
//         }
//         cv.notify_all();
//     }

//     // printFizzBuzz() outputs "fizzbuzz".
// 	void fizzbuzz(function<void()> printFizzBuzz) {
//         while (true) {
//             unique_lock<mutex> lock(mtx);
//             cv.wait(lock, [this](){
//                 if (curr > n)
//                     return true;
//                 return curr != 0 && curr % 3 == 0 && curr % 5 == 0;
//             });
//             if (curr > n)
//                 break;
//             printFizzBuzz();
//             curr++;
//             cv.notify_all();
//         }
//         cv.notify_all();
//     }

//     // printNumber(x) outputs "x", where x is an integer.
//     void number(function<void(int)> printNumber) {

//         while (true) {
//             unique_lock<mutex> lock(mtx);
//             cv.wait(lock, [this](){
//                 // game over should proceed and ends
//                 if (curr > n)
//                     return true;
//                 return curr % 3 != 0 && curr % 5 != 0;
//             });

//             if (curr > n)
//                 break;
//             printNumber(curr);
//             curr++;
//             cv.notify_all();
//         }
//         cv.notify_all();
//     }

// };

// clear version
#include <functional>
#include <condition_variable>
#include <mutex>
using namespace std;

class FizzBuzz {
private:
    int n;
    int curr;
    mutex mtx;
    condition_variable cv;

public:
    FizzBuzz(int n) : n(n), curr(1) {}

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this]() {
                return curr > n || (curr % 3 == 0 && curr % 5 != 0);
            });

            if (curr > n) {
                cv.notify_all();
                return;
            }

            printFizz();
            ++curr;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this]() {
                return curr > n || (curr % 3 != 0 && curr % 5 == 0);
            });

            if (curr > n) {
                cv.notify_all();
                return;
            }

            printBuzz();
            ++curr;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this]() {
                return curr > n || (curr % 3 == 0 && curr % 5 == 0);
            });

            if (curr > n) {
                cv.notify_all();
                return;
            }

            printFizzBuzz();
            ++curr;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this]() {
                return curr > n || (curr % 3 != 0 && curr % 5 != 0);
            });

            if (curr > n) {
                cv.notify_all();
                return;
            }

            printNumber(curr);
            ++curr;
            cv.notify_all();
        }
    }
};
