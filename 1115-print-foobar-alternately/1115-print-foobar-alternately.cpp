#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool fooTurn = true; // Flag to track which function should execute next

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            
            // Wait until it's foo's turn
            cv.wait(lock, [this]() { return fooTurn; });

            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();

            // Set flag to false and notify the bar thread
            fooTurn = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);

            // Wait until it's bar's turn (fooTurn is false)
            cv.wait(lock, [this]() { return !fooTurn; });

            // printBar() outputs "bar". Do not change or remove this line.
            printBar();

            // Set flag back to true and notify the foo thread
            fooTurn = true;
            cv.notify_one();
        }
    }
};